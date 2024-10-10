#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex_nbr = mx_nbr_to_string((long long)nbr, 16);

    return hex_nbr;
}
