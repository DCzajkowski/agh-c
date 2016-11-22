/**
 * Napisz program mnożący dwie macierze liczb rzeczywistych (tablice 2-wymiarowe) o
 * rozmiarach ROW1xCOL1 i ROW2xCOL2 (do zdefiniowania przez #define - przy czym:
 * #define COL1 musi być równe ROW2). Wynikiem ma być trzecia macierz o rozmiarze
 * ROW1xCOL2. Elementy macierzy wynikowej to iloczyn skalarny wiersza pierwszej
 * macierzy przez kolumnę drugiej macierzy. Zawartość mnożonych macierzy należy
 * podać przy deklaracji zgodnie z przykładem "Obliczanie_z_definicji" ze strony:
 * Wikipedii (jako liczby rzeczywiste). Po obliczeniach wypisz macierz wynikową.
 */

#include <stdio.h>
#define ROW1 2
#define COL1 3
#define ROW2 3
#define COL2 4

int main()
{
    double matrix1[ROW1][COL1] = {{1, 2, 3}, {4, 5, 6}};
    double matrix2[ROW2][COL2] = {{12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    double matrix3[ROW1][COL2];

    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            matrix3[i][j] = 0;
            for (int k = 0; k < ROW2; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            printf(" %.3lf ", matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
