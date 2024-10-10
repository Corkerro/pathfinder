#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    int length = mx_strlen(s1);

    char *new_str = (char *)malloc((length + 1) * sizeof(char));
    if (!new_str)
        return NULL;

    mx_memcpy(new_str, s1, length);

    new_str[length] = '\0';

    return new_str;
}
