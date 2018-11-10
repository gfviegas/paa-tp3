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

#endif /* road_h */


// L = 3
// C = 3
// (1,1) = (L-1, 0) = (2, 0)
// (L,C) = (0, C-1) = (0, 2)
//
//
// (X,Y) = [Y, X]
//
// _____________________
// | [0,0] [0,1] [0,2] |
// | [1,0] [1,1] [1,2] |
// | [2,0] [2,1] [2,2] |
// _____________________
//
// _____________________
// | (1,3) (2,3) (3,3) |
// | (1,2) (2,2) (3,2) |
// | (1,1) (2,1) (3,1) |
// _____________________
