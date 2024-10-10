#include "../inc/header.h"

static int validate_format(const char *str) {
    int comma_count = 0;
    int hyphen_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            comma_count++;
        } else if (str[i] == '-') {
            hyphen_count++;
        }
    }

    return comma_count == 1 && hyphen_count == 1;
}

static void free_data(char **data) {
    for (int i = 0; data[i] != NULL; i++) {
        free(data[i]);
    }
    free(data);
}

static int is_alpha_only(const char *str) {
    if (!str) return 0;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            return 0;
        }
    }
    return 1;
}


t_error_status mx_parse_islands(const char *line, t_main_data *main_data) {
    if (!validate_format(line)) return INVALID_LINE;

    char **data = parse_data(line);
    if (data == NULL) return INVALID_LINE;
    if (mx_strcmp(data[0], data[1]) == 0 || !is_alpha_only(data[0]) || !is_alpha_only(data[1])) {
        free_data(data);
        return INVALID_LINE;
    }

    int error = 0;
    int number = mx_str_to_int(data[2], &error);

    main_data->summ_of_islands_bridges += (unsigned int) number;

    if (number <= 0) {
        free_data(data);
        return INVALID_LINE;
    }

    if (error || main_data->summ_of_islands_bridges > INT_MAX) {
        free_data(data);
        return SUM_OF_BRIDGES;
    }

    if (!mx_connect_islands(data[0], data[1], number, main_data)) {
        free_data(data);
        return DUPLICATED_BRIDGES;
    }

    free_data(data);
    return NO_ERROR;
}
