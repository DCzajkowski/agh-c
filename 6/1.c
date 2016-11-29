/**
 * Napisz funkcję
 *
 * char * isElement(char *tab, char znak)
 *
 * która sprawdza czy znak znak znajduje się w napisie tab, i zwraca wskazanie na pierwszy
 * znaleziony element tablicy lub NULL w wypadku nieznalezienia. Użyj funkcji w programie
 * głównym - zadeklaruj tablicę o nazwie napis (o wybranym przez siebie rozmiarze), wczytaj
 * zawartość za pomocą fgets i wywołaj funkcję isElement z tą tablicą i wybranym przez siebie znakiem.
 * W main-ie należy wypisać zawartość pamięci wskazywanej przez zwrócony przez funkcję wskaźnik lub
 * komunikat o nieznalezieniu znaku, kiedy zwrócony wskaźnik na wartość NULL.
 *
 */

#include <stdio.h>
#define SIZE 10

char* isElement(char *tab, char symbol) {
    for (int i = 0; tab[i] != '\0'; i++) {
        if (tab[i] == symbol) {
            return &tab[i];
        }
    }

    return NULL;
}

int main()
{
    char napis[SIZE];
    char symbol = 'a';
    char *pointer;

    fgets(napis, SIZE, stdin);

    pointer = isElement(napis, symbol);

    if (pointer != NULL) {
        printf("%c\n", *pointer);
    } else {
        printf("Nie znaleziono znaku '%c' w %s\n", symbol, napis);
    }

    return 0;
}
