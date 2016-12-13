/**
 * Napisz funkcję, która stworzy dynamicznie tablicę o długości podanej przez argument wywołania
 * i zwróci wskaźnik na zaalokowaną pamięć. Ponadto w funkcji tablica powinna zostać wypełniona
 * kolejnymi, nieparzystymi liczbami całkowitymi (począwszy od 1). Funkcję należy użyć w main-ie
 * do utworzenia tablicy o rozmiarze podanym z klawiatury, następnie tablicę należy wypisać na
 * ekranie. Proszę pamiętać o zwalnianiu pamięci przydzielonej dynamicznie.
 */

#include <stdio.h>
#include <stdlib.h>

int* f(int* tab, int size) {
    tab = malloc(size * sizeof(int));

    if (tab == NULL) {
        return NULL;
    }

    for(int i = 0; i < size; i++) {
        tab[i] = 2 * i + 1;
    }

    return tab;
}

int main() {
    printf("Podaj rozmiar tablicy: ");

    int size;
    scanf("%d", &size);

    int* tab;
    tab = f(tab, size);

    if (tab == NULL) {
        printf("Nie udało się przydzielić pamięci.");
        return 0;
    }

    for (int i = 0; i < size; i++) {
        printf(" %d ", tab[i]);
    }
    printf("\n");

    free(tab);

    return 0;
}
