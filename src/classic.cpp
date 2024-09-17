#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para inicializar matrices de tamaño N con valores aleatorios
void initialize(double **A, double **B, double **C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0;
        }
    }
}

// Función para multiplicar las matrices A y B de tamaño N y almacenar el resultado en C
void matrix_multiply(double **A, double **B, double **C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <matrix size>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("Matrix size must be a positive integer.\n");
        return 1;
    }

    // Asignar memoria dinámicamente para las matrices
    double **A = (double **)malloc(N * sizeof(double *));
    double **B = (double **)malloc(N * sizeof(double *));
    double **C = (double **)malloc(N * sizeof(double *));
    
    for (int i = 0; i < N; i++) {
        A[i] = (double *)malloc(N * sizeof(double));
        B[i] = (double *)malloc(N * sizeof(double));
        C[i] = (double *)malloc(N * sizeof(double));
    }

    clock_t start, end;
    double cpu_time_used;

    // Inicializar matrices
    initialize(A, B, C, N);

    // Medir el tiempo de la multiplicación de matrices
    start = clock();
    matrix_multiply(A, B, C, N);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for matrix multiplication of size %d: %f seconds\n", N, cpu_time_used);

    // Liberar memoria asignada
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}