#include "direction.h"

char directionLabel(Direction direction) {
	char label = (direction == NORTH) ? 'N' : (direction == EAST) ? 'E' : '-';
	return label;
}
