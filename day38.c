#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;
int sz = 0;

// push_front
void push_front(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = front;

    if (front == NULL) {
        front = rear = temp;
    } else {
        front->prev = temp;
        front = temp;
    }
    sz++;
}

// push_back
void push_back(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = rear;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    sz++;
}

// pop_front
void pop_front() {
    if (front == NULL) return;

    struct node* temp = front;
    front = front->next;

    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
    sz--;
}

// pop_back
void pop_back() {
    if (rear == NULL) return;

    struct node* temp = rear;
    rear = rear->prev;

    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
    sz--;
}

// front element
int get_front() {
    if (front == NULL) return -1;
    return front->data;
}

// back element
int get_back() {
    if (rear == NULL) return -1;
    return rear->data;
}

// empty
int empty() {
    return front == NULL;
}

// size
int size() {
    return sz;
}

// clear
void clear() {
    while (front != NULL) {
        pop_front();
    }
}

// display
void display() {
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// reverse
void reverse() {
    struct node* temp = NULL;
    struct node* curr = front;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        front = temp->prev;
}

// Main (sample driver)
int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    display();   // 5 10 20

    pop_front();
    display();   // 10 20

    pop_back();
    display();   // 10

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    return 0;
}