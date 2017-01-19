/**
 * UWAGA! Program nie skończony z powodu braku chęci.
 */

/**
 * Przy pomocy struktur zaimplementować prostą 'bazę danych', przechowywaną  w pamięci komputera
 * w postaci tablicy struktur. 'Baza danych' ma stanowić prostą książkę telefoniczną
 * (Imię, Nazwisko jako napisy, Numer telefonu jako liczba typu long). Program musi pozwalać
 * (poprzez funkcje) na dodanie, usunięcie i przeglądanie wpisów. Dane powinny być przechowywane
 * w tablicy dynamicznej. Należy napisać funkcje:
 *     - dodającą do tablicy jeden rekord bazy (czyli powiększającą tablicę o jeden element -
 *       można wzorować się na zadaniu "Powiększanie tablicy" z tematu "Dynamiczna alokacja pamięci"),
 *     - wyszukującą w bazie (tablicy) rekord o podanym polu Numer (zwracającą indeks znalezionego rekordu lub -1)
 *     - wypisującą element tablicy - tu proszę, aby funkcja otrzymywała adres (wskaźnik) wypisywanego elementu.
 *     - oraz funkcję usuwającą rekord o podanym indeksie tablicy (np. zwróconym przez funkcję wyszukującą)
 *       poprzez realokację tablicy (przy przepisywaniu należy pominąć rekord o podanym indeksie).
 * W programie proszę nie używać zmiennych globalnych.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char* first_name;
    char* last_name;
    long number;
};
typedef struct Contact Contact;

void print_contact(Contact* book, int id) {
    printf("%d \t%s \t%s \t%ld\n", id, (book[id]).first_name, (book[id]).last_name, (book[id]).number);
}

void clear_screen() {
    printf("\033[H\033[J");
}

void print_homescreen() {
    clear_screen();
    printf("Wpisz polecenie:");
    printf("\nadd - Dodaj kontakt do książki telefonicznej");
    printf("\nall - Wyświetl całą książkę telefoniczną");
    printf("\nsearch - Szukaj kontaktu po numerze telefonu");
    printf("\nshow - Wyświetl numer telefonu na podstawie id");
    printf("\nremove - Usuń kontakt na podstawie id");
    printf("\nexit - Zakończ program\n");
}

// int add(PhoneBook **book, int size, Phone phone) {

// }

// int remove(PhoneBook **book, int size, int id) {

// }

// int search(PhoneBook *book, int size, long number) {

// }


int main() {
    Contact* book = NULL;
    char* command;
    int next;
    int size = 0;

    while (1) {
        print_homescreen();
        putchar('>');
        putchar(' ');
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("|add|");
        } else if (strcmp(command, "all") == 0) {
            if (book == NULL || size == 0) {
                printf("Nie ma żadnych numerów telefonu\n");
                continue;
            }

            // printf("ID \tImię \tNazwisko \tNumer telefonu\n--------------------------------------------\n");
            // for (int i = 0; i <= size; i++) {
            //     print_contact(book, i);
            // }
        } else if (strcmp(command, "search") == 0) {
            printf("|search|");
        } else if (strcmp(command, "show") == 0) {
            printf("|show|");
        } else if (strcmp(command, "remove") == 0) {
            printf("|remove|");
        } else if (strcmp(command, "exit") == 0) {
            clear_screen();
            break;
        }

        printf("\n"); getchar(); getchar();
    }

    return 0;
}
