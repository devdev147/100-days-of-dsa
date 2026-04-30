#include <stdio.h>

// Check if we can paint with maxTime limit
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int minTime(int boards[], int n, int k) {
    int max = boards[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > max) max = boards[i];
        sum += boards[i];
    }

    int left = max, right = sum, ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller time
        } else {
            left = mid + 1;   // increase time
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d", minTime(boards, n, k));

    return 0;
}