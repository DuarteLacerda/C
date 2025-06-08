/**
 * @file main.c
 * @brief Programa que lê um ficheiro de texto, conta espaços, tabulações e quebras de linha, e converte o conteúdo para um novo ficheiro substituindo espaços por '_', tabulações por '-' e quebras de linha por espaço.
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

    // Contar espaços, tabulações e quebras de linha
    int spaceCount = 0;
    int tabCount = 0;
    int newlineCount = 0;
    for (ssize_t i = 0; i < bytesRead; i++)
    {
        char c = buffer[i];
        if (c == ' ')
        {
            spaceCount++;
        }
        else if (c == '\t')
        {
            tabCount++;
        }
        else if (c == '\n')
        {
            newlineCount++;
        }
    }
    // Imprimir os resultados
    printf("Total de espaços: %d\n", spaceCount);
    printf("Total de tabulações: %d\n", tabCount);
    printf("Total de quebras de linha: %d\n", newlineCount);

    // Verifica se o ficheiro tem mais de 256 linhas ou 1024 caracteres por linha
    if (newlineCount > 256)
    {
        fprintf(stderr, "[ERROR] Input file '%s' has more than 256 lines.\n", filename);
        close(fd);
        return 1;
    }
    if (bytesRead > 256 * 1024)
    {
        fprintf(stderr, "[ERROR] Input file '%s' has more than 256 lines of 1024 characters each.\n", filename);
        close(fd);
        return 1;
    }

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
        if (c == ' ')
        {
            c = '_'; // Convert space to underscore
        }
        else if (c == '\t')
        {
            c = '-'; // Convert tab to hyphen
        }
        else if (c == '\n')
        {
            c = ' '; // Convert newline to space
        }
        if (write(out_fd, &c, 1) < 0)
        {
            fprintf(stderr, "[ERROR] Cannot write to output file '%s': %s\n", output_filename, strerror(errno));
            close(fd);
            close(out_fd);
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
