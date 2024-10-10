#include "../inc/libmx.h"

void mx_printint(int n) {
    if (n == 0) {
        mx_printchar('0');
        return;
    }

    if (n < 0) {
        mx_printchar('-');
        if (n == -2147483648) {
            mx_printstr("2147483648");
            return;
        }
        n = -n;
    }

    char *n_str = mx_nbr_to_string((long long)n, 10);
    mx_printstr(n_str);
    free(n_str);
}
