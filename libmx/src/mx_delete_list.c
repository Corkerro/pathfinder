#include "../inc/libmx.h"

void mx_delete_list(t_list **head, int free_data) {
    t_list *current = *head;
    t_list *next_node;

    while (current != NULL) {
        next_node = current->next;

        if (free_data)
            free(current->data);
        free(current);

        current = next_node;
    }

    *head = NULL;
}
