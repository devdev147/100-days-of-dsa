#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int coeff;
    int exp;
    struct node* next;
};

// Create polynomial linked list
struct node* createPoly(int n) {
    struct node *head = NULL, *tail = NULL, *temp;
    int c, e;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);

        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = c;
        temp->exp = e;
        temp->next = NULL;

        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

// Display polynomial
void displayPoly(struct node* head) {
    struct node* temp = head;

    while (temp != NULL) {
        // Print coefficient
        printf("%d", temp->coeff);

        // Print exponent part
        if (temp->exp > 1)
            printf("x^%d", temp->exp);
        else if (temp->exp == 1)
            printf("x");

        // Print + if not last node
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct node* poly = createPoly(n);

    displayPoly(poly);

    return 0;
}