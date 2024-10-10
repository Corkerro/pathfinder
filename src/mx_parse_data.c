#include "../inc/header.h"

static void free_string_array(char **array) {
    if (array != NULL) {
        for (int i = 0; array[i] != NULL; i++) {
            free(array[i]);
        }
        free(array);
    }
}

static char **safe_strsplit(const char *line, char delimiter) {
    char **result = mx_strsplit(line, delimiter);
    if (result == NULL || result[0] == NULL) {
        free_string_array(result);
        return NULL;
    }
    return result;
}

static char **create_real_data(char **first_data, char **second_data) {
    char **real_data = malloc(sizeof(char *) * 4);
    if (real_data == NULL) {
        return NULL;
    }

    real_data[0] = mx_strdup(first_data[0]);
    real_data[1] = mx_strdup(second_data[0]);
    real_data[2] = second_data[1] != NULL ? mx_strdup(second_data[1]) : NULL;
    real_data[3] = NULL;

    return real_data;
}

char **parse_data(const char *line) {
    if (line == NULL || line[0] == '-') {
        return NULL;
    }

    char **first_data = safe_strsplit(line, '-');
    if (first_data == NULL || first_data[1] == NULL) {
        free_string_array(first_data);
        return NULL;
    }

    char **second_data = safe_strsplit(first_data[1], ',');
    if (second_data == NULL) {
        free_string_array(first_data);
        return NULL;
    }

    char **real_data = create_real_data(first_data, second_data);
    if (real_data == NULL) {
        free_string_array(first_data);
        free_string_array(second_data);
        return NULL;
    }

    free_string_array(first_data);
    free_string_array(second_data);

    return real_data;
}
