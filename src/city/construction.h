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

boolean isConstructionEmpty(ConstructionPointer construction);

ConstructionPointer createConstruction(Coordinates position, Direction direction);

boolean addConstruction(ConstructionPointer constructionsList, Coordinates position, Direction direction);

boolean checkConstruction(ConstructionPointer constructionsList, Coordinates position, Direction direction);

void printConstruction(Construction construction);

void printAllConstructions(ConstructionPointer constructionsList);


#endif
