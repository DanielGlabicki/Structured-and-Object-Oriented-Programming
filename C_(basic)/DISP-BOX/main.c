#include <stdio.h>

void box(int rows, int cols){
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= cols; j++){
            printf ("$");
        }
        printf ("\n");
    }
}

int main() {
    box(2,4);
    return 0;
}
