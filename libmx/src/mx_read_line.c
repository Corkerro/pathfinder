#include "../inc/libmx.h"

static int read_from_remainder(char **lineptr, char **remainder, char delim) {
    int i = 0;
    while ((*remainder)[i] != '\0') {
        if ((*remainder)[i] == delim) {
            (*remainder)[i] = '\0';
            *lineptr = malloc(i + 1);
            if (!*lineptr) return -2;

            for (int j = 0; j < i; j++)
                (*lineptr)[j] = (*remainder)[j];
            (*lineptr)[i] = '\0';

            char *new_remainder = malloc(mx_strlen(*remainder + i + 1) + 1);
            if (!new_remainder) {
                free(*lineptr);
                return -2;
            }

            for (int j = 0; (*remainder)[i + 1 + j] != '\0'; j++)
                new_remainder[j] = (*remainder)[i + 1 + j];
            new_remainder[mx_strlen(*remainder + i + 1)] = '\0';

            free(*remainder);
            *remainder = new_remainder;

            return i;
        }
        i++;
    }

    *lineptr = malloc(i + 1);
    if (!*lineptr) return -2;

    for (int j = 0; j < i; j++)
        (*lineptr)[j] = (*remainder)[j];
    (*lineptr)[i] = '\0';

    free(*remainder);
    *remainder = NULL;

    return i;
}

static int process_buffer(char **lineptr, char *buffer, int buf_size, char delim, char **remainder, int total_len) {
    for (int i = 0; i < buf_size; i++) {
        if (buffer[i] == delim) {
            *lineptr = mx_realloc(*lineptr, total_len + i + 1);
            if (!*lineptr) return -2;

            for (int j = 0; j < i; j++)
                (*lineptr)[total_len + j] = buffer[j];
            (*lineptr)[total_len + i] = '\0';

            *remainder = malloc(buf_size - i);
            if (!*remainder) {
                free(*lineptr);
                return -2;
            }

            for (int j = 0; j < buf_size - i - 1; j++)
                (*remainder)[j] = buffer[i + 1 + j];
            (*remainder)[buf_size - i - 1] = '\0';

            return total_len + i;
        }
    }

    *lineptr = mx_realloc(*lineptr, total_len + buf_size + 1);
    if (!*lineptr) return -2;

    for (int j = 0; j < buf_size; j++)
        (*lineptr)[total_len + j] = buffer[j];

    return total_len + buf_size;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static char *remainder = NULL;
    char *buffer = malloc(buf_size);
    int total_len = 0, bytes_read;

    if (fd < 0 || !lineptr || buf_size <= 0 || !buffer) {
        free(buffer);
        return -2;
    }

    *lineptr = NULL;

    if (remainder) {
        int len = read_from_remainder(lineptr, &remainder, delim);
        if (len > 0 || len == -2) {
            free(buffer);
            return len;
        }
        total_len = len;
    }

    while ((bytes_read = read(fd, buffer, buf_size)) > 0) {
        total_len = process_buffer(lineptr, buffer, bytes_read, delim, &remainder, total_len);
        if (total_len >= 0) {
            free(buffer);
            return total_len;
        }
    }

    free(buffer);

    if (bytes_read == 0 && total_len > 0) return total_len;

    return -1;
}
