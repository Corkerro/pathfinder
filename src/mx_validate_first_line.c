#include "../inc/header.h"

static int validate_first_line(const char *first_line, int *number) {
    if (first_line == NULL || !(*first_line >= '1' && *first_line <= '9'))
        return 0;

    int len = mx_strlen(first_line) - 1;

    for (int i = 0; i < len; i++) {
        if (!(first_line[i] >= '0' && first_line[i] <= '9'))
            return 0;
    }

    int error = 0;
    *number = mx_str_to_int(first_line, &error);

    if (error)
        return 0;

    return 1;
}

t_error_status mx_validate_first_line(const char *buffer, t_main_data *main_data) {
    int number_of_islands = 0;

    if (validate_first_line(buffer, &number_of_islands)) {
        main_data->number_of_islands = number_of_islands;
        return FILE_NON_EMPTY;
    }
    return INVALID_LINE;
}
