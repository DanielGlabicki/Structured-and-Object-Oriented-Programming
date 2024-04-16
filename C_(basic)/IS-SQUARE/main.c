#include <stdio.h>

int is_sq(int n){
    for (int i = 1; i <= n; ++i){
        if (i*i == n) return 1;
    }
    return 0;
}

int main() {
    int  n1 = 121;
    int n2 = 124;
    printf("Czy %d ma pierwiastek calkowity? %d\n", n1, is_sq(n1));
    printf("Czy %d ma pierwiastek calkowity? %d\n", n2, is_sq(n2));
    return 0;
}
