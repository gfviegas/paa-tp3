/**
 * Gerencia e chama as funções relacionadas ao problema de "Obras na Estrada"
 * manipulando estruturas de dados, utilizando de Programação Dinâmica
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#include "road.h"

void loadRoadMatrix(int ***matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination) {
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
		cprintf(RED, "%s \n", currentLine);
        // for (int j = 0; j < *columnsAmount; j++)
        //     (*matrix)[i][j] = currentLine[j];
    }

    fclose(file);
}
