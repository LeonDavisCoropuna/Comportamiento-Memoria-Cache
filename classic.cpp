#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

// Inicializa las matrices con valores aleatorios
void initialize() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0;
        }
    }
}

// Multiplica las matrices A y B y almacena el resultado en C
void matrix_multiply() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    initialize();

    // Mide el tiempo de ejecución de la multiplicación de matrices
    start = clock();
    matrix_multiply();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for matrix multiplication: %f seconds\n", cpu_time_used);

    return 0;
}
