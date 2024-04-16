#include <stdio.h>
#include <stdlib.h>

#define N 5 //rows
#define M 4 //cols

int main(void) {
    int tab2D[N][M];
    int sum;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            tab2D[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i< N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%3d",tab2D[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; ++i) {
        sum = 0;
        for (int j = 0; j < M; ++j) {
            sum += tab2D[i][j];
        }
        printf("Row %d: %d\n", i, sum);
    }
    for (size_t j = 0; j < M; ++j) {
        sum = 0;
        for (size_t i = 0; i < N; ++i) {
            sum += tab2D[i][j];
        }
        printf("Col %d: %d\n", j, sum);
    }
    return 0;
}