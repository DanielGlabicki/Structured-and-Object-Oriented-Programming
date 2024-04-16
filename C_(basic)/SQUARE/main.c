#include <stdio.h>

int main() {
    const int n = 6;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf ("%3d",(i + j) % n + 1);
        }
        printf("\n");
    }
    return 0;
}
