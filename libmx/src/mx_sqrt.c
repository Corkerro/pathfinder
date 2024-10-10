#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x < 0)
        return 0;

    if (x == 0)
        return 0;

    int left = 0;
    int right = x;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        long long mid_squared = (long long)mid * mid;

        if (mid_squared == x) {
            return mid;
        } else if (mid_squared < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}
