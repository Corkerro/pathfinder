#include "../inc/libmx.h"

char *mx_to_lower_case(const char *str) {
    if (str == NULL)
        return NULL;

    char *new_str = malloc(sizeof(char) * mx_strlen(str) + 1);
    if (new_str == NULL)
        return NULL;

    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            new_str[i] = str[i] + 'a' - 'A';
        else
            new_str[i] = str[i];
    }

    return new_str;
}
