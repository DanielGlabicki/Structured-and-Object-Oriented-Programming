#include <stdio.h>

int main() {
    const int x = 4;
    if (3 <= x && x < 6){
        printf("Nierownosc spelniona!\n");
    } else {
        printf("Nierownosc niespelniona!\n");
    }
    return 0;
}
