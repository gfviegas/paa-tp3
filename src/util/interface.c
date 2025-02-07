/**
 * Gerencia e chama as funções relacionadas aos puzzles, imprimindo e lendo
 * os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Heitor Passeado
 */

#include "interface.h"

// Imprime uma mensagem de aguardando e aguarda a entrada do usuário para continuar a execução do programa
void pressEnterToContinue(void) {
	cprintf(RED, "\n Pressione enter para continuar...\n");
	int enter = -1;
	getchar();
	while (enter != '\n' && enter != '\r') { enter = getchar(); }
}

// Imprime uma flag que indica a leitura de um dado do usuário
void prePrompt(void) {
    cprintf(YELLOW, "->  ");
}

// Imprime o cabeçalho do programa
void printHeader(int analysisMode) {
    clearOutput();
    if (analysisMode) cprintf(RED, " *** \n [STATS] MODO ANALISE ATIVADO! \n *** \n");

    printf("\n\n");
    printLine();
    cprintf(BLUE, "_____                      _   _ _           _       \n| ___ \\                    | | | (_)         | |\n| |_/ / ___ _ __ ___ ______| | | |_ _ __   __| | ___\n| ___ \\/ _ \\ '_ ` _ \\______| | | | | '_ \\ / _` |/ _ \\\n| |_/ /  __/ | | | | |     \\ \\_/ / | | | | (_| | (_) |\n\\____/ \\___|_| |_| |_|      \\___/|_|_| |_|\\__,_|\\___/\n");
    cprintf(BLUE, "\n \t Ao TP 3 !");
    printLine();

    printMenu(analysisMode);
}

// Inicializa o programa imprimindo o menu inicial
void printMenu(int analysisMode) {
    int choice;

    cprintf(GREEN, "\n \n Selecione qual problema você deseja resolver : \n\n");
    cprintf(GREEN, "1 - Pirâmides de números\n");
    cprintf(GREEN, "2 - Obras na cidade\n");
    cprintf(GREEN, "3 - Sair\n");
    prePrompt();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            _pyramidInitial(analysisMode);
            break;
        case 2:
            _cityMenu(analysisMode);
            break;
        case 3:
            return;
        default:
            cprintf(RED, "\n\n * Digite apenas 1 ou 2, não temos tantas opções :(\n");
            return printMenu(analysisMode);
    }
}
