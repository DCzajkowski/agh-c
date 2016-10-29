/** Napisz program wypisujący pierwiastki kwadratowe z liczb wczytywanych ze standardowego wejścia (klawiatury).
 * Program powinien działać w pętli, aż do podania liczby 0. W zadaniu należy wykorzystać pętlę do-while.
 *
 * Do obliczania pierwiastka należy użyć funkcji sqrt z biblioteki matematycznej.
 * W tym celu trzeba w kodzie załączyć plik nagłówkowy #include <math.h>  - funkcja sqrt ma tam deklarację:
 *     double sqrt(double x);
 * Przykład użycia funkcji sqrt:
 *     y = sqrt(x);
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double i = 0;

    do {
        scanf("%lf", &i);
        printf("%lf\n", sqrt(i));
    } while (i != 0);

    return 0;
}
