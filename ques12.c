#include <stdio.h>

int main() {
    int m, n;
    int a[100][100];
    int i, j;
    int symmetric = 1;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // If not square, directly not symmetric
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Input matrix elements
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check symmetric condition
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (symmetric == 0)
            break;
    }

    if (symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
