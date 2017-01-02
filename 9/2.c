/**
 * Napisz funkcje:
 *     void createNewMatrix(int*** ptab, int n);
 * która tworzy macierz o wymiarze nxn. Fukcja zwraca utworzoną tablicę poprzez dodatkowy
 * argument (wskaźnik do tablicy dwuwymiarowej). Funkcja ma tworzyć macierz jako ciągły
 * obszar pamięci (w odróźnieniu od funkcji createMatrix, gdzie każdy wiersz był alokowany
 * osobno); wskaźniki wierszy mają zostać odpowiednio przekierowane.
 *
 * Ponadto napisz funkcję:
 *     void deleteNewMatrix(int*** ptab);
 * które otrzymuje poprzez wskaźnik macierz utworzoną przez funkcję createNewMatrix() i
 * zwalnia zajmowaną przez macierz pamięć, a wskaźnik reprezentujący tablicę ustawia na NULL.
 *
 * W programie należy użyć wymienionych powyżej funkcji do utworzenia tablicy o wymyślonym
 * rozmiarze, wypełnienia jej za pomocą funkcji fillMatrix(), wypisania tablicy i zwolnienia
 * przydzielonej pamięci.
 *
 */

#include <stdio.h>
#include <stdlib.h>

void createNewMatrix(int*** ptab, int n) {
    if (ptab == NULL) return;
    if (n < 1) { *ptab = NULL; return; }

    int** pointers_array = malloc(n * sizeof(int*));
        if (pointers_array == NULL) { free(pointers_array); *ptab = NULL; return; }

    int* values_array = malloc(n * n * sizeof(int));
        if (values_array == NULL) { free(values_array); *ptab = NULL; return; }

    for (int i = 0; i < n; i++) {
        pointers_array[i] = (values_array + i * n);
    }

    *ptab = pointers_array;
}

void deleteNewMatrix(int*** ptab) {
    if (ptab == NULL)
        return;

    if (*ptab != NULL) {
        free(**ptab);
        free(*ptab);
    }

    ptab = NULL;
}

void fillMatrix(int** tab, int n) {
    int number = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tab[i][j] = number++;
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 10;
    int** matrix;

    createNewMatrix(&matrix, size);

    if (matrix != NULL) {
        fillMatrix(matrix, size);

        printMatrix(matrix, size);
    }

    deleteNewMatrix(&matrix);

    return 0;
}
