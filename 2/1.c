/**
 * Napisz prosty kalkulator z czterema działaniami (+, -, *, /). Należy wykorzystać instrukcję switch.
 * Operatory powinny być wprowadzane PRZED liczbami w postaci znaków (+, -, *, /) np. + 5 7.
 */

#include <stdio.h>

int main()
{
    char symbol;
    double first;
    double last;

    scanf("%c %lf %lf", &symbol, &first, &last);

    if (symbol == '/' && last == 0) {
        printf("Nie wolno dzielić przez 0.\n");
        return 0;
    }

    switch (symbol) {
        case '+':
            printf("Wynik działania, to %lf\n", first + last);
            break;
        case '-':
            printf("Wynik działania, to %lf\n", first - last);
            break;
        case '*':
            printf("Wynik działania, to %lf\n", first * last);
            break;
        case '/':
            printf("Wynik działania, to %lf\n", first / last);
            break;
        default:
            printf("Znak działania nieprawidłowy. Dozwolone znaki +, -, *, /.\n");
            return 0;
    }

    return 0;
}
