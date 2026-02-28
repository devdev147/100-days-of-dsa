#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node
{
    int data;
    struct node *next;
};

// Create linked list
struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int i, value;

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
    return head;
}

// Get length of list
int getLength(struct node *head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection by value comparison
int findIntersection(struct node *head1, struct node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if(len1 > len2)
    {
        while(diff--)
            head1 = head1->next;
    }
    else
    {
        while(diff--)
            head2 = head2->next;
    }

    // Traverse together
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data == head2->data)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1; // No intersection
}

int main()
{
    int n, m, result;

    scanf("%d", &n);
    struct node *head1 = createList(n);

    scanf("%d", &m);
    struct node *head2 = createList(m);

    result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}