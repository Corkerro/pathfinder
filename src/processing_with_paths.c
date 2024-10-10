#include "../inc/header.h"

t_path *mx_create_path(int max_length) {
    t_path *path = malloc(sizeof(t_path));
    path->islands = malloc(max_length * sizeof(char *));
    path->distances = malloc((max_length - 1) * sizeof(int));
    path->length = 0;
    path->distance = 0;
    return path;
}

void mx_free_path(t_path *path) {
    free(path->islands);
    free(path->distances);
    free(path);
}
