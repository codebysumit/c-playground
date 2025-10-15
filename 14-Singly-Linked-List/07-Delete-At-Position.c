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

/* Function to delete a node at a position */
void deleteAtPosition(Node** head, int position) {
    Node* curr = *head;
    Node* prev = *head;
    if(*head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }
    else if(position == 0 && head != NULL){
        *head = curr->next;
        free(curr);
        return;
    }

    curr = curr->next;
    int count = 1;
    
    while(curr != NULL && count < position){
        prev = curr;
        curr = curr->next;
        count += 1;
    }

    if(position == count){
        prev->next = curr->next;
        free(curr);
    }
    else {
        printf("Index out of range.\n");
        return;
    }
    
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

    deleteAtPosition(&head, 2);
    printLL(head);
 
    return 0;
}
