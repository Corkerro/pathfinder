#include "../inc/header.h"


static void swap(t_island **connected_with, int *distances, int i, int j) {
    t_island *temp_island = connected_with[i];
    int temp_distance = distances[i];

    connected_with[i] = connected_with[j];
    distances[i] = distances[j];

    connected_with[j] = temp_island;
    distances[j] = temp_distance;
}

// Function to sort the connected_with and distances arrays based on island id
void sort_connected_islands(t_island *island) {
    for (int i = 0; i < island->connected_count - 1; i++) {
        for (int j = 0; j < island->connected_count - i - 1; j++) {
            if (island->connected_with[j]->id > island->connected_with[j + 1]->id) {
                swap(island->connected_with, island->distances, j, j + 1);
            }
        }
    }
}

int main(int argc, char **argv) {
    t_main_data main_data = {
    .number_of_islands = 0,
    .real_number_of_islands = 0,
    .error_line = 0,
    .summ_of_islands_bridges = 0,
    .islands = NULL
    };

    if (mx_validate_program_start(argc, argv, &main_data) != 0) {
        return -1;
	}

    for (int i = 0; i < main_data.number_of_islands; i++) {
        sort_connected_islands(main_data.islands[i]);
    }

	mx_print_all_shortest_paths(&main_data);

    mx_free_all_islands(&main_data);

    return 0;
}
