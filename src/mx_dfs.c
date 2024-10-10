#include "../inc/header.h"

void mx_dfs(t_main_data *data, t_island *current, t_island *target, int current_distance,
          t_path **all_paths, int *path_count, t_path *current_path, int *min_distance) {
    current_path->islands[current_path->length++] = current->name;

    if (current == target) {
        current_path->distance = current_distance;

        if (current_distance < *min_distance) {
            *min_distance = current_distance;
            for (int i = 0; i < *path_count; i++) {
                mx_free_path(all_paths[i]);
                all_paths[i] = NULL;
            }
            *path_count = 0;
        }

        if (current_distance == *min_distance) {
            t_path *new_path = mx_create_path(current_path->length);
            mx_memcpy(new_path->islands, current_path->islands, current_path->length * sizeof(char *));
            new_path->length = current_path->length;
            new_path->distance = current_distance;
            mx_memcpy(new_path->distances, current_path->distances, (current_path->length - 1) * sizeof(int));

            all_paths[*path_count] = new_path;
            (*path_count)++;
        }
    } else {
        for (int i = 0; i < current->connected_count; i++) {
            t_island *neighbor = current->connected_with[i];
            int distance = current->distances[i];

            current_path->distances[current_path->length - 1] = distance;

            int already_in_path = 0;
            for (int j = 0; j < current_path->length; j++) {
                if (mx_strcmp(current_path->islands[j], neighbor->name) == 0) {
                    already_in_path = 1;
                    break;
                }
            }

            if (!already_in_path) {
                mx_dfs(data, neighbor, target, current_distance + distance, all_paths, path_count, current_path, min_distance);
            }
        }
    }

    current_path->length--;
}
