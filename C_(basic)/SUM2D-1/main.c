#include <stdio.h>

#define N 5 //rows
#define M 4 //cols

int main(void) {
    int tab2D[N][M];
    int sum = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            tab2D[i][j] = i + 2 *j;
        }
    }
    for (int i = 0; i < N; i += 2){
        for (int j = 0; j < M; ++j){
            sum += tab2D[i][j];
        }
    }
    for (int i = 0; i< N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%3d",tab2D[i][j]);
        }
        printf("\n");
    }
    printf("%3d", sum);
    return 0;
}
