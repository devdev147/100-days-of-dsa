#include <stdio.h>
#include <stdlib.h>

// Merge and count inversions
long long merge(int arr[], int left, int mid, int right) {
    int n = right - left + 1;
    int* temp = (int*)malloc(n * sizeof(int));

    int i = left, j = mid + 1, k = 0;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // KEY LINE
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = 0; i < n; i++) {
        arr[left + i] = temp[i];
    }

    free(temp);
    return invCount;
}

// Merge sort with inversion count
long long mergeSort(int arr[], int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;

    long long count = 0;
    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long result = mergeSort(arr, 0, n - 1);

    printf("%lld", result);

    return 0;
}