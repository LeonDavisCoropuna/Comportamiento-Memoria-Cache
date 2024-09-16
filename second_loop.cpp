#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

double A[MAX][MAX], x[MAX], y[MAX];

void initialize() {
    for (int i = 0; i < MAX; i++) {
        x[i] = rand() % 100;
        y[i] = 0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = rand() % 100;
        }
    }
}

void first_loops() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void second_loops() {
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    initialize();

    // Measure performance of the second pair of loops
    start = clock();
    second_loops();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for second loops: %f seconds\n", cpu_time_used);

    return 0;
}
