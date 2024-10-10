#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL)
        return NULL;

    while (mx_is_whitespace(*str)) {
        str++;
    }

    if (*str == '\0')
        return mx_strdup("");

    const char *end = str;
    while (*end != '\0') end++;
    end--;

    while (mx_is_whitespace(*end)) end--;

    size_t length = end - str + 1;

    char *trimmed_str = (char *)malloc((length + 1) * sizeof(char));
    if (trimmed_str == NULL)
        return NULL;

    for (size_t i = 0; i < length; i++) trimmed_str[i] = str[i];

    trimmed_str[length] = '\0';

    return trimmed_str;
}
