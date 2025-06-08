/**
 * @file main.c
 * @brief Lê um ficheiro de texto, substitui espaços por underscores em cada linha e escreve apenas as linhas modificadas num novo ficheiro de saída.
 * @date 2025-06-08
 * @author Duarte Lacerda
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h> // For open, read, close

#include "debug.h"
#include "memory.h"

int main(int argc, char *argv[])
{
    /* Disable warnings */
    (void)argc;
    (void)argv;

    // abrir ficheiro dado pelo utilizador --filenmame a.txt
    if (argc < 2 || strcmp(argv[1], "--file") != 0)
    {
        fprintf(stderr, "Usage: %s --file <file_name>\n", argv[0]);
        return 1;
    }
    const char *file = argv[2];
    int fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "[ERROR] Cannot open input file '%s': %s\n", file, strerror(errno));
        return 1;
    }
    // ler ficheiro
    char buffer[1024]; // Buffer to hold file content
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0)
    {
        fprintf(stderr, "[ERROR] Cannot read input file '%s': %s\n", file, strerror(errno));
        close(fd);
        return 1;
    }
    buffer[bytesRead] = '\0'; // Null-terminate the string
    // Verifica se o ficheiro tem conteudo
    if (bytesRead == 0)
    {
        fprintf(stderr, "[ERROR] Input file '%s' is empty.\n", file);
        close(fd);
        return 1;
    }

    // substitui espaços por _
    for (ssize_t i = 0; i < bytesRead; i++)
    {
        if (buffer[i] == ' ')
        {
            buffer[i] = '_';
        }
    }

    // Gerar o nome do ficheiro de saída concatenando ".out" ao nome original
    char output_filename[1024];
    snprintf(output_filename, sizeof(output_filename), "%s.out", file);

    // Escrever apenas as linhas modificadas no ficheiro de saída
    int out_fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0)
    {
        fprintf(stderr, "[ERROR] Cannot open output file '%s': %s\n", output_filename, strerror(errno));
        close(fd);
        return 1;
    }

    int modified_lines = 0;
    char *line_start = buffer;
    char *ptr = buffer;
    while (*ptr)
    {
        if (*ptr == '\n' || *(ptr + 1) == '\0')
        {
            size_t len = ptr - line_start + ((*ptr == '\n') ? 1 : 0);
            int modified = 0;
            for (char *c = line_start; c < line_start + len; c++)
            {
                if (*c == '_')
                {
                    modified = 1;
                    break;
                }
            }
            if (modified)
            {
                size_t total_written = 0;
                while (total_written < len)
                {
                    ssize_t written = write(out_fd, line_start + total_written, len - total_written);
                    if (written < 0)
                    {
                        fprintf(stderr, "[ERROR] Cannot write to output file '%s': %s\n", output_filename, strerror(errno));
                        close(fd);
                        close(out_fd);
                        return 1;
                    }
                    total_written += (size_t)written;
                }
                modified_lines++;
            }
            line_start = ptr + 1;
        }
        ptr++;
    }
    close(fd);

    // Fechar o ficheiro de saída
    if (close(out_fd) < 0)
    {
        fprintf(stderr, "[ERROR] Cannot close output file '%s': %s\n", output_filename, strerror(errno));
        close(fd);
        return 1;
    }

    // Print the modified content
    printf("Modified content:\n%s\n", buffer);
    return 0;
}
