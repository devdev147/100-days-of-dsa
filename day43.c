#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct node {
    int data;
    struct node *left, *right;
};

// Create new node
struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for level order construction
struct queue {
    struct node** arr;
    int front, rear, size;
};

// Create queue
struct queue* createQueue(int n) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->arr = (struct node**)malloc(n * sizeof(struct node*));
    q->front = q->rear = 0;
    q->size = n;
    return q;
}

// Enqueue
void enqueue(struct queue* q, struct node* x) {
    q->arr[q->rear++] = x;
}

// Dequeue
struct node* dequeue(struct queue* q) {
    return q->arr[q->front++];
}

// Check empty
int isEmpty(struct queue* q) {
    return q->front == q->rear;
}

// Build tree from level order
struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct node* root = newNode(arr[0]);
    struct queue* q = createQueue(n);

    enqueue(q, root);

    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct node* curr = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    inorder(root);

    return 0;
}