#include <stdio.h>

int main() {
    int m, n;
    int a[100][100];
    int sum = 0;

    scanf("%d %d", &m, &n);

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Sum of primary diagonal
    for (int i = 0; i < m && i < n; i++) {
        sum += a[i][i];
    }

    printf("%d", sum);

    return 0;
}
