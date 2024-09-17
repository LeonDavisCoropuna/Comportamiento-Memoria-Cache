#!/bin/bash

# Carpetas para almacenar resultados
CACHE_DIR="results/cache"
TIEMPOS_DIR="results/tiempos"
BUILD_DIR="build"
CLASSIC_EXECUTABLE="$BUILD_DIR/classic_matrix_multiply"
BLOCK_EXECUTABLE="$BUILD_DIR/block_matrix_multiply"
FIRST_LOOP_EXECUTABLE="$BUILD_DIR/first_loop"
SECOND_LOOP_EXECUTABLE="$BUILD_DIR/second_loop"

# Crear directorios si no existen
mkdir -p $CACHE_DIR
mkdir -p $TIEMPOS_DIR
mkdir -p $BUILD_DIR

# Crear el directorio build y compilar el programa
echo "Compilando el programa..."
cd $BUILD_DIR
cmake .. && make

# Regresar al directorio raíz
cd ..

# Tamaños de matrices a probar
MATRIX_SIZES=(100 300 400)
LOOP_SIZES=(100 500 1000 5000 10000)

# Ejecutar el algoritmo clásico para diferentes tamaños de matrices
for size in "${MATRIX_SIZES[@]}"; do
    echo "Ejecutando matriz de tamaño $size con el algoritmo clásico..."

    # Almacenar tiempos de ejecución
    TIME_OUTPUT="$TIEMPOS_DIR/classic_time_$size.txt"
    $CLASSIC_EXECUTABLE $size > $TIME_OUTPUT
    echo "Resultados de tiempo (clásico) almacenados en $TIME_OUTPUT"

    # Almacenar uso de caché
    CACHE_OUTPUT="$CACHE_DIR/classic_cache_$size.out"
    valgrind --tool=cachegrind --cachegrind-out-file=$CACHE_OUTPUT $CLASSIC_EXECUTABLE $size
    echo "Resultados de caché (clásico) almacenados en $CACHE_OUTPUT"
done

# Ejecutar el algoritmo en bloque para diferentes tamaños de matrices
for size in "${MATRIX_SIZES[@]}"; do
    echo "Ejecutando matriz de tamaño $size con el algoritmo en bloque..."

    # Almacenar tiempos de ejecución
    TIME_OUTPUT="$TIEMPOS_DIR/block_time_$size.txt"
    $BLOCK_EXECUTABLE $size > $TIME_OUTPUT
    echo "Resultados de tiempo (bloque) almacenados en $TIME_OUTPUT"

    # Almacenar uso de caché
    CACHE_OUTPUT="$CACHE_DIR/block_cache_$size.out"
    valgrind --tool=cachegrind --cachegrind-out-file=$CACHE_OUTPUT $BLOCK_EXECUTABLE $size
    echo "Resultados de caché (bloque) almacenados en $CACHE_OUTPUT"
done

# Ejecutar el algoritmo del primer bucle para diferentes tamaños de array
for size in "${LOOP_SIZES[@]}"; do
    echo "Ejecutando matriz de tamaño $size con el primer bucle..."

    # Almacenar tiempos de ejecución
    TIME_OUTPUT="$TIEMPOS_DIR/first_loop_time_$size.txt"
    $FIRST_LOOP_EXECUTABLE $size > $TIME_OUTPUT
    echo "Resultados de tiempo (primer bucle) almacenados en $TIME_OUTPUT"

    # Almacenar uso de caché
    CACHE_OUTPUT="$CACHE_DIR/first_loop_cache_$size.out"
    valgrind --tool=cachegrind --cachegrind-out-file=$CACHE_OUTPUT $FIRST_LOOP_EXECUTABLE $size
    echo "Resultados de caché (primer bucle) almacenados en $CACHE_OUTPUT"
done

# Ejecutar el algoritmo del segundo bucle para diferentes tamaños de array
for size in "${LOOP_SIZES[@]}"; do
    echo "Ejecutando matriz de tamaño $size con el segundo bucle..."

    # Almacenar tiempos de ejecución
    TIME_OUTPUT="$TIEMPOS_DIR/second_loop_time_$size.txt"
    $SECOND_LOOP_EXECUTABLE $size > $TIME_OUTPUT
    echo "Resultados de tiempo (segundo bucle) almacenados en $TIME_OUTPUT"

    # Almacenar uso de caché
    CACHE_OUTPUT="$CACHE_DIR/second_loop_cache_$size.out"
    valgrind --tool=cachegrind --cachegrind-out-file=$CACHE_OUTPUT $SECOND_LOOP_EXECUTABLE $size
    echo "Resultados de caché (segundo bucle) almacenados en $CACHE_OUTPUT"
done

echo "Ejecuciones completadas."
