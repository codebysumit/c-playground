#include <stdio.h>
#include <stdlib.h>

/* Define the Node structure properly */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function declarations */
Node* createNode(int data);
void printLL(Node* head);
void deleteAtPosition(Node** head, int position);

/* Function to create a new node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to print the linked list */
void printLL(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/* Function to delete a node at a given position (0-based index) */
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }

    Node* curr = *head;

    /* Case 1: Deleting the head node */
    if (position == 0) {
        *head = curr->next;
        free(curr);
        return;
    }

    /* Traverse to the node before the target position */
    Node* prev = NULL;
    int count = 0;
    while (curr != NULL && count < position) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    /* If position is out of range */
    if (curr == NULL) {
        printf("Index out of range.\n");
        return;
    }

    /* Unlink the node and free it */
    prev->next = curr->next;
    free(curr);
}

/* Main function */
int main() {
    Node* head = NULL;

    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);

    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;

    printf("Original Linked List:\n");
    printLL(head);

    deleteAtPosition(&head, 4);  // trying to delete index 4 (invalid)
    printLL(head);

    deleteAtPosition(&head, 2);  // delete index 2 (30)
    printLL(head);

    deleteAtPosition(&head, 0);  // delete head (10)
    printLL(head);

    return 0;
}
