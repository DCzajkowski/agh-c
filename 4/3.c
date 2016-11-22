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
    int i = 0;
    int j = 0;

    fgets(text, SIZE, stdin);

    while (text[i] != '\0') {
        if (text[i] == 'a') {
            j = i;
            while (text[j] != '\0') {
                text[j] = text[j + 1];
                j++;
            }
            i--;
        }
        i++;
    }

    puts(text);

    return 0;
}
