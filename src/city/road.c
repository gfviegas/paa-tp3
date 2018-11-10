/**
 * Gerencia e chama as funções relacionadas ao problema de "Obras na Estrada"
 * manipulando estruturas de dados, utilizando de Programação Dinâmica
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "road.h"

void loadRoadMatrix(int ***matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList) {
	char currentLine[FILE_BUFFER_SIZE];
    char fileName[FILE_BUFFER_SIZE];
    FILE *file = NULL;

	int x, y;

    if (*matrix != NULL) free(*matrix);

    promptFilePath(fileName);
    openFile(&file, fileName);

    fscanf(file, "%d %d\n", linesAmount, columnsAmount);
	cprintf(GREEN, "Matrix: %d x %d \n", *linesAmount, *columnsAmount);

	fscanf(file, "%d %d\n", &x, &y);
	origin->x = x;
	origin->y = y;
	cprintf(GREEN, "Origem: (%d, %d) \n", origin->x, origin->y);

    fscanf(file, "%d %d\n", &x, &y);
	destination->x = x;
	destination->y = y;

	cprintf(GREEN, "Destino: (%d, %d) \n", destination->x, destination->y);

    *matrix = createIntMatrix(*linesAmount, *columnsAmount);
	fillIntMatrix(matrix, *linesAmount, *columnsAmount, 0);

    while (readLine(file, currentLine)) {
		Coordinates position;
		Direction direction;
		int x, y;
		char directionChar;

		sscanf(currentLine, "%d %d %c", &x, &y, &directionChar);

		position.x = x;
		position.y = y;
		direction = (directionChar == 'L') ? EAST : (directionChar == 'N') ? NORTH : NONE;
		if (direction == NONE) continue;

		addConstruction(&constructionsList, position, direction);
    }

	printAllConstructions(constructionsList);
	printIntMatrix(matrix, *linesAmount, *columnsAmount, "Teste", CYAN, YELLOW);

	Direction dir2 = NORTH;
	Coordinates pos2;
	pos2.x = 2;
	pos2.y = 2;
	cprintf(YELLOW, "Tem obra na posicao (%d, %d) na direção %c? = %d\n", 2, 2, directionLabel(dir2), checkConstruction(constructionsList, pos2, dir2));
	pos2.x = 1;
	pos2.y = 2;
	dir2 = EAST;
	cprintf(YELLOW, "Tem obra na posicao (%d, %d) na direção %c? = %d\n", 1, 2, directionLabel(dir2), checkConstruction(constructionsList, pos2, dir2));
	dir2 = NORTH;
	cprintf(YELLOW, "Tem obra na posicao (%d, %d) na direção %c? = %d\n", 1, 2, directionLabel(dir2), checkConstruction(constructionsList, pos2, dir2));

	scanf("%d", &x);

    fclose(file);
}
