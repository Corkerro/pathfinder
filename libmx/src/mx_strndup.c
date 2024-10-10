#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t length = mx_strlen(s1);
    size_t copy_len = (n < length) ? n : length;

    char *new_str = (char *)malloc(copy_len + 1);
    if (new_str == NULL)
        return NULL;

    mx_memcpy(new_str, s1, copy_len);
    new_str[copy_len] = '\0';

    return new_str;
}
