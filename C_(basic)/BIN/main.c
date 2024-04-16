#include <stdio.h>
#include <stdlib.h>

void binary (int n){
    int rest = n % 2;
    if (n > 0){
        binary ((n - rest) / 2);
    } else {
        printf ("\n");
    }
    printf ("%d", rest);
}

int main(void) {
    binary (15);
    binary (16);
    binary (17);
    binary (217);
    return 0;
}
