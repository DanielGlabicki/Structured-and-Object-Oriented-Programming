#include <stdio.h>
#define SIZE 5
int main(void) {
    int tab[SIZE] = {1, 2, 3, 4, 5};
    int max = tab[0];
    for (int i = 1 ; i < sizeof (tab)/sizeof (tab[0]); ++i){
        if (tab[i] > max){
            max = tab[i];
        }
    }
    printf("max = %d\n", max);
    return 0;
}
