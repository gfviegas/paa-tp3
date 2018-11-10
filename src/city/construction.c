#include "construction.h"

boolean isConstructionEmpty(ConstructionPointer construction) {
	return toBoolean(construction == NULL);
}

ConstructionPointer createConstruction(Coordinates position, Direction direction) {
	ConstructionPointer construction = (ConstructionPointer) malloc(sizeof(struct Construction));
	if (isConstructionEmpty(construction)) return NULL;

	construction->active = TRUE;
	construction->position.x = position.x;
	construction->position.y = position.y;
	construction->direction = direction;
	construction->next = NULL;

	return construction;
}

boolean addConstruction(ConstructionPointer *constructionsList, Coordinates position, Direction direction) {
	ConstructionPointer newConstruction = createConstruction(position, direction);
	if (isConstructionEmpty(newConstruction)) return FALSE;

	if (isConstructionEmpty(*constructionsList)) {
		*constructionsList = newConstruction;
		return !isConstructionEmpty(*constructionsList);
	}

	ConstructionPointer lastConstruction = *constructionsList;

	while (!isConstructionEmpty(lastConstruction->next)) {
		lastConstruction = lastConstruction->next;
	}

	lastConstruction->next = newConstruction;
	return TRUE;
}

boolean checkConstruction(ConstructionPointer constructionsList, Coordinates position, Direction direction) {
	if (isConstructionEmpty(constructionsList)) return FALSE;

	ConstructionPointer currentConstruction = constructionsList;

	while (!isConstructionEmpty(currentConstruction)) {
		if (
			(currentConstruction->active) &&
			(currentConstruction->position.x == position.x) &&
			(currentConstruction->position.y == position.y) &&
			(currentConstruction->direction == direction)
		) return TRUE;

		currentConstruction = currentConstruction->next;
	}

	return FALSE;
}

void printConstruction(Construction construction) {
	cprintf(CYAN, "*** CONSTRUÇÃO #%p ***\n", construction);
	cprintf(CYAN, "Ativo: %s\n", (construction.active) ? "sim" : "não");
	cprintf(CYAN, "Coordenadas: (%d, %d)\n", construction.position.x, construction.position.y);
	cprintf(CYAN, "Direção: %c\n", directionToLabel(construction.direction));
	cprintf(CYAN, "************\n");
}

void printAllConstructions(ConstructionPointer constructionsList) {
	if (isConstructionEmpty(constructionsList)) {
		cprintf(RED, "\n NENHUMA CONSTRUÇÃO \n");
		return;
	}

	ConstructionPointer currentConstruction = constructionsList;

	while (!isConstructionEmpty(currentConstruction)) {
		printConstruction(*currentConstruction);
		currentConstruction = currentConstruction->next;
	}
}
