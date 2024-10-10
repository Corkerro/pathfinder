#include "../inc/libmx.h"

void mx_swap_str(char **s1, char **s2) {
    mx_swap(s1, s2, sizeof(char *));
}
