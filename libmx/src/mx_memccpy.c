#include "../inc/libmx.h"

void *mx_memccpy(
    void *restrict dst, const void *restrict src, int c, size_t n) {
    char *loc_dst = (char *)dst;
    const char *loc_src = (const char *)src;

    for (size_t i = 0; i < n; i++) {
        loc_dst[i] = loc_src[i];
        if ((unsigned char)loc_src[i] == (unsigned char)c)
            return (void *)(loc_dst + i + 1);  // +1 to next pointer after c
    }

    return NULL;
}
