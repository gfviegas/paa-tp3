#include "constructions.h"

boolean isConstructionEmpty(ConstructionPointer construction) {
	return (construction == NULL);
}

ConstructionPointer createConstruction(Coordinates position, Direction direction) {
	ConstructionPointer construction = (ConstructionPointer) malloc(sizeof(struct Construction));
	if (isConstructionEmpty(construction)) return NULL;

	construction->active = TRUE;
	construction->position = position;
	construction->direction = direction;
	construction->next = NULL;

	return construction;
}

boolean addConstruction(ConstructionPointer constructionsList, Coordinates position, Direction direction) {
	if (isConstructionEmpty(constructionsList)) return FALSE;
	ConstructionPointer lastConstruction = constructionsList;

	while (lastConstruction->next == NULL) {
		lastConstruction = lastConstruction->next;
	}

	ConstructionPointer newConstruction = createConstruction(position, direction);
	if (newConstruction == NULL) return FALSE;

	lastConstruction->next = newConstruction;
	return TRUE;
}

boolean checkConstruction(ConstructionPointer constructionsList, Coordinates position, Direction direction) {
	if (isConstructionEmpty(constructionsList)) return FALSE;

	ConstructionPointer currentConstruction = constructionsList;

	while (currentConstruction->next == NULL) {
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
