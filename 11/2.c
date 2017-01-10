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
#define SIZE 30

struct Phone {
    char first_name[SIZE];
    char last_name[SIZE];
    long number;
};

struct PhoneBook {
    int size;
    Phone* = phones;
};

// dodanie
// usunięcie
// przeglądanie wpisów

void print_number(struct Phone phone) {
    printf("%s \t\t%s \t\t%ld\n", phone.first_name, phone.last_name, phone.number);
}

void print_book(struct PhoneBook book) {
    for (int i = 0; i <= book.size; i++) {
        printf("%s \t\t%s \t\t%ld\n", book[i].first_name, book[i].last_name, book[i].number);
    }
}

int main() {
    struct PhoneBook book;

    book[0].first_name = "John";
    book[0].last_name = "Doe";
    book[0].number = 505555555;

    printf("First Name \tLast Name \tPhone Number\n--------------------------------------------\n");
    print_phone3(book);

    return 0;
}
