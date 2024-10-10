#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL)
        return NULL;

    char *trimmed_str = mx_strtrim(str);
    if (trimmed_str == NULL)
        return NULL;

    size_t length = mx_strlen(trimmed_str);
    char *temp_str = (char *)malloc(length + 1);
    if (temp_str == NULL) {
        free(trimmed_str);
        return NULL;
    }

    char *dst = temp_str;
    const char *src = trimmed_str;
    int subcounter = 0;

    while (*src) {
        if (mx_is_whitespace(*src)) {
            if (subcounter) {
                *dst++ = ' ';
                subcounter = 0;
            }
        } else {
            *dst++ = *src;
            subcounter = 1;
        }
        src++;
    }

    *dst = '\0';

    char *cleaned_str = (char *)mx_realloc(temp_str, mx_strlen(temp_str) + 1);
    if (cleaned_str == NULL) {
        free(temp_str);
        free(trimmed_str);
        return NULL;
    }

    free(trimmed_str);

    return cleaned_str;
}
