#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    // Initialize with large value (INF)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = INT_MAX;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected
    }

    int visited[MAX] = {0};
    visited[1] = 1;

    int totalWeight = 0;

    // MST will have n-1 edges
    for (int count = 1; count < n; count++) {
        int min = INT_MAX;
        int x = -1, y = -1;

        // Find minimum edge
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && adj[i][j] < min) {
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            totalWeight += min;
            visited[y] = 1;
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}