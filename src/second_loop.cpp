#include <iostream>
#include <cstdlib>
#include <ctime>

double** A;
double* x;
double* y;

void initialize(int size) {
    A = new double*[size];
    x = new double[size];
    y = new double[size];
    
    for (int i = 0; i < size; i++) {
        x[i] = rand() % 100;
        y[i] = 0;  // y = 0
        A[i] = new double[size];
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 100;
        }
    }
}

void second_pair_of_loops(int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void cleanup(int size) {
    for (int i = 0; i < size; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] x;
    delete[] y;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <matrix_size>" << std::endl;
        return 1;
    }

    int size = std::atoi(argv[1]);

    std::clock_t start, end;
    double cpu_time_used;

    initialize(size);

    start = std::clock();
    second_pair_of_loops(size);
    end = std::clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time for the second pair of loops (size " << size << "): " << cpu_time_used << " seconds" << std::endl;

    cleanup(size);
    
    return 0;
}
