/**
 * Gerencia e chama as funções relacionadas ao problema de "Obras na Estrada"
 * manipulando estruturas de dados, utilizando de Programação Dinâmica
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "road.h"

void loadRoadMatrix(int ***matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer *constructionsList) {
	char currentLine[FILE_BUFFER_SIZE];
    char fileName[FILE_BUFFER_SIZE];
    FILE *file = NULL;

	int x, y;

    if (*matrix != NULL) free(*matrix);

    promptFilePath(fileName);
    openFile(&file, fileName);

    fscanf(file, "%d %d\n", linesAmount, columnsAmount);

	fscanf(file, "%d %d\n", &x, &y);
	origin->x = x;
	origin->y = y;

    fscanf(file, "%d %d\n", &x, &y);
	destination->x = x;
	destination->y = y;

    *matrix = createIntMatrix(*linesAmount, *columnsAmount);
	fillIntMatrix(matrix, *linesAmount, *columnsAmount, 0);

    while (readLine(file, currentLine)) {
		Coordinates position;
		Direction direction;
		char directionLabel;

		sscanf(currentLine, "%d %d %c", &(position.x), &(position.y), &directionLabel);
		direction = labelToDirection(directionLabel);

		if (direction == NONE) continue;
		addConstruction(constructionsList, position, direction);
    }

	printAllConstructions(*constructionsList);
	printIntMatrix(matrix, *linesAmount, *columnsAmount, "Teste", CYAN, YELLOW);

	/**
	 * TESTES
	 */
	Direction dir2 = NORTH;
	Coordinates pos2;
	pos2.x = 2;
	pos2.y = 2;
	cprintf(YELLOW, "Tem obra na posicao (%d, %d) na direção %c? = %d\n", 2, 2, directionToLabel(dir2), checkConstruction(*constructionsList, pos2, dir2));
	pos2.x = 1;
	pos2.y = 2;
	dir2 = EAST;
	cprintf(YELLOW, "Tem obra na posicao (%d, %d) na direção %c? = %d\n", 1, 2, directionToLabel(dir2), checkConstruction(*constructionsList, pos2, dir2));
	dir2 = NORTH;
	cprintf(YELLOW, "Tem obra na posicao (%d, %d) na direção %c? = %d\n", 1, 2, directionToLabel(dir2), checkConstruction(*constructionsList, pos2, dir2));
	/**
	 * FIM TESTES
	 */

    fclose(file);
}

int positionArrayX(int x) {
	return x - 1;
}
int positionArrayY(int y, int linesAmount) {
	return linesAmount - y;
}


boolean solve(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList) {
	printAllConstructions(constructionsList);
	cprintf(YELLOW, "\n [INFO] Matrix: %d x %d \n", linesAmount, columnsAmount);
	cprintf(YELLOW, "[INFO] Origem: (%d, %d) \n", origin->x, origin->y);
	cprintf(YELLOW, "[INFO] Destino: (%d, %d) \n", destination->x, destination->y);

	(*matrix)[positionArrayY(destination->y, linesAmount)][positionArrayX(destination->x)] = 1;

	for (int y = destination->y; y >= origin->y; y--) {
		for (int x = destination->x; x >= origin->x; x--) {
			Coordinates currentPosition = {x, y};
			int cpArrayY = positionArrayY(y, linesAmount);
			int cpArrayX = positionArrayX(x);

			if (y < columnsAmount && !checkConstruction(constructionsList, currentPosition, NORTH)) {
				int cpArrayY2 = positionArrayY(y + 1, linesAmount);
				(*matrix)[cpArrayY][cpArrayX] += (*matrix)[cpArrayY2][cpArrayX];
			}

			if (x < linesAmount && !checkConstruction(constructionsList, currentPosition, EAST)) {
				int cpArrayX2 = positionArrayX(x + 1);
				(*matrix)[cpArrayY][cpArrayX] += (*matrix)[cpArrayY][cpArrayX2];
			}
		}
	}

	printIntMatrix(matrix, linesAmount, columnsAmount, "Solução", CYAN, YELLOW);
	return TRUE;
}
