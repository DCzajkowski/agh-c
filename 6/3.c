/**
 * Napisz funkcję
 *
 * int isEqual(char* str1, char* str2)
 *
 * która sprawdza czy podane dwa ciągi znaków (napisy) są identyczne. Funkcja ma zwrócić true lub false.
 * Ponieważ używany przez nas standard języka C nie ma jeszcze typu Boolean więc należy zdefiniować true
 * i false we własnym zakresie.
 *
 * Użyj funkcji w programie głównym - sprawdź działanie funkcji na następujących parach napisów (należy
 * wypisywać odpowiedni komunikat w zależności od rezultatu działania funkcji):
 *
 * "Ala ma kota",  "Ala ma kota"
 * "Ala ma",  "Ala ma kota"
 * "Ala ma kota",  "Ala ma"
 */

#include <stdio.h>
#include <string.h>
#define true 1
#define false 0

int isEqual(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

int main()
{
    printf("'Ala ma kota' i 'Ala ma kota' ");
    if (isEqual("Ala ma kota", "Ala ma kota")) {
        printf("są takie same.\n");
    } else {
        printf("nie są takie same.\n");
    }

    printf("'Ala ma' i 'Ala ma kota' ");
    if (isEqual("Ala ma", "Ala ma kota")) {
        printf("są takie same.\n");
    } else {
        printf("nie są takie same.\n");
    }

    printf("'Ala ma kota' i 'Ala ma' ");
    if (isEqual("Ala ma kota", "Ala ma")) {
        printf("są takie same.\n");
    } else {
        printf("nie są takie same.\n");
    }

    return 0;
}
