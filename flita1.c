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
        current = current->next;
    }
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

int main(void) {

    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    printf("Filling  the list\n");
    int i = 1;
    while i < 10{
        int per = 0;
        scanf("%d",&per);
        push_start(&head,per);
        i++;
    }
    
    printf("Print list\n\n");
    print_list(head);
    printf("Delete last element\n\n");
    pop(&head);
    print_list(head);    
    return 0;
}
