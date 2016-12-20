/**
 * Napisz program zawierający następujące funkcje:
 *     void fillMatrix(int** tab, int n);
 *         która otrzymuje macierz tab o wymiarze "nxn", a następnie wypełnia ją kolejnymi
 *         liczbami naturalnymi począwszy od 1.
 *
 *     void copyMatrix(int*** pdest, int** src, int n);
 *         która tworzy tablicę "dest", kopiuje do niej zawartość tablicy "src" i "wrzuca"
 *         "dest" pod przekazany adres. Obie tablice są wymiaru "nxn".
 *         W funkcji należy użyć funkcji CreateMatrix().
 *
 * W programie należy użyć wszystkich wymienionych powyżej funkcji do utworzenia tablicy o
 * wymyslonym rozmiarze, wypełnienia jej, skopiowania do drugiej tablicy, wypisania drugiej
 * tablicy i zwolnienia całej przydzielonej pamięci
 *
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

    // tab[i][j] = *(*(tab+i)+j)
    // for (int i = 0; i <  n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         tab[i][j] = 0;
    //     }
    // }

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

// void copyMatrix(int*** pdest, int** src, int n);

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

    deleteMatrix(&matrix, n);

    return 0;
}
