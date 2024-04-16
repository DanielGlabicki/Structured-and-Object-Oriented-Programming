#include <stdio.h>

double expression (double x){
    return (x * x * x + 3 * x)/(x * x + 6);
}

int main() {
    double x = 4.21;
    printf("f(%f)=%f\n", x, expression(x));
    return 0;
}
