#include <stdlib.h>
#include <stdio.h>

void zamien(int* pa, int* pb){
    int c = *pa;
    *pa = *pb;
    *pb = c;
}

int main(void) {
    int a = 4;
    int b = 5;

    zamien(&a, &b);

    if (a == 5 && b == 4) {
        printf("OK\n");
    } else {
        printf("Cos poszlo nie tak...\n");
    }

    return EXIT_SUCCESS;
}