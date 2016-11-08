/**
 * Napisz program wypisujący tabliczkę mnożenia 10x10 w postaci tabelki (fragment poniżej, kropki oznaczają spacje):
 *
 * ...| .1 .2 .3 .4 .5 .6 .7 .8 .9 10
 * ---------------------------------
 * .1 | .1 .2 .3 .4 .5 .6 .7 .8 .9 10
 * .2 | .2 .4 .6 .8 10 12 14 16 18 20
 * .3 | .3 .6 .9 12 15 18 21 24 27 30
 * itd.
 *
 * Liczby powinny być w kolumnach z wyrównaniem do prawej. W wersji uproszczonej można pominąć "ozdobniki" (linie oraz numery kolumn i wierszy).
 */

#include <stdio.h>

int main()
{
    int n = 10,
        m = 10;

    printf("...│");
    for (int i = 1; i <= n; i++) {
        printf(" %4d", i);
    }
    printf("\n");

    printf("───┼");
    for (int i = 1; i <= n * 5; i++) {
        printf("─");
    }
    printf("\n");

    for (int i = 1; i <= n; i++) {
        if (i < 10) {
            printf(" %d │", i);
        } else {
            printf("%d │", i);
        }

        for (int j = 1; j <= m; j++) {
            printf(" %4d", i * j);
        }
        printf("\n");
    }

    return 0;
}
