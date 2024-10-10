#include "../inc/libmx.h"

void mx_printerr_int(int n) {
    if (n == 0) {
        mx_printerr_char('0');
        return;
    }

    if (n < 0) {
        mx_printchar('-');
        if (n == -2147483648) {
            mx_printerr("2147483648");
            return;
        }
        n = -n;
    }

    char *n_str = mx_nbr_to_string((long long)n, 10);
    mx_printerr(n_str);
    free(n_str);
}
