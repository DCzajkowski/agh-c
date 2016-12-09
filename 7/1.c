/**
 * Napisz funkcję (rekurencyjną) liczenia n-tego elementu ciągu Fibonacciego.
 */

#include <stdio.h>

int f(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return f(n - 1) + f(n - 2);
}

int main() {
    int n;

    printf("Podaj liczbę n dla której chcesz otrzymać n-ty wyraz ciągu:\n");
    scanf("%d", &n);

    printf("%d-ty wyraz ciągu Fibonacciego to: %d\n", n, f(n));

    return 0;
}
