#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
typedef struct Node {
    float val;
    struct Node* next;
} Node;

// Insert in sorted order (insertion sort inside bucket)
void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->val >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL && curr->next->val < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    Node* buckets[n];

    // Initialize buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        insertSorted(&buckets[idx], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->val;
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}