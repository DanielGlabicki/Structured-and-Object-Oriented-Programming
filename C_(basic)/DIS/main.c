#include <stdio.h>

void wyswietl(const int* poczatek, const int* koniec){
    for (const int* ptr = poczatek; ptr < koniec; ptr++){
        printf("%3d ", *ptr);
    }
}

int main() {

    int tab[] = {1,2,3,4,5,6,7};
    int size = sizeof(tab) / sizeof(tab[0]);
    wyswietl(&tab[0],&tab[size]);
    return 0;
}
