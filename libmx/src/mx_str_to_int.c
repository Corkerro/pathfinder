#include "../inc/libmx.h"

int mx_str_to_int(const char *str, int *error) {
    long result = 0;
    int sign = 1;
    *error = 0;

    while (mx_is_whitespace(*str))
        str++;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');

        if (result > INT_MAX) {
            *error = 1;
            return 0;
        }

        str++;
    }

    return sign * result;
}
