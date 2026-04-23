#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];
int m;

// Initialize hash table
void init() {
    for (int i = 0; i < m; i++)
        table[i] = -1;  // -1 means empty
}

// Insert using quadratic probing
void insert(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
int search(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == -1)
            return 0; // stop early if empty slot found
    }

    return 0;
}

int main() {
    int q;
    scanf("%d", &m);   // size of table
    scanf("%d", &q);   // number of operations

    init();

    while (q--) {
        char op[10];
        int x;

        scanf("%s %d", op, &x);

        if (strcmp(op, "INSERT") == 0) {
            insert(x);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(x))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}