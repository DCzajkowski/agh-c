/**
 * Napisz program, który będzie prosił o podanie współczynników a,b,c równania kwadratowego postaci
 *
 * ax^2 + bx + c = 0
 *
 * i następnie wypisze rozwiązania takiego równania. Obliczanie miejsc zerowych zaimplementuj jako
 * funkcję. Funkcja zwraca liczbę znalezionych miejsc zerowych i posiada dwa dodatkowe parametry
 * (oprócz a, b, i c ) wypełniane wartościami miejsc zerowych przez funkcję.
 * Nie wolno używać zmiennych globalnych.
 */

#include <stdio.h>
#include <math.h>

int f(double a, double b, double c, double &result1, double &result2)
{
    double delta = pow(b, 2) - 4 * a * c;
    if (delta > 0) {
        result1 = (- b - sqrt(delta)) / (2 * a);
        result2 = (- b + sqrt(delta)) / (2 * a);

        return 2;
    } else if (delta == 0) {
        result1 = (- b) / (2 * a);

        return 1;
    }
    return 0;
}

int main()
{
    double a, b, c;
    double result1, result2;

    printf("Podaj współczynniki funkcji kwadratowej oddzielone spacją:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    int results = f(a, b, c, result1, result2);

    if (results == 0) {
        printf("Brak rozwiązań równania.\n");
        return 0;
    }

    printf("Rozwiązania tego rówanania kwadratowego to:\n");

    if (results == 2) {
        printf("%lf\n", result1);
        printf("%lf\n", result2);
    } else if (results == 1) {
        printf("%lf\n", result1);
    }

    return 0;
}
