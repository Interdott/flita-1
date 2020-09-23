#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {

    node_t * current = head;

    while (current != NULL) {
        printf("Value: %d\n", current->val);
        printf("Address: %p\n", (void *)current->next);
        current = current->next;
    }
}

void push(node_t * head, int val) {

    node_t * current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void push_start(node_t ** head, int val) {

    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head) {

    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(node_t * head) {

    int retval = 0;

    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

int remove_by_index(node_t ** head, int n) {

    int i = 0;
    int retval = -1;

    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

int main() {

    node_t * head = NULL;
    head = malloc(sizeof(node_t));

    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = malloc(sizeof(node_t));
    head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(node_t));
    head->next->next->next->val = 4;
    head->next->next->next->next = NULL;

    return 0;
}
