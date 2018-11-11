/**
 * Realiza as funções para resolver o problema da pirâmede
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Heitor Passeado
 */
 #ifndef pyramid_h
 #define pyramid_h

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include "../util/fileReader.h"
 #include "../util/matrix.h"
 #include "../util/logger.h"

typedef enum Movements{
    LEFT,RIGHT
} Movements;

 void loadPyramidMatrix(int ***matrix, int *size);

 int solvePyramidRecursive(int ***matrix, int size, int i, int j, Movements *path, int *calls);

 int solvePyramidMemoization(int ***matrix, int size, int i, int j, Movements *path, int *calls);

 int pyramidMemoization(int ***matrix, int size, int i, int j, Movements *path, int ***results, int *calls);

 int solvePyramidPD(int **matrix, int size, Movements *path, int *calls);

 int pyramidPD(int **matrix, int size, Movements *path, int ***results, int *calls);

 const char* getMovementName(Movements move);

 int max(int a, int b);

 #endif
