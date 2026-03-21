#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Function to create linked list
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to rotate right by k places
struct node* rotateRight(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct node *temp = head;
    int count = 1;

    // Count nodes
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Make circular
    temp->next = head;

    // Handle k > n
    k = k % count;

    int steps = count - k;
    temp = head;

    // Move to (n-k)th node
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    head = temp->next;

    // Break circular link
    temp->next = NULL;

    return head;
}

// Function to display list
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int n, k;

    scanf("%d", &n);

    struct node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}