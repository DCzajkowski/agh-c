/**
 * Napisz program sumujący kwadraty 10 kolejnych liczb naturalnych (od 1 do 10). W zadaniu należy wykorzystać pętlę while.
 */

#include <stdio.h>

int main()
{
    int i = 1;
    int result = 0;

    while (i <= 10) {
        result += i * i;
        i++;
    }

    printf("%d\n", result);

    return 0;
}
