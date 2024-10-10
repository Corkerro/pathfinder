#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *str = (const unsigned char *)s;
    unsigned char symbol = (unsigned char)c;

    for (size_t i = 0; i < n; i++)
        if (str[i] == symbol)
            return (void *)(str + i);

    return NULL;
}
