#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    if (src == NULL || dst == NULL)
        return NULL;

    char *init_dst = dst;

    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }

    *dst = '\0';

    return init_dst;
}
