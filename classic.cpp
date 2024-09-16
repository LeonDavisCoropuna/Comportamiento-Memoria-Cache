#include <iostream>
#include <chrono> // Para medir el tiempo de ejecución

const int MAX = 1024; // Tamaño de la matriz, puedes ajustarlo
const int BLOCK_SIZE = 64; // Tamaño del bloque, ajustable según el tamaño de caché

// Función para multiplicar dos matrices usando la técnica de bloques
void block_matrix_multiplication(double A[MAX][MAX], double B[MAX][MAX], double C[MAX][MAX]) {
    for (int i = 0; i < MAX; i += BLOCK_SIZE) {
        for (int j = 0; j < MAX; j += BLOCK_SIZE) {
            for (int k = 0; k < MAX; k += BLOCK_SIZE) {
                for (int i1 = i; i1 < std::min(i + BLOCK_SIZE, MAX); ++i1) {
                    for (int j1 = j; j1 < std::min(j + BLOCK_SIZE, MAX); ++j1) {
                        double sum = 0.0;
                        for (int k1 = k; k1 < std::min(k + BLOCK_SIZE, MAX); ++k1) {
                            sum += A[i1][k1] * B[k1][j1];
                        }
                        C[i1][j1] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    // Inicialización de las matrices A y B con valores arbitrarios (por ejemplo, 1.0)
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    block_matrix_multiplication(A, B, C);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo de ejecución (bloques): " << duration.count() << " segundos\n";

    return 0;
}
