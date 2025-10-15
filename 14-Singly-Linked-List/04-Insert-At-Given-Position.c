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
void insertAtHead(Node** head, int data);
void insertAtPosition(Node** head, int data, int position)

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

/* Function to insert a new node at head */
void insertAtHead(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

/* Function to insert a new node at given position */
void insertAtPosition(Node** head, int data, int position) {
    if(position == 0 || *head == NULL) {
        insertAtHead(&*head, data);
        return;
    }
    
    Node* newNode = createNode(data);
    Node* currNode = *head;
    int counter = 1;
    while(currNode != NULL && counter < position) {
        currNode = currNode->next;
        counter += 1;
    }
    
    if (currNode == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    
    newNode->next = currNode->next;
    currNode->next = newNode;
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

    insertAtPosition(&head, 80, 1);
    printLL(head);
    
    insertAtPosition(&head, 50, 0);
    printLL(head);
 
    return 0;
}
