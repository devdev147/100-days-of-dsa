#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting intervals by start time
int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

// Min Heap functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Push into heap
void push(int heap[], int* size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

// Pop min (root)
int pop(int heap[], int* size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

// Get min (root)
int top(int heap[]) {
    return heap[0];
}

// Main function
int minMeetingRooms(int** intervals, int intervalsSize) {
    if (intervalsSize == 0) return 0;

    // Sort intervals
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int heap[intervalsSize];
    int size = 0;

    // Add first meeting
    push(heap, &size, intervals[0][1]);

    for (int i = 1; i < intervalsSize; i++) {
        // If room is free
        if (intervals[i][0] >= top(heap)) {
            pop(heap, &size);
        }

        // Allocate room (push end time)
        push(heap, &size, intervals[i][1]);
    }

    return size;
}