#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (!s1 && !s2)
        return NULL;

    if (!s1)
        return mx_strdup(s2);

    if (!s2)
        return mx_strdup(s1);

    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    char *result = (char *)malloc(len1 + len2 + 1);

    if (!result)
        return NULL;

    mx_strcpy(result, s1);
    mx_strcpy(result + len1, s2);

    return result;
}
