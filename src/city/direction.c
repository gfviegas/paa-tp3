#include "direction.h"

char directionToLabel(Direction direction) {
	char label = (direction == EAST) ? 'L' : (direction == NORTH) ? 'N' : '-';
	return label;
}

Direction labelToDirection(char label) {
	Direction direction = (label == 'L') ? EAST : (label == 'N') ? NORTH : NONE;
	return direction;
}
