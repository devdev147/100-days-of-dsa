#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, value;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Read n values and create linked list
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        // Allocate memory for new node
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;   // First node
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Traverse and print linked list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}