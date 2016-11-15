/**
 * Napisz program, w którym do tablicy liczb rzeczywistych wpisywanych jest 5 liczb z klawiatury.
 * Następnie należy policzyć średnią wartości z tablicy oraz ich wariancję.
 */

#include <stdio.h>
#include <math.h>
#define SIZE 5

int main()
{
    double array[SIZE];

    /**
     * Reading into an array
     */

    for (int i = 0; i < SIZE; i++) {
        scanf("%lf", &array[i]);
    }

    /**
     * Counting the average
     */
    double average = 0;

    for (int i = 0; i < SIZE; i++) {
        average = average + array[i];
    }

    average = average / SIZE;

    printf("Średnia wartość podanych liczb to: %.2lf\n", average);

    /**
     * Counting the variance
     */
    double variance = 0;

    for (int i = 0; i < SIZE; i++) {
        variance += pow(array[i] - average, 2);
    }

    variance = variance / SIZE;

    printf("Wariancja podanych liczb to: %.2lf\n", variance);

    return 0;
}
