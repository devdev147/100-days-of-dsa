#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix_sum = 0;
    int count = 0;

    // Simple large range for prefix sums
    // (For competitive coding, use hashmap)
    int size = 200001;
    int offset = 100000;

    int *freq = (int*)calloc(size, sizeof(int));

    freq[offset] = 1;   // prefix sum 0 initially exists

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        count += freq[prefix_sum + offset];
        freq[prefix_sum + offset]++;
    }

    printf("%d", count);

    free(freq);
    return 0;
}