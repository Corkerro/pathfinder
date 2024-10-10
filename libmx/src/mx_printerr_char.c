#include "../inc/libmx.h"

void mx_printerr_char(char c) {
    write(STDERR_FILENO, &c, 1);
}
