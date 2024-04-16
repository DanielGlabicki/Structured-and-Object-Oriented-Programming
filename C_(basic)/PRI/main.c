#include <stdio.h>
#include <stdbool.h>
int pri(int n, int i) {
    if (i == n) {
        return 1;
    }
    if (n % i == 0) {
        return 0;
    }
    return pri(n, i + 1);
}

bool is_pri(int n) {
    return (n == 0 || n == 1 || pri(n, 2) == 0) ? false : true;
}

int main(void) {
    int n = 4;
    printf("Is %d a prime number? - %d\n", n, is_pri(n));
    return 0;
}
