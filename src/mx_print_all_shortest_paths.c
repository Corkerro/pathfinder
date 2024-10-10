#include "../inc/header.h"

static void mx_find_all_shortest_paths(t_island *start, t_island *end, t_main_data *data) {
    t_path *current_path = mx_create_path(data->number_of_islands);
    t_path **all_paths = malloc(data->number_of_islands * 10 * sizeof(t_path *));
    int path_count = 0;
    int min_distance = INT_MAX;

    mx_dfs(data, start, end, 0, all_paths, &path_count, current_path, &min_distance);

    if (path_count == 0) {
        mx_print_devider();
        mx_print_error(start->name, end->name);
        mx_print_devider();
    } else {
        for (int i = 0; i < path_count; i++) {
            mx_print_devider();
            mx_print_path(start->name, end->name);

            mx_printstr("Route: ");
            for (int j = 0; j < all_paths[i]->length; j++) {
                mx_printstr(all_paths[i]->islands[j]);
                if (j < all_paths[i]->length - 1) {
                    mx_printstr(" -> ");
                }
            }
            mx_printchar('\n');

            mx_printstr("Distance: ");
            if (all_paths[i]->length == 2) {
                mx_printint(all_paths[i]->distances[0]);
            } else {
                mx_printint(all_paths[i]->distances[0]);
                for (int j = 1; j < all_paths[i]->length; j++) {
                    if (j < all_paths[i]->length - 1) {
                        mx_printstr(" + ");
                        mx_printint(all_paths[i]->distances[j]);
                    }
                }
                mx_printstr(" = ");
                mx_printint(all_paths[i]->distance);
            }
            mx_printchar('\n');

            mx_print_devider();
            mx_free_path(all_paths[i]);
        }
    }

    free(all_paths);
    mx_free_path(current_path);
}

void mx_print_all_shortest_paths(t_main_data *data) {
    for (int i = 0; i < data->real_number_of_islands; i++) {
        for (int j = i + 1; j < data->real_number_of_islands; j++) {
            t_island *start = mx_get_island_by_index(i, data);
            t_island *end = mx_get_island_by_index(j, data);
            mx_find_all_shortest_paths(start, end, data);
        }
    }
}
