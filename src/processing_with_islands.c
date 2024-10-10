#include "../inc/header.h"

t_island *mx_get_island_by_name(const char *name, t_main_data *data) {
    for (int i = 0; i < data->real_number_of_islands; i++) {
        if (mx_strcmp(data->islands[i]->name, name) == 0) {
            return data->islands[i];
        }
    }
    return NULL;
}

t_island *mx_get_island_by_index(int id, t_main_data *data) {
	if (id > data->real_number_of_islands || id < 0) return NULL;

	return data->islands[id];
}

t_island *mx_init_island(const char *name, int id) {
    t_island *island = malloc(sizeof(t_island));
    if (!island) {
        mx_printerr("Error: failed to allocate memory for island\n");
        return NULL;
    }

    island->name = mx_strdup(name);
    if (!island->name) {
        mx_printerr("Error: failed to allocate memory for island name\n");
        free(island);
        return NULL;
    }

    island->connected_with = NULL;
    island->distances = NULL;
    island->connected_count = 0;
    island->id = id;
    return island;
}

t_island *mx_create_island_if_not_exist(const char *name, t_main_data *data) {
    t_island *island = mx_get_island_by_name(name, data);
    if (island)
        return island;

    island = mx_init_island(name, data->real_number_of_islands);
    data->islands = realloc(data->islands, sizeof(t_island) * (data->real_number_of_islands + 1));
    data->islands[data->real_number_of_islands] = island;

    data->real_number_of_islands++;

    return island;
}

int mx_connect_islands(const char *name1, const char *name2, int distance, t_main_data *data) {
    t_island *island1 = mx_create_island_if_not_exist(name1, data);
    t_island *island2 = mx_create_island_if_not_exist(name2, data);

    for (int i = 0; i < island1->connected_count; i++) {
        if (island1->connected_with[i] == island2) {
            return 0;
        }
    }

    island1->connected_with = realloc(island1->connected_with, sizeof(t_island *) * (island1->connected_count + 1));
    island1->distances = realloc(island1->distances, sizeof(int) * (island1->connected_count + 1));
    island1->connected_with[island1->connected_count] = island2;
    island1->distances[island1->connected_count] = distance;
    island1->connected_count++;

    island2->connected_with = realloc(island2->connected_with, sizeof(t_island *) * (island2->connected_count + 1));
    island2->distances = realloc(island2->distances, sizeof(int) * (island2->connected_count + 1));
    island2->connected_with[island2->connected_count] = island1;
    island2->distances[island2->connected_count] = distance;
    island2->connected_count++;

    return 1;
}

void mx_free_island(t_island *island) {
    free(island->name);
    free(island->connected_with);
    free(island->distances);
    free(island);
}

void mx_free_all_islands(t_main_data *data) {
    for (int i = 0; i < data->real_number_of_islands; i++) {
        mx_free_island(data->islands[i]);
    }
    free(data->islands);
}
