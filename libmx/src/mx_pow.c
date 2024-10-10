#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    double num = 1;

    if (pow == 0)
        return 1.0;
    else {
        while (pow >= 1) {
            num *= n;
            pow--;
        }

        return num;
    }
}

