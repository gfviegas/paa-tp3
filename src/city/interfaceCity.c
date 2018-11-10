#include "interfaceCity.h"

void _promptAction(int **matrix, int *linesAmount, int *columnsAmount, CoordinatesPointer origin, CoordinatesPointer destination, ConstructionPointer constructionsList, int analysisMode) {
    int choice;

    system("clear");
    printLine();

    printf("\n\n");
    cprintf(GREEN, "Escolha uma ação: \n\n");
    cprintf(GREEN, "1 - Carregar arquivo\n");
    cprintf(GREEN, "2 - Solucionar\n");
    cprintf(GREEN, "3 - Sair\n");

    prePrompt();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            loadRoadMatrix(&matrix, linesAmount, columnsAmount, origin, destination, &constructionsList);
            break;
        case 2:
            solve(&matrix, *linesAmount, *columnsAmount, origin, destination, constructionsList);

            break;
        case 3:
            return printHeader(analysisMode);
        default:
            cprintf(RED, "Opção inválida!\n");
            break;
    }

	scanf("%d", &choice);
    return _promptAction(matrix, linesAmount, columnsAmount, origin, destination, constructionsList, analysisMode);
}

void _cityMenu(int analysisMode) {
    int **matrix = NULL;
    int linesAmount, columnsAmount;
	Coordinates origin;
	Coordinates destination;
	ConstructionPointer constructions = NULL;

    _promptAction(matrix, &linesAmount, &columnsAmount, &origin, &destination, constructions, analysisMode);
}
