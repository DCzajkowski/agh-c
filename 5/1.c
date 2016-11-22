/**
 * Napisz program dodający do siebie dwie macierze (tablice 2-wymiarowe) o rozmiarze ROWxCOL
 * (do zdefiniowania przez #define - proszę aby liczba wierszy była różna od liczby kolumn).
 * Wynikiem ma być trzecia macierz o tym samym rozmiarze. Elementy macierzy wynikowej to
 * suma odpowiadających im elementów dodawanych macierzy. Zawartość sumowanych macierzy
 * należy podać przy deklaracji (dowolne liczby całkowite). Po sumowaniu wypisz macierz
 * wynikową (w osobnych pętlach).
 */

#include <stdio.h>
#define ROW 4
#define COL 3

int main()
{
    int matrix1[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int matrix2[ROW][COL] = {{12, 11, 10}, {9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matrix3[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf(" %d ", matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
