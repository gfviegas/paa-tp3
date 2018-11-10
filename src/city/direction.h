/**
 * Define um ENUM de direções
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */
#ifndef direction_h
#define direction_h

#include <stdlib.h>
/**
* Direções disponíveis para percorrer a cidade.
*/
typedef enum Direction {
	NONE, // Nenhuma
	EAST, // Leste
	NORTH // Norte
} Direction;

typedef struct Coordinates* CoordinatesPointer;
typedef struct Coordinates {
	int x;
	int y;
} Coordinates;

char directionToLabel(Direction direction);

Direction labelToDirection(char label);

#endif
