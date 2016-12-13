/**
 * Napisz funkcję
 *     int * add(int* tab, int n, int new_elem);
 * która powiększa przekazaną n-elementową tablicę o jeden element new_elem
 * (umieszczany na końcu powiększonej tablicy). Funkcja zwraca adres
 * powiększonej tablicy (nowo przydzielonej pamięci) lub NULL w
 * wypadku niepowodzenia. Funkcja powinna zostać wywołana 10-krotnie
 * w programie głównym (main) celem utworzenia tablicy 10-cio elementowej,
 * która następnie ma zostać wypisana. W main wskaźnik, który stanie się
 * powiększaną tablicą należy ustawić wstępnie na NULL. W tworzonej funkcji
 * proszę nie używać funkcji realloc().
 *
 * UWAGI:
 * Kolejność działań funkcji:
 *     przydzielenie pamięci o 1 większej od n,
 *     przepisanie zawartości tablicy do nowo przydzielonego miejsca,
 *     zwolnienie pamięci tablicy (starej),
 *     zwrócenie wskaźnika na nowo przydzieloną pamięć (nowej tablicy).
 *
 */

#include <stdio.h>
#include <stdlib.h>

int* add(int* tab, int n, int new_elem) {
    int* helper;
    helper = malloc(n * sizeof(int));

    if (helper == NULL) {
        return NULL;
    }

    for(int i = 0; i < n; i++) {
        helper[i] = tab[i];
    }

    free(tab);

    tab = malloc((n + 1) * sizeof(int));

    if (tab == NULL) {
        return NULL;
    }

    for(int i = 0; i < n; i++) {
        tab[i] = helper[i];
    }
    tab[n] = new_elem;

    free(helper);

    return tab;
}

int main() {
    int* tab = NULL;

    for (int i = 0; i < 10; i++) {
        tab = add(tab, i, i + 10);

        if (tab == NULL) {
            printf("Wystąpił problem podczas alokacji pamięci.\n");
            return 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf(" %d ", tab[i]);
    }

    free(tab);

    return 0;
}
