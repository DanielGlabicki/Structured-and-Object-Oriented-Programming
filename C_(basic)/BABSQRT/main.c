#include <stdio.h>

int main() {
    const double S = 124.0;
    double x0 = S;
    double x1 = 0.5 * (x0 + S / x0);
    for (int i = 1; x0 - x1 > 0.0001; ++i){
        x0 = x1;
        x1 = 0.5 * (x0 + S / x0);
    }
    printf("Pierwiastek z  %lf to okolo: %lf\n", S, x1);
    return 0;
}
