#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return -1;

    if (*sub == '\0')
        return 0;

    int count = 0;
    const char *temp = str;

    while ((temp = mx_strstr(temp, sub)) != NULL) {
        count++;
        temp += mx_strlen(sub);  // Move past the last found occurrence of sub
    }

    return count;
}
