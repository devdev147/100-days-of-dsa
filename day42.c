#include <stdio.h>
#include <stdlib.h>

// Node structure for Queue
struct node
{
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

// Queue enqueue
void enqueue(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

// Queue dequeue
int dequeue()
{
    if (front == NULL)
        return -1;

    struct node* temp = front;
    int val = temp->data;

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

// Stack using array
struct stack
{
    int *arr;
    int top;
    int size;
};

// Initialize stack
struct stack* createStack(int n)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = n;
    s->top = -1;
    s->arr = (int*)malloc(n * sizeof(int));
    return s;
}

// Push
void push(struct stack* s, int x)
{
    s->arr[++(s->top)] = x;
}

// Pop
int pop(struct stack* s)
{
    return s->arr[(s->top)--];
}

// Reverse Queue using Stack
void reverseQueue(int n)
{
    struct stack* s = createStack(n);

    // Step 1: Dequeue all and push to stack
    while (front != NULL)
        push(s, dequeue());

    // Step 2: Pop from stack and enqueue back
    while (s->top != -1)
        enqueue(pop(s));
}

// Print Queue
void printQueue()
{
    struct node* temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main
int main()
{
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    reverseQueue(n);

    printQueue();

    return 0;
}