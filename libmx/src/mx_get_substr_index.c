#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return -2;

    if (*sub == '\0')
        return 0;

    char *found = mx_strstr(str, sub);

    if (found)
        return found - str;

    return -1;
}
