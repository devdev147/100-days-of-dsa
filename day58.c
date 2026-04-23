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

// Search element in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int preorder[], int inorder[],
                       int preStart, int inStart, int inEnd) {

    if (inStart > inEnd)
        return NULL;

    struct Node* root = createNode(preorder[preStart]);

    int k = search(inorder, inStart, inEnd, root->data);
    int leftSize = k - inStart;

    root->left = buildTree(preorder, inorder,
                           preStart + 1, inStart, k - 1);

    root->right = buildTree(preorder, inorder,
                            preStart + leftSize + 1, k + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(preorder, inorder, 0, 0, n - 1);

    postorder(root);

    return 0;
}