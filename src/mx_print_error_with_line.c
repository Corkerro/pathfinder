#include "../inc/header.h"

void mx_print_error_with_line(int line) {
    mx_printerr("error: line ");
    mx_printerr_int(line);
    mx_printerr(" is not valid\n");
}
