#include "../inc/libmx.h"

int mx_count_digits(long long number, int divider) {
    int count = 0;

    if (number == 0)
        return 1;

    if (number < 0)
        number = -number;

    while (number != 0) {
        number /= divider;
        count++;
    }

    return count;
}
