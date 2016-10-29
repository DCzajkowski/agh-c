/**
 * Napisz program wyświetlający na ekranie Twoje imię i nazwisko na trzy sposoby:
 *   w jednym wierszu przy pomocy jednego wywołania funkcji printf,
 *   w dwóch osobnych wierszach przy pomocy jednego wywołania printf
 *   w jednym wierszu przy użyciu dwóch wywołań printf.
 */

#include <stdio.h>

int main()
{
    char first_name[] = "Dariusz";
    char last_name[] = "Czajkowski";

    printf("1. %s %s\n", first_name, last_name);
    printf("2. %s\n%s\n", first_name, last_name);
    printf("3. %s ", first_name);
    printf("%s\n", last_name);

    return 0;
}
