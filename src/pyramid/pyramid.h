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

 /**
  * Lê de um arquivo e carrega uma matriz no modelo do problema de pirâmede
  * @param matrix Matriz que armazanará
  * @param size Variável que receberá o tamanho da matriz lida
  */
 void loadPyramidMatrix(int ***matrix, int *size);

 /**
  * Função que encapsula variáveis que são usadas na pyramidRecursive e exibe os resultados
  * @param matrix       Matriz a ser resolvida
  * @param size         Tamanho da matriz
  * @param analysisMode Se está ou não no modo análise
  */
 void solvePyramidRecursive(int ***matrix, int size, int analysisMode);
/**
 * Função que resolve o problema das pirâmides por recursão básica
 * @param  matrix Matriz a ser resolvida
 * @param  size   Tamanho da matriz
 * @param  i      índice das linhas(começa no 0)
 * @param  j      índice das colunas(começa no 0)
 * @param  path   Vetor com os caminhos percorridos: esquerda ou direita
 * @param  calls  Quantas chamadas foram feitas
 * @return        Valor do caminho máximo
 */
 int pyramidRecursive(int ***matrix, int size, int i, int j, Movements *path, int *calls);

 /**
 * Encapsula variáveis da pyramidMemoization e exibe os resultados
 * @param matrix       Matriz a ser resolvida
 * @param size         Tamanho da matriz
 * @param analysisMode Se está ou não no modo análise
 */
 void solvePyramidMemoization(int ***matrix, int size, int analysisMode);

 /**
  * Resolve o problema das pirâmedes com recursão e memoization, exibe os resultados
  * @param  matrix  Matriz que contém os resultados
  * @param  size    Tamanho da matriz
  * @param  i       Índice das linhas(começa com 0_)
  * @param  j       [description]
  * @param  path    [description]
  * @param  results [description]
  * @param  calls   [description]
  * @return         [description]
  */
 int pyramidMemoization(int ***matrix, int size, int i, int j, Movements *path, int ***results, int *calls);

void solvePyramidPD(int ***matrix, int size, int analysisMode);

 int pyramidPD(int **matrix, int size, Movements *path, int ***results, int *calls);

 const char* getMovementName(Movements move);

 int max(int a, int b, int *winner);

 #endif
