#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert()
{
    int value;
    struct node *newnode, *temp;

    printf("Enter value: ");
    scanf("%d", &value);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    printf("Node inserted successfully!\n");
}

// Delete a node by value
void deleteNode()
{
    int key;
    struct node *temp = head, *prev = NULL;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    // If head node holds the key
    if(head->data == key)
    {
        // Only one node
        if(head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *last = head;
            while(last->next != head)
            {
                last = last->next;
            }

            last->next = head->next;
            temp = head;
            head = head->next;
            free(temp);
        }

        printf("Node deleted successfully!\n");
        return;
    }

    prev = head;
    temp = head->next;

    while(temp != head && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == head)
    {
        printf("Value not found!\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted successfully!\n");
    }
}

// Display circular list
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: deleteNode();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}