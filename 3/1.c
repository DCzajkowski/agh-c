/**
 * Napisz program wybierający najmniejszą liczbę z 10 wpisanych z klawiatury.
 */

#include <stdio.h>

int main()
{
    int current,
        smallest = 2147483647;

    printf("Podaj 10 liczb oddzielonych enterami:\n");

    for (int i = 0; i < 9; i++) {
        scanf("%d\n", &current);
        if (current < smallest) {
            smallest = current;
        }
    }

    printf("Najmniejsza liczba wśród podanych to: %d\n", smallest);

    return 0;
}
