#include "shell.h"
/**
 * _setenv - Initialize a new environment variable,
 *             else modify an existing one
 *  Return: zero on success and return -1 on failure 
**/


// node_t *head = NULL;

int _setenv(const char *name, const char *value, int overwrite) {
    node_t *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (!overwrite) {
                return 0;
            }

            free(current->value);
            current->value = strdup(value);

            return 0;
        }

        current = current->next;
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->value = strdup(value);
    new_node->next = head;
    head = new_node;

    return 0;
}


