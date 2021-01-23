#include <stdio.h>
#define SIZE 400

void lakesize(int picture[][SIZE], int m, int n, int cell, int size){
    if(picture[cell/n][cell%n] == 1){
        size++;
        picture[cell/n][cell%n] = -1;
    }
    if(cell%n+1 < n){//right
        lakesize(picture, m, n, cell + 1, size);
    }
    if(cell/n-1 >= 0){//up
        lakesize(picture, m, n, cell - n, size);
    }
    if(cell%n-1 >= 0){//left
        lakesize(picture, m, n, cell - 1, size);
    }
    if(cell/n+1 < m){//down
        lakesize(picture, m, n, cell + n, size);
    }
    return;
}

void scan(int picture[][SIZE], int lake[], int m, int n, int cell, int num){
    if(cell >= m * n)
        return;
    if(picture[cell/n][cell%n] == 1){
        lakesize(picture, m, n, cell, 0);
        scan(picture, lake, m, n, cell + 1, num + 1);
    }
    scan(picture, lake, m, n, cell + 1, num);
}

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    int picture[SIZE][SIZE];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &picture[i][j]);
    int lake[n*m/2+1];
    scan(picture, lake, m, n, 0, 0);
    return 0;
}
