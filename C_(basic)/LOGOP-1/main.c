#include <stdio.h>

int main() {
    const double a = 3.1;
    const double b = 33.1;
    const double c = -3.1;
    if (a > 0 && b  > 0 && c >0){
        printf("Trzy dodatnie!\n");
        return 0;
    }
    else {
        if ((a > 0 && b > 0) || (a > 0 && c > 0) || (b > 0 && c > 0)){
            printf("Dwie dodatnie!\n");
            return 0;
        }
        else printf("Nic :(\n");
    }

    return 0;
}
