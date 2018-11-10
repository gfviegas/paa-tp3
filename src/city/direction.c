#include "direction.h"

char directionLabel(Direction direction) {
	char label = (direction == EAST) ? 'E' : (direction == NORTH) ? 'N' : '-';
	return label;
}
