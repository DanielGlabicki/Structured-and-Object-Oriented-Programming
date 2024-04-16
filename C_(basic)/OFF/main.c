#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int v1;
    //double x;
    int v2;
    int adr_v1 = (int) &v1;
    int adr_v2 = (int) &v2;
    printf ("%d\n", adr_v1);
    printf ("%d\n", adr_v2);
    int num_of_cells = adr_v2 - adr_v1;
    printf("Odleglosc v1 od v2 to: %d\n", num_of_cells);
    return EXIT_SUCCESS;
}
