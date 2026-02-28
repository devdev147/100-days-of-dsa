#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node
{
    int data;
    struct node *next;
};

// Function to create linked list
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

// Function to delete first occurrence of key
struct node* deleteKey(struct node *head, int key)
{
    struct node *temp = head, *prev = NULL;

    // If head node itself holds the key
    if(temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for key
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if(temp == NULL)
        return head;

    // Unlink node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Function to print list
void printList(struct node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, key;

    scanf("%d", &n);
    struct node *head = createList(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}