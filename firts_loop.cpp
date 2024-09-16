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

    // Measure performance of the first pair of loops
    start = clock();
    first_loops();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for first loops: %f seconds\n", cpu_time_used);

    // Reset y array
    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }

    return 0;
}
