#include <stdio.h>

int sqeq(int a, int b, int c){
    int delta = b * b - 4 * a * c;
    if (delta > 0) return 2;
    else if (delta == 0) return 1;
    else return 0;
}


int main() {
    int a = 2;
    int b = 4;
    int c = 1;
    printf("Ilosc rozw %d * x^2 + %d * x + %d to %d.\n", a,b,c, sqeq(a,b,c));
    return 0;
}
