/**
 * @file main.c
 * @brief Programa que lê um ficheiro e conta o número de linhas, imprimindo cada linha com o seu número.
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

int main(int argc, char *argv[]) {
    /* Disable warnings */
    (void)argc;
    (void)argv;
    
    //abrir ficheiro dado pelo utilizador --filenmame a.txt
    if (argc < 2 || strcmp(argv[1], "--file") != 0) {
        fprintf(stderr, "Usage: %s --file <file>\n", argv[0]);
        return 1;
    }
    const char *filename = argv[2];
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "[ERROR] Cannot open input file '%s': %s\n", filename, strerror(errno));
        return 1;
    }
    //ler ficheiro
    char buffer[1024]; // Buffer to hold file content
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0) {
        fprintf(stderr, "[ERROR] Cannot read input file '%s': %s\n", filename, strerror(errno));
        close(fd);
        return 1;
    }
    buffer[bytesRead] = '\0'; // Null-terminate the string

    // Verifica se o ficheiro tem conteudo
    if (bytesRead == 0) {
        fprintf(stderr, "[ERROR] Input file '%s' is empty.\n", filename);
        close(fd);
        return 1;
    }
    
    // Contar linhas
    int lines = 1; // Start with 1 to count the first line
    printf("Line %d: ", lines);
    for (ssize_t i = 0; i < bytesRead; i++) {
        char c = buffer[i];
        if (c != '\n') {
            putchar(c);
        } else {
            putchar('\n');
            if (i + 1 < bytesRead) {
                lines++;
                printf("Line %d: ", lines);
            }
        }
    }

    // Print the total number of lines
    printf("\nTotal number of lines: %d\n", lines);

    // Guardar o conteúdo convertido num novo ficheiro
    const char *output_filename = "output.txt";
    int out_fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0) {
        fprintf(stderr, "[ERROR] Cannot open output file '%s': %s\n", output_filename, strerror(errno));
        close(fd);
        return 1;
    }

    // Escrever o conteúdo convertido no ficheiro de saída
    // Write each line with its line number to the output file
    int current_line = 1;
    char line_prefix[32];
    ssize_t i = 0;
    while (i < bytesRead) {
        // Write line prefix
        int prefix_len = snprintf(line_prefix, sizeof(line_prefix), "Line %d: ", current_line);
        if (write(out_fd, line_prefix, prefix_len) < 0) {
            fprintf(stderr, "[ERROR] Cannot write to output file '%s': %s\n", output_filename, strerror(errno));
            close(fd);
            close(out_fd);
            return 1;
        }
        // Write line content
        while (i < bytesRead && buffer[i] != '\n') {
            if (write(out_fd, &buffer[i], 1) < 0) {
                fprintf(stderr, "[ERROR] Cannot write to output file '%s': %s\n", output_filename, strerror(errno));
                close(fd);
                close(out_fd);
                return 1;
            }
            i++;
        }
        // Write newline if present
        if (i < bytesRead && buffer[i] == '\n') {
            if (write(out_fd, "\n", 1) < 0) {
                fprintf(stderr, "[ERROR] Cannot write to output file '%s': %s\n", output_filename, strerror(errno));
                close(fd);
                close(out_fd);
                return 1;
            }
            i++;
        }
        current_line++;
    }

    printf("\nConverted content saved to '%s'.\n", output_filename);

    // Fechar o ficheiro de saída
    if (close(out_fd) < 0) {
        fprintf(stderr, "[ERROR] Cannot close output file '%s': %s\n", output_filename, strerror(errno));
        close(fd);
        return 1;
    }

    // Fechar o ficheiro
    if (close(fd) < 0) {
        fprintf(stderr, "[ERROR] Cannot close input file '%s': %s\n", filename, strerror(errno));
        return 1;
    }
    
    // Return success
    printf("\n");
    return 0;
}
