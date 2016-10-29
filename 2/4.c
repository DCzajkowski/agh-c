/**
 * Napisz program wyliczający silnię: n! = 1*2*...*n
 *
 * Pamiętaj, że 0! = 1! = 1.
 *
 * Program powinien działać w pętli, aż do podania liczby 0. W zadaniu należy wykorzystać pętlę for.
 */

#include <stdio.h>

int main()
{
    int i;
    int result;

    while (true) {
        result = 1;
        i = 0;

        scanf("%d", &i);

        if (i == 0) break;

        for (int x = i; x > 0; x--) {
            result *= x;
        }
        printf("%d! = %d\n", i, result);
    }

    return 0;
}
