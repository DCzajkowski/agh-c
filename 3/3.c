/**
 * Napisz program rysujący "choinkę" jak poniżej (kropki oznaczają spacje).
 *
 *     .....*
 *     ....***
 *     ...*****
 *     ..*******
 *     .*********
 *     ***********
 *
 * Wykorzystaj funkcję putchar z biblioteki stdio, która ma deklarację:
 *     int putchar(int znak);
 *
 * Przykład jej użycia:
 *     putchar('*');
 *
 * Liczba poziomów powinna być pobierana z klawiatury. Pierwsza gwiadka w ostatnim rzędzie powinna
 * znaleźć się w pierwszej kolumnie wiersza konsoli (stykać się z ramką).
 */

#include <stdio.h>

int main()
{
    int rows;

    printf("Podaj liczbę rzędów:\n");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            putchar(' ');
        }

        for (int j = 0; j < 2 * i - 1; j++) {
            putchar('*');
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
