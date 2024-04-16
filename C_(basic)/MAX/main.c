#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int main() {
    int a = 42;
    int b = 43;
    printf ("max(41,42) = %d\n", max (a,b));
    return 0;
}
