#include <stdio.h>

int fact(int n){
    if (n == 0){
        return 1;
    }
    return n * fact(n-1);
}


int main() {
    printf ("5! = %d\n",fact(5));
    printf ("0! = %d\n",fact(0));
    printf ("3! = %d\n",fact(3));
    return 0;
}
