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
#include <string.h>
#include <stdlib.h>
#define SIZE 255

struct Person {
    char first_name[SIZE];
    char last_name[SIZE];
    int year;
};

struct Element {
    struct Person person;
    struct Element* next;
};

void attach(struct Element** head, char* first_name, char* last_name, int year) {
    struct Element* element = malloc(sizeof(*element));
    strcpy(element->person.first_name, first_name);
    strcpy(element->person.last_name, last_name);
    element->person.year = year;
    element->next = *head;
    *head = element;
}

void add(struct Element** head) {
    struct Element* element = malloc(sizeof(*element));

    if (element != NULL) {
        printf("Podaj imię, nazwisko i rok urodzenia oddzielone spacjami:\n");
        scanf("%s %s %d", element->person.first_name, element->person.last_name, &element->person.year);

        element->next = *head;

        *head = element;
        printf("\nDodano element.\n");
    } else {
        printf("Wystąpił problem podczas alokowania pamięci.\n");
    }
}

void all(struct Element* head) {
    struct Element *element = head;

    if (element == NULL) {
        printf("Nie ma żadnych elementów w tablicy.\n");
        return;
    }

    for (; element != NULL; element = element->next) {
        printf("%s %s %d\n", element->person.first_name, element->person.last_name, element->person.year);
    }
}

struct Element * search(struct Element* head, int year) {
    struct Element *element = head;
    struct Element *found = NULL;

    if (element == NULL) {
        printf("Nie ma żadnych elementów w tablicy.\n");
        return NULL;
    }

    for (; element != NULL; element = element->next) {
        if (element->person.year == year) {
            attach(&found, element->person.first_name, element->person.last_name, element->person.year);
        }
    }

    return found;
}

void clear_screen() {
    printf("\033[H\033[J");
}

void print_homescreen() {
    clear_screen();
    printf("Wpisz polecenie:");
    printf("\n1 - Wyświetl całą listę");
    printf("\n2 - Dodaj nowy element");
    printf("\n3 - Wyszukaj elementy na podstawie roku urodzenia");
    printf("\n4 - Dodaj element w dowolnym miejscu listy");
    printf("\n5 - Usuń element z początku listy");
    printf("\n0 - Zakończ program\n");
}

void close() {
    clear_screen();
    printf("Wystąpił problem.");
}

int main() {
    struct Element *head = NULL;
    int choice;

    while (1) {
        print_homescreen();
        putchar('>');
        putchar(' ');
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            all(head);
        } else if (choice == 2) {
            add(&head);

            if (head == NULL) { close(); return 0; }
        } else if (choice == 3) {
            int year;
            printf("Podaj rok urodzenia po którym chcesz wyszukać rekordy:\n");
            putchar('>');
            putchar(' ');
            scanf("%d", &year);
            struct Element * found = search(head, year);
            for (; found != NULL; found = found->next) {
                printf("%s %s %d\n", found->person.first_name, found->person.last_name, found->person.year);
            }
        } else if (choice == 4) {
            printf("|add in different place|");
        } else if (choice == 5) {
            printf("|remove the first element|");
        } else if (choice == 0) {
            clear_screen();
            break;
        }

        printf("\n\nNaciśnij dowolny klawisz aby kontynuować...\n"); getchar(); getchar();
    }

    return 0;
}
