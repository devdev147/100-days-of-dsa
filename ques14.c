#include <stdio.h>

int main() {
    int n;
    int a[100][100];
    int isIdentity = 1;

    scanf("%d", &n);

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check identity condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) {
                if (a[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if (a[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if (isIdentity == 0)
            break;
    }

    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
