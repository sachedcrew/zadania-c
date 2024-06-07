#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void pop(Node** head) {
    if (*head == NULL) {
        return; 
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
