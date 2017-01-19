/**
 * UWAGA! To zadanie zostało oceninone na db z komentarzem:
 *     char* helper = malloc((size - 1) * sizeof(char)); za mało o 1znak
 *     100 nienazwana stała
 *     char new_text = deleteFirstChar(&text);- brak sprawdzenia wyniku działania funkcji
 *     brak zwolnienia pamięci w main
 */

/**
 * Napisz funkcję
 *     char deleteFirstChar(char** pstr)
 * która wylicza długość napisu wskazanego przez pstr i usuwa z niego pierwszy znak
 * poprzez zmniejszenie rozmiaru tablicy zawierającej napis - funkcja przydziela
 * dokładnie tyle pamięci, ile potrzebuje nowy napis i zwalnia pamięć przydzieloną
 * staremu (oczywiście po uprzednim przepisaniu napisu ze starej tablicy do nowej
 * wraz ze znakiem końca napisu). Na koniec pod adres pstr należy "wrzucić" na
 * nową tablicę. Funkcja ma zwracać usuwany znak.
 *
 * Po każdym usunięciu kolejnego znaku program (main) ma wypisać napis. W pisanej
 * funkcji proszę nie używać funkcji: realloc(), strcpy(), strlen().
 *
 * UWAGI:
 *     a) Przy testowaniu funkcji w programie głównym (main) napis przekazywany
 *         do funkcji deleteFirstChar musi być alokowany dynamicznie - w przeciwnym
 *         razie przy pierwszym wywołaniu funkcja deleteFirstChar będzie próbowała
 *         zwolnić pamięć przydzielaną statycznie (należy dynamicznie utworzyć
 *         100-elementową tablicę znakową i wczytać do niej napis przy użyciu funkcji fgets).
 *     b) Funkcja otrzymuje jako parametr adres tablicy. Tak więc odwołanie do elementu
 *         tablicy przekazanej przez adres będzie wyglądało:
 *         (*ptab)[i] - najpierw trzeba wyłuskać (wyciągnąć) tablicę spod adresu, a dopiero
 *         potem można odwoływać się do jej i-tego elementu. Nawiasy ( ) są konieczne, bo
 *         nawiasy [ ] są silniejsze od * (zapis *ptab[i] oznaczałby, że ptab jest tablicą
 *         wskaźników i wyłuskujemy to, na co wskazuje jej i-ty element).
 *
 */

#include <stdio.h>
#include <stdlib.h>

char deleteFirstChar(char** pointer) {
    int size = 0;
    char removal = (*pointer)[0];

    while ((*pointer)[size] != '\0' && (*pointer)[size] != '\n' ) {
        size++;
    }

    char* helper = malloc((size - 1) * sizeof(char));

    if (helper == NULL) {
        return '\0';
    }

    for (int i = 0; i < (size - 1); i++) {
        helper[i] = (*pointer)[i + 1];
    }
    helper[size - 1] = '\0';

    free(*pointer);
    *pointer = helper;

    return removal;
}

int main() {
    char* text = malloc(100 * sizeof(char));

    if (text == NULL) {
        printf("Wystąpił problem podczas alokowania pamięci.\n");
        return 0;
    }

    fgets(text, 100, stdin);

    char new_text = deleteFirstChar(&text);

    if (new_text == '\0') {
        printf("Wystąpił problem podczas alokowania pamięci.\n");
        return 0;
    }

    printf("Usunięty (zwrócony) znak: %c\n", new_text);
    printf("Nowy napis: %s\n", text);

    return 0;
}
