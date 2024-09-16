## Primera Implementacion (Two - Loops) 
La diferencia en el tiempo de ejecución entre los dos bloques de código (`first_loops` y `second_loops`) se debe a cómo se accede a la memoria, lo que tiene un impacto significativo en el rendimiento debido a la forma en que funciona la caché del procesador.

### Explicación del Rendimiento Inferior en `second_loops`

#### Acceso a la Memoria y Localidad Espacial

1. **Orden de Acceso a la Memoria**:
   - **`first_loops`**: 
     ```c
     void first_loops() {
         for (int i = 0; i < MAX; i++) {
             for (int j = 0; j < MAX; j++) {
                 y[i] += A[i][j] * x[j];
             }
         }
     }
     ```
     Aquí, `y[i]` se accede de manera secuencial a lo largo de la iteración sobre `i`, y `A[i][j]` se accede de manera secuencial a lo largo de `j`. Debido a que las matrices en C se almacenan en orden de fila (row-major order), `A[i][j]` está en la misma fila de memoria consecutivamente. Esto significa que, a medida que avanzas en `j`, los accesos a `A[i][j]` están contiguos en la memoria, lo que resulta en una buena localidad espacial y una alta probabilidad de que los datos estén en caché.

   - **`second_loops`**:
     ```c
     void second_loops() {
         for (int j = 0; j < MAX; j++) {
             for (int i = 0; i < MAX; i++) {
                 y[i] += A[i][j] * x[j];
             }
         }
     }
     ```
     En este caso, `A[i][j]` se accede de manera que `j` cambia más rápidamente que `i`. Como `A` está almacenada en orden de fila, acceder a `A[i][j]` con `j` cambiando primero causa que el acceso a la memoria no sea secuencial en la mayoría de los casos. Esto resulta en muchos fallos de caché, ya que cada nuevo acceso a `A[i][j]` puede estar en una ubicación de memoria diferente y no necesariamente cercana al anterior.

#### Impacto en la Caché del Procesador

- **Localidad Temporal y Espacial**:
  - **Localidad Espacial**: En `first_loops`, los accesos a `A[i][j]` están en direcciones de memoria contiguas, lo que permite que los datos sean cargados en la caché y reutilizados eficientemente. En `second_loops`, la falta de contigüidad en los accesos a `A[i][j]` resulta en un bajo rendimiento de caché.
  - **Localidad Temporal**: La localidad temporal se refiere a la reutilización de los mismos datos en un corto período de tiempo. En `first_loops`, `y[i]` se accede repetidamente mientras `j` varía, lo que favorece la localidad temporal. En `second_loops`, cada `y[i]` se actualiza menos frecuentemente durante la iteración sobre `j`.

- **Caché Misses**:
  - **`first_loops`**: Accede a datos en la caché con una alta probabilidad de que los datos sean consecutivos en la memoria, reduciendo el número de fallos de caché.
  - **`second_loops`**: Puede resultar en muchos fallos de caché debido al acceso no contiguo a `A[i][j]`, lo que provoca que se tenga que cargar constantemente nuevas ubicaciones de memoria en la caché.

El algoritmo `first_loops` es más rápido porque accede a la memoria de una manera que maximiza la eficiencia de la caché del procesador. Al iterar a través de `i` y `j` en el orden de fila, se aprovecha la contigüidad de la memoria en la que se almacenan los datos. En contraste, `second_loops` no aprovecha la contigüidad de la memoria debido al orden en el que se accede a los datos, lo que resulta en un mayor número de fallos de caché y, por ende, un peor rendimiento.