#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL)
        return -1;

    int count = 0;
    int subcounter = 0;

    while (*str) {
        if (*str != c && subcounter == 0) {
            subcounter = 1;
            count++;
        } else if (*str == c)
            subcounter = 0;
        str++;
    }

    return count;
}
