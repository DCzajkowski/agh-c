/**
 * Napisz program, który wczyta napis ze standardowego wejścia do tablicy,
 * a następnie usunie z niego wszystkie litery 'a'. Zmodyfikowany tekst
 * ma być zapamiętany w miejscu starego. Długość napisu to maksymalnie
 * 128 znaków (należy użyć #define).
 * Program należy napisać bez użycia tablic pomocniczych. Nie wolno użyć funkcji strlen,
 * ani w inny sposób obliczać długości napisu. Do wypisania napisu należy użyć funkcję puts.
 */

#include <stdio.h>
#define SIZE 128

int main()
{
    char text[SIZE];

    fgets(text, SIZE, stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'a') {
            for (int j = i; text[j] != '\0'; j++) {
                text[j] = text[j + 1];
            }
            i--;
        }
    }

    puts(text);

    return 0;
}
