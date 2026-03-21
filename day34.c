#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push
void push(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

// Evaluate postfix
int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {
        // If operand
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        // Operator
        else {
            int a = pop();
            int b = pop();

            int result;

            switch (token[0]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

// Main
int main() {
    char expr[100];

    // Read full line input
    fgets(expr, sizeof(expr), stdin);

    // Remove newline
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluatePostfix(expr);

    printf("%d\n", result);

    return 0;
}