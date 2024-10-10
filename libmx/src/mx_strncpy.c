#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    if (dst == NULL || src == NULL || len < 0)
        return NULL;

    char *init_dst = dst;

    for (int i = 0; i < len; i++) {
        if (*src == '\0')
            *dst = '\0';
        else
            *dst = *src;
        dst++;
        src++;
    }

    return init_dst;
}
