#include "../inc/libmx.h"

int count_words(const char *s, char c) {
    int count = 0;
    int in_word = 0;

    while (*s) {
        if (*s == c) {
            if (in_word) {
                in_word = 0;
            }
        } else {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        }
        s++;
    }

    return count;
}

char *copy_substr(const char *start, const char *end) {
    size_t length = end - start;
    char *substr = (char *)malloc(length + 1);

    if (substr) {
        mx_memcpy(substr, start, length);
        substr[length] = '\0';
    }

    return substr;
}

char **mx_strsplit(const char *s, char c) {
    if (!s) return NULL;

    int num_words = count_words(s, c);
    char **arr = (char **)malloc((num_words + 1) * sizeof(char *));
    if (!arr) return NULL;

    const char *start = NULL;
    int i = 0;

    while (*s) {
        if (*s != c) {
            if (!start) start = s;
        } else {
            if (start) {
                arr[i++] = copy_substr(start, s);
                start = NULL;
            }
        }
        s++;
    }

    if (start)
        arr[i++] = copy_substr(start, s);

    arr[i] = NULL;

    return arr;
}
