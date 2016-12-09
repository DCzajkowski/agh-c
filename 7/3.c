/**
 * Napisz rekurencyjną funkcję, która policzy dla liczby rzeczywistej wartość potęgi o wykładniku
 * naturalnym. Należy wykorzystać fakt, że n-tą potęgę można wyrazić za pomocą n-1 potęgi.
 */

#include <stdio.h>

double f(double x, int n) {
    if (n == 0) {
        return 1;
    }
    return f(x, n - 1) * x;
}

int main() {
    double x;
    int n;

    printf("Aby obliczyć wartość potęgi podaj liczby w formacie \"x^n\", gdzie x i n to wybrane liczby:\n");

    scanf("%lf^%d", &x, &n);

    if (x == 0 && n == 0) {
        printf("Nie można policzyć symbolu nieoznaczonego 0^0.\n");
    } else {
        printf("Wartość potęgi (%.2lf^%d) wynosi %.2lf\n", x, n, f(x, n));
    }

    return 0;
}
