#include <stdio.h>

int sum(int n){
    if (n % 10 == n){
        return n;
    }
    return n % 10 + sum((n - n % 10) / 10);
}

int main() {
    int n = 123456;
    printf("Suma cyfr %d wynosi: %d\n", n, sum(n));
    return 0;
}
