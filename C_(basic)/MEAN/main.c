#include <stdio.h>

double mean (double a, double b, double c){
    return (a + b + c) / 3;
}

int main() {
    double a = 2.4;
    double b = 3.2;
    double c = 34;
    printf("Sredania %.3f, %.3f, %.3f wynosi %.4f.\n", a,b,c, mean(a,b,c));
    return 0;
}
