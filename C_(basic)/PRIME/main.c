#include <stdio.h>

int main() {
    int n = 127;
    int composite = 0;
    for(int i = 2; i < n; ++i){
        if (n % i == 0) ++composite;
    }
    if (composite == 0){
        printf("Liczba pierwsza\n");
        return 0;
    }
    printf("Liczba zlozona\n");
    return 0;
}
