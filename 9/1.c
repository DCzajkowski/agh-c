/**

 */

#include <stdio.h>
#include <stdlib.h>

void deleteMatrix(int*** ptab, int n) {
    for (int i = 0; i < n; i++) {
        free((*ptab)[i]);
    }
    free(*ptab);

    *ptab = NULL;
}

int** createMatrix(int n) {
    int **tab = malloc(n * sizeof(int*));

    if (tab == NULL) return NULL;

    for (int i = 0; i < n; i++) {
        tab[i] = malloc(n * sizeof(int));
        if (tab[i] == NULL) return NULL;
    }

    return tab;
}

void fillMatrix(int** tab, int n) {
    int number = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tab[i][j] = number++;
        }
    }
}

void copyMatrix(int*** pdest, int** src, int n) {
    int** dest = createMatrix(n);

    if (dest == NULL) return;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[i][j] = src[i][j];
        }
    }

    *pdest = dest;
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int checkMatrix(int** matrix, int n, char* error) {
    if (matrix == NULL) {
        printf("%s\n", error);
        deleteMatrix(&matrix, n);

        return 1;
    }
    return 0;
}

int main() {
    char* error = "Wystąpił problem podczas alokowania pamięci.";
    int n = 10;
    int** matrix = createMatrix(n);

    if (checkMatrix(matrix, n, error)) return 0;

    fillMatrix(matrix, n);

    printMatrix(matrix, n);

    printf("\n---------------------------------------\n\n");

    int** new_matrix;
    copyMatrix(&new_matrix, matrix, n);

    if (checkMatrix(matrix, n, error)) return 0;

    printMatrix(new_matrix, n);

    deleteMatrix(&matrix, n);
    deleteMatrix(&new_matrix, n);

    return 0;
}
