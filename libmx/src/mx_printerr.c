#include "../inc/libmx.h"

void mx_printerr(const char *s) {
    if (s == NULL)
        return;

    write(STDERR_FILENO, s, mx_strlen(s));
}
