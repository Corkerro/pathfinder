#include "../inc/libmx.h"

static int get_file_size(const char *file) {
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return -1;

    char buffer;
    int size = 0;

    while (read(fd, &buffer, 1) > 0) size++;

    close(fd);
    return size;
}

static char *read_file_content(const char *file, int size) {
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;

    char *content = (char *)malloc(size + 1);
    if (!content) {
        close(fd);
        return NULL;
    }

    if (read(fd, content, size) != size) {
        free(content);
        close(fd);
        return NULL;
    }

    content[size] = '\0';
    close(fd);
    return content;
}

char *mx_file_to_str(const char *file) {
    if (!file)
        return NULL;

    int size = get_file_size(file);
    if (size < 0)
        return NULL;

    return read_file_content(file, size);
}
