#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 64

double **A, **B, **C;

// Inicializa las matrices con valores aleatorios
void initialize(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0;
        }
    }
}

// Multiplica las matrices A y B usando el enfoque en bloques y almacena el resultado en C
void matrix_multiply_block(int size) {
    for (int i = 0; i < size; i += BLOCK_SIZE) {
        for (int j = 0; j < size; j += BLOCK_SIZE) {
            for (int k = 0; k < size; k += BLOCK_SIZE) {
                // Multiplicación de bloques
                for (int bi = i; bi < i + BLOCK_SIZE && bi < size; ++bi) {
                    for (int bj = j; bj < j + BLOCK_SIZE && bj < size; ++bj) {
                        double sum = 0;
                        for (int bk = k; bk < k + BLOCK_SIZE && bk < size; ++bk) {
                            sum += A[bi][bk] * B[bk][bj];
                        }
                        C[bi][bj] += sum;
                    }
                }
            }
        }
    }
}

// Función para asignar memoria para las matrices
void allocate_matrices(int size) {
    A = (double **)malloc(size * sizeof(double *));
    B = (double **)malloc(size * sizeof(double *));
    C = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        A[i] = (double *)malloc(size * sizeof(double));
        B[i] = (double *)malloc(size * sizeof(double));
        C[i] = (double *)malloc(size * sizeof(double));
    }
}

// Función para liberar la memoria de las matrices
void free_matrices(int size) {
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <matrix_size>\n", argv[0]);
        return 1;
    }

    int matrix_size = atoi(argv[1]);
    if (matrix_size <= 0) {
        fprintf(stderr, "Matrix size must be a positive integer\n");
        return 1;
    }

    // Asignar memoria para las matrices
    allocate_matrices(matrix_size);

    clock_t start, end;
    double cpu_time_used;

    initialize(matrix_size);

    // Mide el tiempo de ejecución de la multiplicación de matrices en bloque
    start = clock();
    matrix_multiply_block(matrix_size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for matrix multiplication (block size %d) of size %d: %f seconds\n", BLOCK_SIZE, matrix_size, cpu_time_used);

    // Liberar memoria
    free_matrices(matrix_size);

    return 0;
}