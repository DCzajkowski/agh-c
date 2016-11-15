/**
 * Napisz program wczytujący ze standardowego wejścia krótki tekst (kilka wyrazów - maksymalnie 100 znaków)
 * do tablicy (proszę użyć funkcji fgets(char *tablica, int rozmiar_tablicy, FILE *strumien_danych),
 * gdzie strumieniem danych jest stdin). Następnie program ma wszystkie puste znaki (spacje, tabulacje)
 * zamienić na koniec linii i wypisać zmieniony tekst (funkcja puts(char *tablica)).
 *
 * Przykład użycia obu funkcji:
 *
 * #define R 100
 * char tab[R];
 * fgets(tab, R, stdin);
 * ...... TU JAKIŚ KOD .......
 * puts(tab);
 */

#include <stdio.h>
#define SIZE 100

int main()
{
    char array[SIZE];

    fgets(array, SIZE, stdin);

    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == ' ' || array[i] == '\t') {
            array[i] = '\n';
        }
    }

    puts(array);

    return 0;
}
