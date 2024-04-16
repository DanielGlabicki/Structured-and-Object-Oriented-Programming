#include <stdio.h>

void triangle (int a, int b, int c){
    if ((a + b > c) && (a + c > b) && (b + c > a)){
        printf ("Z %d, %d, %d da sie zbudowac trojkat.\n", a, b, c);
    }
    else printf ("Z %d, %d, %d nie da sie zbudowac trojkata.\n", a, b, c);
}

int main() {
    triangle(1, 2, 3);
    triangle (3, 3, 3);
    return 0;
}
