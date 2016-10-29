/**
 * Napisz program zamieniający miejscami wartości zmiennych całkowitych x oraz y wczytanych z klawiatury.
 * Należy wczytać liczby, wyświetlić je, zamienić wartości i wyswietlić ponownie.
 */

#include <stdio.h>

int main()
{
    int x;
    int y;
    int z;

    printf("Podaj zmienną x: ");
    scanf("%d", &x);
    printf("Podaj zmienną y: ");
    scanf("%d", &y);

    printf("Zmienna x wynosi %d, a zmienna y wynosi %d.\n", x, y);

    z = x;
    x = y;
    y = z;

    printf("Po zamianie zmienna x wynosi %d, a zmienna y wynosi %d.\n", x, y);

    return 0;
}
