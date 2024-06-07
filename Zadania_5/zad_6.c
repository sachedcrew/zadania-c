#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void add_at_index(Node** head, int index, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node* temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return; 
    }

    new_node->next = temp->next;
    temp->next = new_node;
}
