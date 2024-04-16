#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    int tab[SIZE];
    int i = 0;
    while (i < SIZE){
        tab[i] = rand() % 100;
        printf("%3d", tab[i]);
        ++i;
    }
    return 0;
}
