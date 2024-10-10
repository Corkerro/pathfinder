#include "../inc/header.h"

static t_error_status check_file_status(const char *filename, t_main_data *main_data) {
    char *file = mx_file_to_str(filename);
    if (file == NULL) {
        return FILE_NOT_EXIST;
    }
    if (file[0] == '\0') {
        mx_strdel(&file);
        return FILE_EMPTY;
    }

    char **data = mx_strsplit(file, '\n');
    mx_strdel(&file);
    t_error_status status = mx_validate_first_line(data[0], main_data);
    if (status != INVALID_LINE) {
        for (int line = 1; data[line] != NULL; line++) {
            t_error_status parse_status = mx_parse_islands(data[line], main_data);
            if (parse_status != NO_ERROR) {
                main_data->error_line = line + 1;
                mx_del_strarr(&data);
                mx_free_all_islands(main_data);
                return parse_status;
            }
        }
        if (main_data->number_of_islands != main_data->real_number_of_islands) {
            mx_del_strarr(&data);
            mx_free_all_islands(main_data);
            return INVALID_NUMBER;
        }

    } else {
        main_data->error_line = 1;
    }

    mx_del_strarr(&data);
    return status;
}

int mx_validate_program_start(int argc, char **argv, t_main_data *main_data) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    if (!main_data) return 0;

    t_error_status status = check_file_status(argv[1], main_data);

    switch (status) {
    case FILE_NOT_EXIST:
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        return 1;
        break;
    case FILE_EMPTY:
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        return 2;
        break;
    case FILE_NON_EMPTY:
        break;
    case INVALID_LINE:
        mx_print_error_with_line(main_data->error_line);
        return 3;
        break;
    case DUPLICATED_BRIDGES:
        mx_printerr("error: duplicate bridges\n");
        return 4;
        break;
    case SUM_OF_BRIDGES:
        mx_printerr("error: sum of bridges lengths is too big\n");
        return 5;
        break;
    case INVALID_NUMBER:
        mx_printerr("error: invalid number of islands\n");
        return 6;
        break;
    case NO_ERROR:
        break;
    }

    return 0;
}
