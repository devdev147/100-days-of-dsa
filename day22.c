#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, value, count = 0;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Count nodes
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Print count
    printf("%d", count);

    return 0;
}