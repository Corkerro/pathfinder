#ifndef HEADER_H
#define HEADER_H

#pragma once

#include "../libmx/inc/libmx.h"
#include "enums.h"
#include "structs.h"

void mx_print_all_shortest_paths(t_main_data *data);
int mx_validate_program_start(int argc, char **argv, t_main_data *main_data);
char **parse_data(const char *line);
t_error_status mx_parse_islands(const char *line, t_main_data *main_data);
t_error_status mx_validate_first_line(const char *buffer, t_main_data *main_data);
void mx_dfs(t_main_data *data, t_island *current, t_island *target, int current_distance,
          t_path **all_paths, int *path_count, t_path *current_path, int *min_distance);
void mx_print_error_with_line(int line);

// processing_with_islands.c
t_island *mx_get_island_by_name(const char *name, t_main_data *data);
t_island *mx_get_island_by_index(int id, t_main_data *data);
t_island *mx_create_island_if_not_exist(const char *name, t_main_data *data);
int mx_connect_islands(const char *name1, const char *name2, int distance, t_main_data *data);
void mx_free_island(t_island *island);
void mx_free_all_islands(t_main_data *data);

// processing_with_paths.c
t_path *mx_create_path(int max_length);
void mx_free_path(t_path *path);

// processing_with_prints.c
void mx_print_devider(void);
void mx_print_path(const char *start, const char *end);
void mx_print_error(const char *start, const char *end);

#endif //HEADER_H
