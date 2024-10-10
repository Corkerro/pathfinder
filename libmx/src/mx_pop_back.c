#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (!head || !*head)
        return;

    t_list *current = *head;
    t_list *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL)
        *head = NULL;
    else
        previous->next = NULL;

    free(current);
}
