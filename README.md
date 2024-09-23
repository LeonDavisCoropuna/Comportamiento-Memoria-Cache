# Comportamiento de Memoria Cache

Este proyecto evalúa el comportamiento de la memoria caché de dos algoritmos de multiplicación de matrices: el clásico y el basado en bloques, así como el impacto de diferentes estructuras de bucles en el rendimiento. El análisis se realiza utilizando herramientas de medición de caché y se documenta a través de los resultados obtenidos.

## Objetivos del Proyecto

El objetivo principal de este proyecto es comparar el rendimiento de dos enfoques de multiplicación de matrices, destacando cómo la implementación por bloques mejora el acceso a la memoria caché en comparación con el método clásico. También se evalúa el rendimiento de diferentes bucles anidados para comprender mejor su influencia en la eficiencia de la ejecución.

## Metodología

1. **Definición de Algoritmos**: Se implementaron los algoritmos de multiplicación de matrices clásico y por bloques, así como dos estructuras de bucles anidados para el análisis.
   
2. **Configuración del Entorno**: Se utilizó CMake para la gestión del proyecto y un script de shell (`run.sh`) para automatizar la compilación y la ejecución de las pruebas.

3. **Ejecutar Pruebas con Diferentes Tamaños de Matrices**: Se realizaron experimentos variando los tamaños de las matrices y los arrays, desde tamaños pequeños hasta grandes, para evaluar el rendimiento de los algoritmos bajo diferentes cargas de trabajo.

4. **Análisis del Uso de la Memoria Caché**: Se empleó Valgrind con la herramienta Cachegrind para medir el uso de la memoria caché durante la ejecución de los algoritmos.

5. **Visualización de Resultados**: KCachegrind se utilizó para visualizar los resultados del análisis de caché, facilitando el entendimiento de la memoria utilizada y el tiempo invertido en los accesos a la misma.

## Requisitos

Antes de comenzar, asegúrate de tener los siguientes requisitos instalados:
- **CMake**: Para generar archivos de construcción.
- **GCC**: Para compilar el código en C++.
- **Valgrind**: Para analizar el uso de la memoria caché.
- **KCachegrind**: Para visualizar los resultados del análisis de caché.

## Instrucciones de Ejecución

1. **Clona el repositorio**

   Primero, clona el repositorio desde GitHub. Abre una terminal y ejecuta el siguiente comando:

   ```bash
   git clone https://github.com/LeonDavisCoropuna/Comportamiento-Memoria-Cache.git
   ```

   Luego, navega al directorio del proyecto:

   ```bash
   cd Comportamiento-Memoria-Cache
   ```

2. **Ejecuta el script `run.sh`**

   El script `run.sh` compilará el proyecto (si no se ha hecho ya) y ejecutará las pruebas para diferentes tamaños de matrices y arrays. Asegúrate de que el script tenga permisos de ejecución y luego ejecútalo:

   ```bash
   chmod +x run.sh
   ./run.sh
   ```

   El script generará dos tipos de resultados:
   - **Tiempos de Ejecución**: Se guardarán en `results/tiempos`.
   - **Análisis de Caché**: Se guardarán en `results/cache`.

3. **Cambiar tamaños de matrices y arrays**

   Si deseas cambiar los tamaños de las matrices o arrays utilizados en las pruebas, puedes modificar las siguientes variables en el script `run.sh`:

   - Para tamaños de matrices (usado en los algoritmos de multiplicación de matrices), edita la lista `MATRIX_SIZES`:
     ```bash
     MATRIX_SIZES=(100 300 700 1000 1500 2000)
     ```

   - Para tamaños de arrays (usado en los bucles), edita la lista `LOOP_SIZES`:
     ```bash
     LOOP_SIZES=(100 500 1000 5000 10000 20000)
     ```

   Una vez editados, guarda el archivo y vuelve a ejecutar el script para probar los nuevos tamaños.

4. **Visualiza los resultados**

   Los resultados del análisis de caché se pueden visualizar usando KCachegrind. Para abrir el archivo de salida generado por Valgrind, usa el siguiente comando:

   ```bash
   kcachegrind results/cache/cache_<size>.out
   ```

   Reemplaza `<size>` con el tamaño de la matriz correspondiente.

## Archivos del Proyecto

- **`src/classic.cpp`**: Implementación del algoritmo de multiplicación de matrices clásico.
- **`src/block.cpp`**: Implementación del algoritmo de multiplicación de matrices en bloque.
- **`src/first_loop.cpp`**: Implementación del primer bucle anidado.
- **`src/second_loop.cpp`**: Implementación del segundo bucle anidado.
- **`CMakeLists.txt`**: Archivo de configuración de CMake.
- **`run.sh`**: Script para compilar y ejecutar los programas de prueba.

## Contribuciones

Si deseas contribuir a este proyecto, por favor, realiza un fork del repositorio, haz tus cambios y envía un pull request con tus contribuciones.

## Contacto

Para cualquier consulta, puedes contactar a Leon Davis a través de [GitHub](https://github.com/LeonDavisCoropuna).