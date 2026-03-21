#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node* next;
};

// Front and Rear pointers
struct node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) // empty queue
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

// Dequeue operation
int dequeue()
{
    if (front == NULL)
        return -1;

    struct node* temp = front;
    int val = temp->data;

    front = front->next;

    if (front == NULL) // queue becomes empty
        rear = NULL;

    free(temp);
    return val;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int type;
        scanf("%d", &type);

        if (type == 1)
        {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if (type == 2)
        {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}