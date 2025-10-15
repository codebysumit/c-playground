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
void insertAtEnd(Node** head, int data);

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

/* Function to insert a new node at end */
void insertAtEnd(Node** head, int data) {
    if(*head == NULL) {
        *head = createNode(data);
        return;
    }
    
    Node* currentNode = *head;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    
    Node* newNode = createNode(data);
    currentNode->next = newNode;
}

/* Main function */
int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    /* Print linked list */
    printLL(head);

    return 0;
}
