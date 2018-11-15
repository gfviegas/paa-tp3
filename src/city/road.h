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

#include "../util/boolean.h"
#include "../util/fileReader.h"
#include "../util/matrix.h"
#include "../util/logger.h"
#include "construction.h"
#include "direction.h"

/**
* A partir de um arquivo de descrição do problema que o usuário fornece, cria e preenche a matriz com seus dados
* @param matrix        Ponteiro para a matriz de inteiros a ser criada
* @param linesAmount   Ponteiro da quantidade de linhas da matriz
* @param columnsAmount Ponteiro da quantidade de colunas da matriz
*/
void loadRoadMatrix(int ***matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer *constructionsList);

boolean solve(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList);

void printSolutionPath(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList);

void printCity(int ***matrix, int linesAmount, int columnsAmount, char* header, ConstructionPointer constructionsList, boolean printPath);
#endif /* road_h */
