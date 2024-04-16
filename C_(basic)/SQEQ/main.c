#include <stdio.h>

int main() {
    const float a = 2;
    const float b = 4;
    const float c = 2;
    float delta = b * b - 4 * a * c;
    if (delta > 0){
        printf("Dwa rozwiazania");
    }else if(delta == 0){
        printf("Jedno rozwiazanie");
    }else printf("Brak rozwiazan");
    return 0;
}
