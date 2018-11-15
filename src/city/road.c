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

	cprintf(BLUE, "[INFO] Arquivo lido com sucesso!\n");
    fclose(file);
}

int XtoArrayIndex(int x) {
	return x - 1;
}

int YtoArrayIndex(int y, int linesAmount) {
	return linesAmount - y;
}

int arrayIndexToX(int j) {
	return j + 1;
}

int arrayIndexToY(int i, int linesAmount) {
	return linesAmount - i;
}


boolean solve(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList) {
	cprintf(YELLOW, "[INFO] Origem: (%d, %d) \n", origin->x, origin->y);
	cprintf(YELLOW, "[INFO] Destino: (%d, %d) \n", destination->x, destination->y);

	fillIntMatrix(matrix, linesAmount, columnsAmount, 0);
	(*matrix)[YtoArrayIndex(destination->y, linesAmount)][XtoArrayIndex(destination->x)] = 1;

	for (int y = destination->y; y >= origin->y; y--) {
		for (int x = destination->x; x >= origin->x; x--) {
			Coordinates currentPosition = {x, y};
			int cpArrayY = YtoArrayIndex(y, linesAmount);
			int cpArrayX = XtoArrayIndex(x);

			if (y < columnsAmount && !checkConstruction(constructionsList, currentPosition, NORTH)) {
				int cpArrayY2 = YtoArrayIndex(y + 1, linesAmount);
				(*matrix)[cpArrayY][cpArrayX] += (*matrix)[cpArrayY2][cpArrayX];
			}

			if (x < linesAmount && !checkConstruction(constructionsList, currentPosition, EAST)) {
				int cpArrayX2 = XtoArrayIndex(x + 1);
				(*matrix)[cpArrayY][cpArrayX] += (*matrix)[cpArrayY][cpArrayX2];
			}
		}
	}

	printCity(matrix, linesAmount, columnsAmount, "Solução", constructionsList, FALSE);
	printSolutionPath(matrix, linesAmount, columnsAmount, origin, destination, constructionsList);

	return TRUE;
}

void printSolutionPath(int ***matrix, int linesAmount, int columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList) {
	int **pathMatrix = NULL;
	pathMatrix = createIntMatrix(linesAmount, columnsAmount);
	fillIntMatrix(&pathMatrix, linesAmount, columnsAmount, NONE);

	Coordinates currentPosition = *origin;
	int cpArrayY, cpArrayX;

	pathMatrix[YtoArrayIndex(destination->y, linesAmount)][XtoArrayIndex(destination->x)] = -1;

	while (currentPosition.x != destination->x || currentPosition.y != destination->y) {
		cpArrayY = YtoArrayIndex(currentPosition.y, linesAmount);
		cpArrayX = XtoArrayIndex(currentPosition.x);

		if (currentPosition.y < linesAmount && (*matrix)[cpArrayY][cpArrayX] > 0 && !checkConstruction(constructionsList, currentPosition, NORTH)) {
			pathMatrix[cpArrayY][cpArrayX] = NORTH;
			currentPosition.y += 1;
			continue;
		}
		if (currentPosition.x < columnsAmount && (*matrix)[cpArrayY][cpArrayX] > 0 && !checkConstruction(constructionsList, currentPosition, EAST)) {
			pathMatrix[cpArrayY][cpArrayX] = EAST;
			currentPosition.x += 1;
			continue;
		}
	}

	printCity(&(pathMatrix), linesAmount, columnsAmount, "Caminho Válido", constructionsList, TRUE);
	free(pathMatrix);
}

void printCity(int ***matrix, int linesAmount, int columnsAmount, char* header, ConstructionPointer constructionsList, boolean printPath) {
	int precision = ((columnsAmount*1.25 * 1.5) + 2) + ((int) strlen(header) / 2);

	printMatrixLine(columnsAmount*1.25, 1, 1, BLUE);
	cprintf(MAGENTA, "%*s", precision, header);
	printMatrixLine(columnsAmount*1.25, 1, 1, BLUE);

	for (int i = 0; i < linesAmount; i++) {
		if (i > 0) {
			cprintf(CYAN, " | ");
			for (int j = 0; j < columnsAmount; j++) {
				Coordinates currentPosition = {arrayIndexToX(j), arrayIndexToY(i, linesAmount)};
				AvailableColors colorToPrint = (checkConstruction(constructionsList, currentPosition, NORTH)) ? RED : GREEN;

				if (j < columnsAmount - 1) cprintf(colorToPrint, "==");
				printf("  ");
			}
			cprintf(CYAN, " |\n");
		}

		cprintf(CYAN, " | ");
		for (int j = 0; j < columnsAmount; j++) {
			Coordinates currentPosition = {arrayIndexToX(j), arrayIndexToY(i, linesAmount)};
			AvailableColors colorToPrint = (checkConstruction(constructionsList, currentPosition, EAST)) ? RED : GREEN;

			if (!printPath) {
				cprintf(YELLOW, "%.2d", (*matrix)[i][j]);
			} else if ((*matrix)[i][j] == NORTH) {
				cprintf(YELLOW, "/\\");
			} else if ((*matrix)[i][j] == EAST) {
				cprintf(YELLOW, "->");
			} else if ((*matrix)[i][j] == -1) {
				cprintf(YELLOW, "**");
			} else {
				cprintf(YELLOW, "  ");
			}

			if (j < columnsAmount - 1) cprintf(colorToPrint, "||");
		}
		cprintf(CYAN, " |\n");
	}

	printMatrixLine(columnsAmount*1.25, 1, 1, BLUE);
}
