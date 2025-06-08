/**
 * @file main.c
 * @brief Programa que lê um ficheiro de texto, converte todas as letras minúsculas para maiúsculas e guarda o resultado num novo ficheiro.
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
#include <ctype.h> // For tolower, toupper

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
        fprintf(stderr, "Usage: %s --file <file>\n", argv[0]);
        return 1;
    }
    const char *filename = argv[2];
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "[ERROR] Cannot open input file '%s': %s\n", filename, strerror(errno));
        return 1;
    }
    // ler ficheiro
    char buffer[1024]; // Buffer to hold file content
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0)
    {
        fprintf(stderr, "[ERROR] Cannot read input file '%s': %s\n", filename, strerror(errno));
        close(fd);
        return 1;
    }
    buffer[bytesRead] = '\0'; // Null-terminate the string

    // Verifica se o ficheiro tem conteudo
    if (bytesRead == 0)
    {
        fprintf(stderr, "[ERROR] Input file '%s' is empty.\n", filename);
        close(fd);
        return 1;
    }

    // Converter todas as letras minúsculas para maiúsculas
    printf("Converted content:\n");
    for (ssize_t i = 0; i < bytesRead; i++)
    {
        char c = buffer[i];
        if (islower(c))
        {
            // Converte para maiúscula
            c = toupper(c);
        }
        putchar(c); // Imprime o caractere convertido
    }
    printf("\n");

    // Guardar o conteúdo convertido num novo ficheiro
    const char *output_filename = "output.txt";
    int out_fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0)
    {
        fprintf(stderr, "[ERROR] Cannot open output file '%s': %s\n", output_filename, strerror(errno));
        if (close(fd) < 0)
        {
            fprintf(stderr, "[ERROR] Cannot close input file '%s': %s\n", filename, strerror(errno));
            return 1;
        }
        return 1;
    }
    // Escrever o conteúdo convertido no ficheiro de saída
    for (ssize_t i = 0; i < bytesRead; i++)
    {
        char c = buffer[i];
        if (islower(c))
        {
            c = toupper(c);
        }
        if (write(out_fd, &c, 1) != 1)
        {
            fprintf(stderr, "[ERROR] Cannot write to output file '%s': %s\n", output_filename, strerror(errno));
            close(out_fd);
            close(fd);
            return 1;
        }
    }

    printf("\nConverted content saved to '%s'.\n", output_filename);

    // Fechar o ficheiro de saída
    if (close(out_fd) < 0)
    {
        fprintf(stderr, "[ERROR] Cannot close output file '%s': %s\n", output_filename, strerror(errno));
        close(fd);
        return 1;
    }

    // Return success
    printf("\n");
    return 0;
}
