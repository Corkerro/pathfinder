#include "../inc/libmx.h"

void mx_swap_char(char *s1, char *s2) {
    if (s1 == NULL || s2 == NULL)
        return;

    mx_swap(s1, s2, sizeof(char));
}
