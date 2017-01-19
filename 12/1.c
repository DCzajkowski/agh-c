/**
 * Zaimplementować listę jednokierunkową zawierającą dane osobowe:
 * imię, nazwisko, rok urodzenia. Dane osobowe mają być zdefiniowane w
 * osobnej strukturze. Struktura opisująca element listy ma zawierać
 * strukturę z danymi osobowymi oraz  pole wskaźnikowe do "siebie samej".
 * Program musi zawierać funkcje realizujące następujące operacje:
 *     * wypisywanie listy
 *     * dodawanie nowego elementu na początku listy
 *     * dodawanie nowego elementu na końcu listy (nadobowiązkowo)
 *     * wyszukiwanie elementów wg. roku urodzenia, ( i nazwiska nadobowiązkowo)
 *     * dodawanie nowego elementu w dowolnym miejscu listy (za wyszukanym)
 *     * usuwanie elementu z początku listy
 *     * usuwanie elementu z końca listy (nadobowiązkowo)
 *     * usuwanie elementu z dowolnego miejsca listy (wyszukanego)  (nadobowiązkowo)
 *     * usuwanie całej listy (zwalnianie pamięci).
 *
 * W programie proszę nie używać zmiennych globalnych.
 *
 * Proszę w programie użyć dwóch sposobów zwracania "nowej głowy" przez funkcje dodającą i
 * usuwającą - jedna z nich niech zwraca przez return a druga przez adres (kolejność dowolna).
 *
 * Proszę w jakiś sposób uwzględnić fakt, że jeżeli alokacja się nie powiedzie to wtedy coś
 * trzeba zrobić z dotychczasową listą (nadobowiązkowo).
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 255

struct Person {
    char first_name[SIZE];
    char last_name[SIZE];
    int year;
};

struct List {
    struct Person person;
    struct List* next;
};

void add(struct List** head) {
    struct List* element = malloc(sizeof(*element));

    if (element != NULL) {
        printf("Podaj imię, nazwisko i rok urodzenia oddzielone spacjami:\n");
        scanf("%s %s %d", element->person.first_name, element->person.last_name, &element->person.year);

        element->next = *head;

        *head = element;
    } else {
        printf("Wystąpił problem podczas alokowania pamięci.\n");
    }
}

void all(struct List* head) {
    struct List *element = head;

    if (element == NULL) {
        printf("Nie ma żadnych elementów w tablicy.\n");
        return;
    }

    for (; element != NULL; element = element->next) {
        printf("%s %s %d\n", element->person.first_name, element->person.last_name, element->person.year);
    }
}

struct List * search(struct List* head, int year) {
    struct List *element = head;
    struct List *found = NULL;

    if (element == NULL) {
        printf("Nie ma żadnych elementów w tablicy.\n");
        return NULL;
    }

    for (; element != NULL; element = element->next) {
        if (element->person.year == year) {
            add(&found);
        }
    }

    return found;
}

int main() {
    struct List *head = NULL;

    add(&head);

    if (head == NULL) {
        return 0;
    }

    all(head);

    return 0;
}
