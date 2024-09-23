cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(MatrixMultiplication)

# Habilitar compilación con C++11
set(CMAKE_CXX_STANDARD 11)

# Establecer opciones de compilación
if(CMAKE_BUILD_TYPE MATCHES Debug)
    # Compilación en modo depuración
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
else()
    # Compilación en modo de liberación con optimizaciones
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()

# Agregar el archivo fuente
add_executable(classic_matrix_multiply src/classic.cpp)
add_executable(block_matrix_multiply src/block.cpp)
add_executable(first_loop src/first_loop.cpp)
add_executable(second_loop src/second_loop.cpp)