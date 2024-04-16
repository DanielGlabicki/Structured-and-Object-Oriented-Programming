#include <stdio.h>

int fact (int n){
    int factorial = 1;
    for (int i = 1; i <= n ; ++i){
        factorial *= i;
    }
    return factorial;
}

int main() {
    int n = 6;
    printf("%d!=%d\n", n, fact(n));
    return 0;
}
