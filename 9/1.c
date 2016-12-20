/**
 * Sprawdź wszystkie malloc'i i zwolnij pamięć jeśli wystąpił problem
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

    for (int i = 0; i < n; i++) {
        tab[i] = malloc(n * sizeof(int));
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[i][j] = src[i][j];
        }
    }

    *pdest = dest;
}

int main() {
    int n = 10;
    int** matrix = createMatrix(n);

    fillMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n---\n\n");

    int** new_matrix;
    copyMatrix(&new_matrix, matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", new_matrix[i][j]);
        }
        printf("\n");
    }

    deleteMatrix(&matrix, n);
    deleteMatrix(&new_matrix, n);

    return 0;
}
