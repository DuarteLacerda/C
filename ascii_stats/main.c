/**
 * @file main.c
 * @brief Programa que lê um ficheiro e conta o número de bytes ASCII, dígitos, letras e outros caracteres.
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
#include <ctype.h>

#include "debug.h"
#include "memory.h"

void print_help(const char *prog_name)
{
    printf("Usage: %s <option> <file_name>\n", prog_name);
    printf("Options:\n");
    printf("  -f | --file        Abrir ficheiro\n");
    printf("  -h | --help        Mostrar ajuda\n");
    printf("  -V | --version     Mostrar versão\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Erro: Argumentos insuficientes.\n");
        print_help(argv[0]);
        return 0;
    }

    // Corrigido: strcmp retorna 0 se strings forem iguais
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        print_help(argv[0]);
        return 0;
    }

    if (strcmp(argv[1], "-V") == 0 || strcmp(argv[1], "--version") == 0)
    {
        printf("Versão: 1.0\n");
        printf("Autor: Duarte Lacerda\n");
        return 0;
    }

    // Corrigido: condição correta para aceitar apenas -f ou --file
    if (argc < 3 || (strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "--file") != 0))
    {
        printf("Erro: Argumentos insuficientes ou inválidos.\n");
        print_help(argv[0]);
        return 0;
    }

    const char *file = argv[2];
    int fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        ERROR(1, "O ficheiro '%s' não existe", file);
    }

    char buffer[1024];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0)
    {
        ERROR(1, "Problemas ao ler o ficheiro '%s'", file);
    }
    if (bytesRead == 0)
    {
        ERROR(1, "O ficheiro '%s' está vazio", file);
    }

    buffer[bytesRead] = '\0';

    int digit = 0, alpha = 0, other = 0;
    for (ssize_t i = 0; i < bytesRead; i++)
    {
        if (isdigit((unsigned char)buffer[i]))
            digit++;
        else if (isalpha((unsigned char)buffer[i]))
            alpha++;
        else
            other++;
    }

    if (close(fd) < 0)
    {
        ERROR(1, "O ficheiro '%s' não pôde ser fechado", file);
    }

    int cAscii = alpha + digit;

    printf("O ficheiro '%s' tem:\n", file);
    printf("    - '%ld' bytes no total, dos quais:\n", bytesRead);
    printf("        - '%d' bytes não ASCII\n", other);
    printf("        - '%d' bytes caracteres ASCII, dos quais:\n", cAscii);
    printf("            - '%d' dígitos (0-9)\n", digit);
    printf("            - '%d' letras (A-Z, a-z)\n", alpha);
    printf("            - '%d' outros caracteres ASCII\n", other);

    return 0;
}