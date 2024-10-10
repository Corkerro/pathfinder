#include "../inc/libmx.h"

void mx_swap(void *a, void *b, size_t size) {
    if (a == NULL || b == NULL || size == 0)
        return;

    char temp[size];
    mx_memcpy(temp, a, size);
    mx_memcpy(a, b, size);
    mx_memcpy(b, temp, size);
}
