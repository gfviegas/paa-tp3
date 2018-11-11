#include "pyramid.h"
#include "string.h"
void loadPyramidMatrix(int ***matrix, int *size){
    char fileName[FILE_BUFFER_SIZE];
    char currentLine[FILE_BUFFER_SIZE];
    int i=0,j=0;
    int calls = 0;
    FILE *file = NULL;
    if (*matrix != NULL) free(*matrix);

    promptFilePath(fileName);
    openFile(&file, fileName);

    while(readLine(file, currentLine)) {
        (*size)++;
    }
    Movements path[*size];
    fclose(file);
    (*matrix) = createIntMatrix((*size),(*size));
    fillIntMatrix(matrix, (*size), (*size), 0);

    openFile(&file, fileName);
    while(i < (*size)){
        for(j=0; j<= i; j++){
            (j == i) ? fscanf(file, "%d\n", &(*matrix)[i][j]) : fscanf(file, "%d ", &(*matrix)[i][j]);
        }
        i++;
    }
    fclose(file);

    printIntMatrix(matrix, (*size), (*size), "teste", RED, YELLOW);
    printf("O tamanho é %d\n", (*size));
    printf("PRINTS MOMENTANEOS!!\n");
    printLine();
    printf("[recursivo]O caminho mais longo é %d\n", solvePyramidRecursive(matrix, (*size) - 1, 0, 0, path, &calls));
    for(j = 0; j < (*size) - 1; j++){
        printf("%s\n", getMovementName(path[j]));
    }
    printf("Quantidade de chamadas --> %d\n", calls);
    calls = 0;
    printf("[memoization]O caminho mais longo é %d\n", solvePyramidMemoization(matrix, (*size) - 1, 0, 0, path, &calls));
    for(j = 0; j < (*size) - 1; j++){
        printf("%s\n", getMovementName(path[j]));
    }
    printf("Quantidade de chamadas --> %d\n", calls);
    calls = 0;
    printf("\n [PD] O caminho mais longo é %d ", solvePyramidPD(*matrix, (*size) - 1, path, &calls));
    printf("com %d operações\n", calls);

}


int solvePyramidRecursive(int ***matrix, int size, int i, int j, Movements *path, int *calls){
    (*calls)++;
    if(i == size)    return (*matrix)[i][j];

    if(solvePyramidRecursive(matrix, size, i + 1, j, path, calls) > solvePyramidRecursive(matrix, size, i + 1, j + 1, path, calls)){
        path[i] = LEFT;
        return (*matrix)[i][j] + solvePyramidRecursive(matrix, size, i + 1, j, path, calls);
    }
    else{
        path[i] = RIGHT;
        return (*matrix)[i][j] + solvePyramidRecursive(matrix, size, i + 1, j + 1, path, calls);
    }
}

int solvePyramidMemoization(int ***matrix, int size, int i, int j, Movements *path, int *calls){
    int **results;
    results = createIntMatrix(size,size);
    fillIntMatrix(&results, size, size, 0);
    return pyramidMemoization(matrix, size, i, j, path, &results, calls);
}

int pyramidMemoization(int ***matrix, int size, int i, int j, Movements *path, int ***results, int *calls){
    (*calls)++;
    if(i == size)    return (*matrix)[i][j];

    if((*results)[i][j] != 0){

        return (*matrix)[i][j] + (*results)[i][j];
    }
    else if(pyramidMemoization(matrix, size, i + 1, j, path, results, calls) > pyramidMemoization(matrix, size, i + 1, j + 1, path, results, calls)){
            path[i] = LEFT;
            (*results)[i][j] = pyramidMemoization(matrix, size, i + 1, j, path, results, calls);
            return (*matrix)[i][j] + (*results)[i][j];
        }
        else{
            path[i] = RIGHT;
            (*results)[i][j] = pyramidMemoization(matrix, size, i + 1, j + 1, path, results, calls);
            return  (*matrix)[i][j] + (*results)[i][j];
        }
}

int solvePyramidPD(int **matrix, int size, Movements *path, int *calls){
    int **results;
    results = createIntMatrix(size,size);
    fillIntMatrix(&results, size, size, 0);
    return pyramidPD(matrix, size, path, &results, calls);
}

int pyramidPD(int **matrix, int size, Movements *path, int ***results, int *calls){
    int i, j;
    for(i = size - 1; i >= 0; i--){
        for(j = 0; j <= i; j++){
            (*calls)++;
            matrix[i][j] = matrix[i][j] + max(matrix[i+1][j], matrix[i+1][j+1]);
        }
    }
    return matrix[0][0];
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}
const char* getMovementName(Movements move){
    if(move == LEFT) return "esquerda ";
    return "direita ";
}
