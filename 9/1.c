/**
 * Napisz program zawierający następujące funkcje:
 *     int** createMatrix(int n);
 *         która tworzy macierz o wymiarze nxn. Fukcja zwraca utworzoną tablicę.
 *         W funkcji każdy wiersz ma być alokowany osobno. W funkcji należy użyć funkcji deleteMatrix().
 *
 *     void fillMatrix(int** tab, int n);
 *         która otrzymuje macierz tab o wymiarze "nxn", a następnie wypełnia ją kolejnymi
 *         liczbami naturalnymi począwszy od 1.
 *
 *     void copyMatrix(int*** pdest, int** src, int n);
 *         która tworzy tablicę "dest", kopiuje do niej zawartość tablicy "src" i "wrzuca"
 *         "dest" pod przekazany adres. Obie tablice są wymiaru "nxn".
 *         W funkcji należy użyć funkcji CreateMatrix().
 *
 *     void deleteMatrix(int*** ptab, int n);
 *         która otrzymuje poprzez adres macierz o wymiarze "nxn" utworzoną przez createMatrix()
 *         i następnie zwalnia zajmowaną przez macierz pamięć, a wskaźnik reprezentujący tablicę ustawia na NULL.
 *
 * W programie należy użyć wszystkich wymienionych powyżej funkcji do utworzenia tablicy o
 * wymyslonym rozmiarze, wypełnienia jej, skopiowania do drugiej tablicy, wypisania drugiej
 * tablicy i zwolnienia całej przydzielonej pamięci
 *
 * Sprawdź wszystkie malloc'i i zwolnij pamięć jeśli wystąpił problem
 */

#include <stdio.h>
#include <stdlib.h>

int* createMatrix(int n) {
    int *matrix = malloc(n * n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(matrix + i * n + j) = 0;
        }
    }

    return matrix;
}

// void fillMatrix(int** tab, int n);
// void copyMatrix(int*** pdest, int** src, int n);
// void deleteMatrix(int*** ptab, int n);

int main() {
    int n = 10;
    int* matrix = createMatrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", *(matrix + i * n + j));
        }
        printf("\n");
    }

    return 0;
}
