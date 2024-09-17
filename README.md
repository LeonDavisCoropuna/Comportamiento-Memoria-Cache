# Comportamiento de Memoria Cache

Este proyecto evalúa el comportamiento de la memoria caché de dos algoritmos de multiplicación de matrices: el clásico y el basado en bloques. El proyecto utiliza CMake para la configuración del proyecto y un script de shell (`run.sh`) para ejecutar las pruebas.

## Requisitos

Antes de comenzar, asegúrate de tener los siguientes requisitos instalados:
- **CMake**: Para generar archivos de construcción.
- **GCC**: Para compilar el código en C.
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

   El script `run.sh` compilará el proyecto (si no se ha hecho ya) y ejecutará las pruebas para diferentes tamaños de matrices. Asegúrate de que el script tenga permisos de ejecución y luego ejecútalo:

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
     MATRIX_SIZES=(100 300 400)
     ```
     Puedes agregar o modificar los tamaños que desees probar.

   - Para tamaños de arrays (usado en los bucles), edita la lista `LOOP_SIZES`:
     ```bash
     LOOP_SIZES=(100 500 1000)
     ```
     Aquí también puedes agregar o modificar los tamaños a probar.

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
- **`src/first_loop.cpp`**: Implementación del primer bucle.
- **`src/second_loop.cpp`**: Implementación del segundo bucle.
- **`CMakeLists.txt`**: Archivo de configuración de CMake.
- **`run.sh`**: Script para compilar y ejecutar los programas de prueba.

## Contribuciones

Si deseas contribuir a este proyecto, por favor, realiza un fork del repositorio, haz tus cambios y envía un pull request con tus contribuciones.

## Contacto

Para cualquier consulta, puedes contactar a Leon Davis a través de [GitHub](https://github.com/LeonDavisCoropuna).