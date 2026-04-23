#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inorder[], int postorder[],
                       int postEnd, int inStart, int inEnd) {

    if (inStart > inEnd)
        return NULL;

    struct Node* root = createNode(postorder[postEnd]);

    int k = search(inorder, inStart, inEnd, root->data);

    int rightSize = inEnd - k;

    // Build right first
    root->right = buildTree(inorder, postorder,
                            postEnd - 1, k + 1, inEnd);

    root->left = buildTree(inorder, postorder,
                           postEnd - rightSize - 1, inStart, k - 1);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    struct Node* root = buildTree(inorder, postorder, n - 1, 0, n - 1);

    preorder(root);

    return 0;
}