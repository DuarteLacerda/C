/**
 * @file main.c
 * @brief Programa que lê o conteúdo de um ficheiro e converte para maiúsculas ou minúsculas consoante a opção fornecida pelo utilizador.
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
    if (argc < 2 || strcmp(argv[1], "--filename") != 0)
    {
        fprintf(stderr, "Usage: %s --filename <file_name> [--options L/l | U/u]\n", argv[0]);
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
    // substitui maiuscula por minuscula e vice-versa dependo do que o utilizador meter nas opções (--options L/l ou U/u)
    if (argc > 3 && strcmp(argv[3], "--option") == 0)
    {
        if (argc < 5)
        {
            fprintf(stderr, "[ERROR] Option requires an argument.\n");
            close(fd);
            return 1;
        }
        char option = argv[4][0];
        for (ssize_t i = 0; i < bytesRead; i++)
        {
            if (option == 'L' || option == 'l')
            {
                buffer[i] = tolower(buffer[i]);
            }
            else if (option == 'U' || option == 'u')
            {
                buffer[i] = toupper(buffer[i]);
            }
            else
            {
                fprintf(stderr, "[ERROR] Invalid option '%c'. Use 'L/l' for lowercase or 'U/u' for uppercase.\n", option);
                close(fd);
                return 1;
            }
        }
    }
    // Imprimir o conteúdo do ficheiro
    printf("Content:\n%s", buffer);
    // Fechar o ficheiro
    if (close(fd) < 0)
    {
        fprintf(stderr, "[ERROR] Cannot close input file '%s': %s\n", filename, strerror(errno));
        return 1;
    }
    // Return success
    printf("\n");
    return 0;
}
