#include <stdio.h>
#define SIZE 4

int main(void) {
    double tab[SIZE];
    tab[0] = 1.0;
    tab[1] = 2.0;
    tab[2] = 3.0;
    tab[3] = 4.0;
    double sum = 0;
    for (int i = 0; i < SIZE; ++i){
        sum += tab[i];
    }
    printf("%4.2lf\n", sum);
    return 0;
}
