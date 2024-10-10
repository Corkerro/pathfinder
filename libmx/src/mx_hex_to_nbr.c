#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL)
        return 0;

    int size = mx_strlen(hex);
    unsigned long result = 0;

    char *lower_hex = mx_to_lower_case(hex);
    if (lower_hex == NULL)
        return 0;

    for (int i = 0; i < size; i++) {
        char c = lower_hex[i];
        unsigned long value;
        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'a' && c <= 'f')
            value = c - 'a' + 10;
        else
            return 0;

        result = result * 16 + value;
    }

    free(lower_hex);
    return result;
}
