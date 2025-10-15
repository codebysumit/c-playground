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
    free(current);
}

/* Main function */
int main() {
    Node* head = NULL;

    /* Create nodes */
    Node* myNode1 = createNode(10);
    Node* myNode2 = createNode(20);
    Node* myNode3 = createNode(30);
    Node* myNode4 = createNode(40);

    /* Link nodes correctly */
    head = myNode1;
    head->next = myNode2;
    head->next->next = myNode3;
    head->next->next->next = myNode4;

    /* Print linked list */
    printLL(head);

    /* Free memory */
    free(myNode1);
    free(myNode2);
    free(myNode3);
    free(myNode4);

    return 0;
}
