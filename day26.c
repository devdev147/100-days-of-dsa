#include <stdio.h>
#include <stdlib.h>

// Structure of doubly linked list node
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    int n, i, value;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Create doubly linked list
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    // Traverse in forward direction
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}