#include "../inc/libmx.h"

char *mx_itoa(int number) {
    return mx_nbr_to_string((long long)number, 10);
}
