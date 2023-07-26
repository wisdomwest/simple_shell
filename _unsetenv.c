#include "shell.h"

/**
 * _unsetenv - Remove an environment variable
 *  Return: zero on success and return -1 on failure 
**/


// node_t *head = NULL;

int _unsetenv(const char *name) {
    node_t *current = head;
    node_t *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current->name);
            free(current->value);
            free(current);

            return 0;
        }

        previous = current;
        current = current->next;
    }

    return -1;
}