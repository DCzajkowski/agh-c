/**
 * Zaimplementować strukturę opisującą liczbę zespoloną, a następnie funkcje
 * realizujące podstawowe operacje na liczbach zespolonych
 * (obowiązkowo dodawanie, moduł, liczba sprzężona, nadobowiązkowo odejmowanie,
 * mnożenie dzielenie). Funkcje, których wynikiem działania jest struktura
 * powinny ją zwrócić poprzez return.
 *
 * W wypisywaniu liczby zespolonej można się posłużyć przykładową funkcją:
 * void wypisz_zesp(struct complex z) {
 *     printf("%.2f %+.2fi \n", z.re, z.im);
 * }
 * gdzie z jest zmienną strukturalną o polach re i im (to jest przykładowa
 * struktura - państwo użyją tu własnych struktur).
 */

#include <stdio.h>
#include <math.h>

struct Complex {
    double re;
    double im;
};

struct Complex add_complex(struct Complex z1, struct Complex z2) {
    struct Complex z;
    z.re = z1.re + z2.re;
    z.im = z1.im + z2.im;

    return z;
}

double modulus_complex(struct Complex z) {
    return sqrt(pow(z.re, 2) + pow(z.im, 2));
}

struct Complex conjugate_complex(struct Complex z) {
    z.im = - z.im;

    return z;
}

void print_complex(struct Complex z) {
    if (z.re == 0 && z.im == 0) {
        printf("0");
        return;
    }
    if (z.re == 0) {
        printf("%.0lfi", z.im);
        return;
    }
    if (z.im == 0) {
        printf("%.0lf", z.re);
        return;
    }
    if (z.im < 0) {
        printf("%.0lf - %.0lfi", z.re, -z.im);
        return;
    }
    printf("%.0lf + %.0lfi", z.re, z.im);
}

int main() {
    struct Complex z1;
    z1.re = 0;
    z1.im = 2;

    struct Complex z2;
    z2.re = 4;
    z2.im = 6;

    struct Complex z = add_complex(z1, z2);

    printf("Suma liczby zespolonej ");
    print_complex(z1);
    printf(" oraz ");
    print_complex(z2);
    printf(" to: ");
    print_complex(z);
    printf("\n");

    double modulus = modulus_complex(z);

    printf("Moduł liczby zespolonej ");
    print_complex(z);
    printf(" to: %lf\n", modulus);

    struct Complex conjugate = conjugate_complex(z);

    printf("Sprzężenie liczby zespolonej ");
    print_complex(z);
    printf(" to: ");
    print_complex(conjugate);
    printf("\n");

    return 0;
}
