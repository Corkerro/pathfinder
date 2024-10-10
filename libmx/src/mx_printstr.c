#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    if (s == NULL)
        return;

    write(STDOUT_FILENO, s, mx_strlen(s));
}
