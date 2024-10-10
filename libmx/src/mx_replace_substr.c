#include "../inc/libmx.h"

static char *replace_helper(
    const char *str, const char *sub, const char *replace, int new_len) {
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    char *new_str = (char *)malloc(new_len + 1);
    if (!new_str)
        return NULL;

    int i = 0;
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&new_str[i], replace);
            i += replace_len;
            str += sub_len;
        } else
            new_str[i++] = *str++;
    }
    new_str[i] = '\0';
    return new_str;
}

char *mx_replace_substr(
    const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace)
        return NULL;

    int sub_len = mx_strlen(sub);
    if (sub_len == 0)
        return NULL;

    int count = mx_count_substr(str, sub);
    if (count == 0)
        return mx_strdup(str);

    int new_len = mx_strlen(str) + (mx_strlen(replace) - sub_len) * count;

    return replace_helper(str, sub, replace, new_len);
}
