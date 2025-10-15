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
void deleteAtEnd(Node** head);

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

/* Function to delete a node at end */
void deleteAtEnd(Node** head) {
    if(*head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }
    
    Node* currNode = *head;
    // if((*head)->next == NULL)
    if(currNode->next == NULL) {
        free(currNode);
        *head = NULL;
        return;
    }

    while(currNode->next->next != NULL) {
        currNode = currNode->next;
    }

    free(currNode->next);
    currNode->next = NULL;
    
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

    printLL(head);

    deleteAtEnd(&head);
    printLL(head);
 
    return 0;
}
