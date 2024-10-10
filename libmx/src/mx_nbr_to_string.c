#include "../inc/libmx.h"

char *mx_nbr_to_string(long long nbr, int divider) {
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
        'b', 'c', 'd', 'e', 'f'};
    int size = mx_count_digits(nbr, divider);
    int is_negative = (nbr < 0 && divider == 10) ? 1 : 0;
    char *nbr_str;

    if (is_negative) {
        nbr = -nbr;
        size++;
    }

    nbr_str = malloc(sizeof(char) * (size + 1));
    if (!nbr_str)
        return NULL;

    nbr_str[size] = '\0';

    if (nbr == 0) {
        nbr_str[0] = '0';
    } else {
        while (size > (is_negative ? 1 : 0)) {
            nbr_str[--size] = digits[nbr % divider];
            nbr /= divider;
        }
    }

    if (is_negative) {
        nbr_str[0] = '-';
    }

    return nbr_str;
}
