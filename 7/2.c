/**
 * Napisz funkcję rekurencyjną obliczającą wartość symbolu Newtona
 *
 * (n po k) dla n >= k >= 0.
 *
 * Skorzystaj z zależności:
 *
 * (wzor rekurencyjny) (n po k) = ((n-1) po (k-1)) + ((n-1) po (k)) dla n, k > 0.
 *
 * n po k wynosi 1 dla k = 0 i k = n
 */

#include <stdio.h>

int f(int n, int k) {
    if (n >= k && k >= 0) {
        if (k == 0 || k == n) {
            return 1;
        }
        return f(n - 1, k - 1) + f(n - 1, k);
    }
    return -1;
}

int main() {
    int n;
    int k;

    printf("Aby obliczyć wartość symbolu Newtona podaj liczby w formacie \"n po k\", gdzie n i k to wybrane liczby:\n");

    scanf("%d po %d", &n, &k);

    int result = f(n, k);

    if (result == -1) {
        printf("Nie można policzyć symbolu Newtona dla danych liczb.\n");
    } else {
        printf("Wartość symbolu Newtona dla (%d po %d) wynosi %d\n", n, k, result);
    }

    return 0;
}
