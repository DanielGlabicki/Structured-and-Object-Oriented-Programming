#include <stdio.h>

int main() {
    int tab[7] = {1, 2, 3, 4, 5, 6, 7};
    int a;
    int size = sizeof (tab) / sizeof (tab[0]);
    for (int i = 0; i < size / 2; ++i){
        a = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = a;
    }
    for (int i = 0; i < size; ++i){
        printf("%2d", tab[i]);
    }
    return 0;
}
