#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL)
        return -1;

    int swaps = 0;

    if (left < right) {
        int i = left;
        int j = right;

        int mid_index = (left + right) / 2;
        int pivot_length = mx_strlen(arr[mid_index]);

        while (i <= j) {
            while (mx_strlen(arr[i]) < pivot_length) {
                i++;
            }
            while (mx_strlen(arr[j]) > pivot_length) {
                j--;
            }

            if (i <= j) {
                if (i != j && mx_strlen(arr[i]) != mx_strlen(arr[j])) {
                    char *temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    swaps++;
                }
                i++;
                j--;
            }
        }

        swaps += mx_quicksort(arr, left, j);
        swaps += mx_quicksort(arr, i, right);
    }

    return swaps;
}
