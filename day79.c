#include <stdio.h>
#include <limits.h>

#define MAX 100

// Min heap node
struct Node {
    int v, dist;
};

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
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push
void push(int v, int d) {
    heap[size].v = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

// Pop
struct Node pop() {
    struct Node root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int isEmpty() {
    return size == 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    // Initialize
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove if graph is directed
    }

    int src;
    scanf("%d", &src);

    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        struct Node cur = pop();
        int u = cur.v;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] > 0) {
                int w = adj[u][v];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    push(v, dist[v]);
                }
            }
        }
    }

    // Output distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}