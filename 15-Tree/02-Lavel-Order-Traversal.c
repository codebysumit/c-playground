#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} tree;

typedef struct node {
    tree* data;
    struct node* next;
} node;

typedef struct queue {
    node* head;
    node* tail;
    size_t size;
} queue;

node* init_node(tree* data) {
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

queue* init_queue(void) {
    queue* new_queue = (queue*)malloc(sizeof(queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    new_queue->size = 0;
    return new_queue;
}

void push(queue* q, tree* data) {
    node* new_node = init_node(data);
    if(new_node == NULL) {
        printf("Memory full!");
        return;
    }

    if(q->head == NULL){
        q->head = new_node;
        q->tail = new_node;
    }
    else {
    q->tail->next = new_node;
    q->tail = new_node;
    }
    q->size++;
}

void pop(queue* q) {
    if(q->head == NULL){
        return;
    }
    node* temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->size--;
    if (q->head == NULL) {
        /* queue became empty: clear tail to avoid dangling pointer */
        q->tail = NULL;
    }
}

tree* fornt(queue* q){
    if(q->head == NULL){
        return NULL;
    }
    return q->head->data;
}

size_t get_size(queue* q) {
    return q->size;
}

bool is_queue_empty(queue* q) {
    return (q->size == 0 ? true : false);
}

tree* init_tree(int data) {
    tree* new_tree = (tree*)malloc(sizeof(tree));
    new_tree->data = data;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}

static int idx = -1;
tree* build_tree(int pre_order[]) {
    idx++;

    if(pre_order[idx] == -1){
        return NULL;
    }

    tree* root = init_tree(pre_order[idx]);
    root->left = build_tree(pre_order);
    root->right = build_tree(pre_order);

    return root;
}

void pre_order_traversal(tree* root){
    if(root == NULL) {
        return;
    }
    
    // root-left-right
    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

/*
void lavel_order_traversal(tree* root) {
    queue* q = init_queue();
    push(q, root);

    while(q->size > 0){
        tree* curr = fornt(q);
        pop(q);
        // printf("%d", curr->data);

        if(curr->left != NULL){
            push(q, curr->left);
        }

        if(curr->right != NULL){
            push(q, curr->right);
        }
    }
    
}
*/

void lavel_order_traversal(tree* root){
    queue* q = init_queue();

    push(q, root);
    push(q, NULL);

    while (get_size(q) > 0)
    {
        tree* curr = fornt(q);
        pop(q);

        if(curr == NULL){
            if(!is_queue_empty(q)){
                printf("\n");
                push(q, NULL);
                continue;
            }
            else {
                break;
            }
        }

        printf("%d ", curr->data);

        if(curr->left != NULL){
            push(q, curr->left);
        }

        if(curr->right != NULL){
            push(q, curr->right);
        }
    }
    
}


int main()
{
    // int preOrder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int preOrder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    tree* root = build_tree(preOrder);

    printf("Pre-Order Traversal: ");
    pre_order_traversal(root);
    printf("\n");

    printf("Lavel-Order Traversal: \n");
    lavel_order_traversal(root);
    printf("\n");
    
    return 0;
}

/*
Output:
Pre-Order Traversal: 1 2 4 5 3 6 7 
Lavel-Order Traversal: 
1
2 3
4 5 6 7
*/
