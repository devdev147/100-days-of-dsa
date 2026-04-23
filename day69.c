#include <stdio.h>
#include <limits.h>

#define MAX 100

// Structure for heap node
struct Node {
    int vertex;
    int dist;
};

// Min Heap
struct Node heap[MAX];
int size = 0;

// Swap
void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

// Pop min
struct Node pop() {
    struct Node root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int isEmpty() {
    return size == 0;
}

// Dijkstra
void dijkstra(int V, int adj[MAX][MAX], int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        struct Node curr = pop();
        int u = curr.vertex;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] > 0) { // edge exists
                int weight = adj[u][v];

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    push(v, dist[v]);
                }
            }
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {
    int V = 5;
    int adj[MAX][MAX] = {0};

    // Example graph
    adj[0][1] = 10;
    adj[0][4] = 5;
    adj[1][2] = 1;
    adj[1][4] = 2;
    adj[2][3] = 4;
    adj[3][0] = 7;
    adj[3][2] = 6;
    adj[4][1] = 3;
    adj[4][2] = 9;
    adj[4][3] = 2;

    dijkstra(V, adj, 0);

    return 0;
}