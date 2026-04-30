#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

// Sort by position descending
int compare(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int* speed, int n) {
    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        // If this car forms a new fleet
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    printf("%d", carFleet(target, position, speed, n)); // Output: 3
    return 0;
}