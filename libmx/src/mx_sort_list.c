#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL || lst->next == NULL)
        return lst;

    bool swapped = true;
    t_list *current;
    t_list *last = NULL;

    while (swapped) {
        swapped = false;
        current = lst;

        while (current->next != last) {
            if (cmp(current->data, current->next->data)) {
                void *temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    }

    return lst;
}
