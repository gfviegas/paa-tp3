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
/**
 * Resolve o caminho de uma cidade
 * @param  matrix            Matriz contendo a cidade
 * @param  linesAmount       Quantidade de linhas que a matriz contém
 * @param  columnsAmount     Quantidade de colunas que a matriz contém
 * @param  origin            Coordenadas da origem
 * @param  destination       Coordenadas do desetino
 * @param  constructionsList Lista contendo as contruções que a cidade possui
 * @return                   Booleano representando se foi encontrado uma solução
 */
boolean solve(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList);

/**
 * Exibe a cidade com o caminho solução
 * @param matrix            Matriz contendo a cidade
 * @param linesAmount       Tamanho de linhas da cidade
 * @param columnsAmount     Tamanho de colunas da cidade
 * @param origin            Coordenadas do ponto de origem
 * @param destination       Coordenadas do ponto de destino
 * @param constructionsList Lista de construções da cidade
 */
void printSolutionPath(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList);
/**
 * Exibe a cidade
 * @param matrix            [description]
 * @param linesAmount       [description]
 * @param columnsAmount     [description]
 * @param header            [description]
 * @param constructionsList [description]
 * @param printPath         [description]
 */
void printCity(int ***matrix, int linesAmount, int columnsAmount, char* header, ConstructionPointer constructionsList, boolean printPath);
#endif /* road_h */
