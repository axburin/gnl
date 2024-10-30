#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(intn argc, char **argv) 
{
    int fd;
    char *line;

    // Vérifie si un fichier est passé en argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Ouvre le fichier en mode lecture
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Lit et affiche chaque ligne du fichier
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);  // 'line' contient déjà le '\n' si 'get_next_line' fonctionne comme prévu
        free(line);  // Libère la mémoire allouée par 'get_next_line'
    }

    // Ferme le fichier
    close(fd);
    return 0;
}