#include "../inc/header.h"

void mx_print_devider(void) {
    mx_printstr("========================================\n");
}

void mx_print_path(const char *start, const char *end) {
    mx_printstr("Path: ");
    mx_printstr(start);
    mx_printstr(" -> ");
    mx_printstr(end);
    mx_printchar('\n');
}

void mx_print_error(const char *start, const char *end) {
    mx_printstr("No paths found between ");
    mx_printstr(start);
    mx_printstr(" and ");
    mx_printstr(end);
    mx_printstr(".\n");
}
