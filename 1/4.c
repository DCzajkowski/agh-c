/**
 * Napisz program obliczający pole koła na postawie promienia.
 * Program ma pobierać promień od użytkownika "z klawiatury".
 * W obliczeniach proszę użyć zmiennych rzeczywistych.
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double radius;
    double result;

    scanf("%lf", &radius);

    result = M_PI * radius * radius;

    printf("Pole kola wynosi %lf\n", result);

    return 0;
}
