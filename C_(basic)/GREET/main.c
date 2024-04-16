#include <stdio.h>

void powitaj(int ile_razy){
    for (int i = 1; i <= ile_razy; ++i){
        printf("Dzien dobry!\n");
    }
}

int main() {
    powitaj (6);
    return 0;
}
