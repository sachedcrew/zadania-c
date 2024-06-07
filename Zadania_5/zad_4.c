#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void remove_by_index(Node** head, int index) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;

    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return; 
    }

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
