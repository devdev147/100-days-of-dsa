#include <stdio.h>

// Check if allocation is possible with maxPages limit
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book exceeds maxPages → impossible
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return 0;
        }
    }
    return 1;
}

int findMinPages(int arr[], int n, int m) {
    if (m > n) return -1; // more students than books

    int max = arr[0], sum = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        sum += arr[i];
    }

    int left = max, right = sum, ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller maximum
        } else {
            left = mid + 1;   // increase limit
        }
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", findMinPages(arr, n, m));

    return 0;
}