#include <stdio.h>

#define MAX 1000

// Simple hash using arrays (since constraints are small)
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = 8;

    int prefixSum = 0;
    int maxLen = 0;

    // To store prefix sums and their first index
    int sum[MAX];
    int index[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0 from start
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Check if prefixSum seen before
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (sum[j] == prefixSum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int len = i - index[found];
            if (len > maxLen)
                maxLen = len;
        } else {
            sum[size] = prefixSum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);
    return 0;
}