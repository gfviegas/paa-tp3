/**
 * Gerencia e chama as funções relacionadas ao problema de "Obras na Estrada"
 * manipulando estruturas de dados, utilizando de Programação Dinâmica
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */
#ifndef road_h
#define road_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/fileReader.h"
#include "../util/matrix.h"
#include "../util/logger.h"

/**
* Direções disponíveis para percorrer a cidade.
*/
typedef enum Direction {
 NONE, // Nenhuma
 EAST, // Leste
 NORTH, // Norte
} Direction;

typedef struct Coordinates* CoordinatesPointer;
typedef struct Coordinates {
	int x;
	int y;
} Coordinates;

/**
* A partir de um arquivo de descrição do problema que o usuário fornece, cria e preenche a matriz com seus dados
* @param matrix        Ponteiro para a matriz de inteiros a ser criada
* @param linesAmount   Ponteiro da quantidade de linhas da matriz
* @param columnsAmount Ponteiro da quantidade de colunas da matriz
*/
void loadRoadMatrix(int ***matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination);


#endif /* road_h */
