#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* buildTree(int preOrder[]);
void preorderTraversal(Node* root);
void inorderTraversal(Node* root);
void postorderTraversal(Node* root);

/*
# Use Case of `createNode(int) -> Node*`:
    Node* root = createNode(10);
    printf("data: %d,  left: %p, right: %p", root->data, root->left, root->right);
*/

Node* createNode(int data) {
    Node* rootNode = malloc(sizeof(Node));
    rootNode->data = data;
    rootNode->left = NULL;
    rootNode->right = NULL;
    return rootNode;
}

/*
# Use Case of `buildTree(int[]) -> Node*`:
    // preOrder array representation of the tree
    // root -> left -> right
    int preOrder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);
    printf("%d\n", root->right->right->data); // Output: 5
    printf("%d\n", root->right->data); // Output: 3

    idex = -1; // reset index for next tree
    Node* root2 = buildTree(preOrder);
    printf("%d\n", root2->right->data); // Output: 3   
*/
static int idex = -1;
Node* buildTree(int preOrder[]){
    idex++;

    if(preOrder[idex] == -1) {
        return NULL;
    }

    Node* root = createNode(preOrder[idex]);
 
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

// pre order traversal
void preorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    // root - Left -  right
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// in order traversal
void inorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    // Left - root - right
    preorderTraversal(root->left);
    printf("%d ", root->data);
    preorderTraversal(root->right);
}

// post order traversal
void postorderTraversal(Node* root) {
    if(root == NULL){
        return;
    }

    // left - right - root
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // int preOrder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int preOrder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node* root = buildTree(preOrder);

    printf("Pre-Order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("In-Order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
