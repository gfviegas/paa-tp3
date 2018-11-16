#ifndef construction_h
#define construction_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/logger.h"
#include "../util/boolean.h"
#include "direction.h"

typedef struct Construction* ConstructionPointer;
typedef struct Construction {
	boolean active;
	Coordinates position;
	Direction direction;
	ConstructionPointer next;
} Construction;

/**
 * Verifica se uma construção é vazia
 * @param  construction
 * @return boolean representando se ela é ou não vazia
 */
boolean isConstructionEmpty(ConstructionPointer construction);
/**
 * Aloca espaço para uma construção
 * @param  position  Posição que ela possuiŕa
 * @param  direction Direção que ela teŕa
 * @return           Construção criada
 */
ConstructionPointer createConstruction(Coordinates position, Direction direction);

/**
 * Adiciona uma construção na Lista
 * @param  constructionsList Lista de construções
 * @param  position          Posição que ela conterá
 * @param  direction         Direção que ela terá
 * @return                   Boolean representando se ela foi ou não adicionada
 */
boolean addConstruction(ConstructionPointer *constructionsList, Coordinates position, Direction direction);

<<<<<<< HEAD
/**
 * Checa se uma determinada construção está na Lista
 * @param  constructionsList Lista de construções a ser verificada
 * @param  position          Posição da construção a ser verificada
 * @param  direction         Direção da construção a ser verificada
 * @return                   Boolean representando se ela foi ou não encontrada
 */
=======
void clearConstructionList(ConstructionPointer *constructionsList);

>>>>>>> d621461a5a8bba4ca25c3a12e902e37a5f343697
boolean checkConstruction(ConstructionPointer constructionsList, Coordinates position, Direction direction);
/**
 * Exibe construção, se ela é ativa, sua posição, direção e código
 * @param construction construção a ser exibida
 */
void printConstruction(Construction construction);

/**
 * Imprime todas as posições na Lista
 * @param constructionsList Lista a ser verificada
 */
void printAllConstructions(ConstructionPointer constructionsList);


#endif
