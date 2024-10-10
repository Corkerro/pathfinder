#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct t_island t_island;

typedef struct t_island {
    char *name;
    struct t_island **connected_with;
    int *distances;
    int connected_count;
	int id;
} t_island;

typedef struct t_main_data t_main_data;

struct t_main_data {
    int number_of_islands;
    int real_number_of_islands;
    int error_line;
    unsigned int summ_of_islands_bridges;
    t_island **islands;
};

typedef struct s_path {
    char **islands;
    int length;
    int distance;
    int *distances;
} t_path;

#endif //STRUCTS_H
