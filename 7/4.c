/**
 * Napisz rekurencyjną funkcję, która sprawdza, czy podany napis jest palindromem
 * (czyta się tak samo od początku jak i od końca - np. 'ala', 'kobyłamamałybok' itp.).
 * Funkcja ma zwrócić 0 kiedy napis nie jest, a 1 kiedy jest palindromem.
 * Funkcja ma mieć dwa parametry: napis (czyli char *) i długość napisu.
 */

#include <stdio.h>

int f(char *text, int length) {
    if (length == 0 || length == 1) {
        return 1;
    }
    if (text[0] == text[length - 1]) {
        return f(text + 1, length - 2);
    }
    return 0;
}

int main() {
    int length = 15;
    char *text = "kobylamamalybok";

    if (f(text, length)) {
        printf("Podany tekst jest palindromem.\n");
    } else {
        printf("Podany tekst nie jest palindromem.\n");
    }

    return 0;
}
