/**
 * Napisz program wyliczający ile minut (średnio) masz na wykonanie każdego z zadań zakładając, że pozostało 75 minut zajęć.
 * Zadanie należy wykonać w dwóch wariantach: na liczbach rzeczywistych i liczbach całkowitych.
 * Z czego wynika ewentualna różnica w uzyskanym wyniku?
 */

#include <stdio.h>

int main()
{
    double time = 75;
    double number_of_exercises = 9;

    int result = time / number_of_exercises;
    float result_in_real = time / number_of_exercises;

    printf("Czas na jedno zadanie w calkowitych to %d, a w rzeczywistych to %f\n", result, result_in_real);

    return 0;
}
