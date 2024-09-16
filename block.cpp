#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define BLOCK_SIZE 32 

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

// Multiplica las matrices A y B usando la técnica de bloques y almacena el resultado en C
void matrix_multiply_block() {
    for (int i = 0; i < MAX; i += BLOCK_SIZE) {
        for (int j = 0; j < MAX; j += BLOCK_SIZE) {
            for (int k = 0; k < MAX; k += BLOCK_SIZE) {
                // Multiplicación de bloques
                for (int ii = i; ii < i + BLOCK_SIZE && ii < MAX; ++ii) {
                    for (int jj = j; jj < j + BLOCK_SIZE && jj < MAX; ++jj) {
                        double sum = 0.0;
                        for (int kk = k; kk < k + BLOCK_SIZE && kk < MAX; ++kk) {
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        C[ii][jj] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    initialize();

    start = clock();
    matrix_multiply_block();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for matrix multiplication with blocking: %f seconds\n", cpu_time_used);

    return 0;
}
