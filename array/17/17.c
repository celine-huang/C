#include <stdio.h>
int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    int mat[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int ave[c];
    for(int i = 0; i < c; i++){
        ave[i] = 0;
        for(int j = 0; j < r; j++){
            ave[i] += mat[j][i];
        }
        ave[i] /= r;
        printf("%d\n", ave[i]);
    }
}
