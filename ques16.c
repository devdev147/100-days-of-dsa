#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    int count = 1;

    for (int i = 0; i < n; i++) {
        if (i < n-1 && arr[i] == arr[i+1]) {
            count++;
        } else {
            printf("%d:%d ", arr[i], count);
            count = 1;
        }
    }

    return 0;
}
