#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n;
    scanf("%d", &n);
    int prob[n*(n+1)/2][2];
    for(int i = 0; i < n*(n+1)/2; i++){
        scanf("%d%d", &prob[i][0], &prob[i][1]);
    }
    int q[(int)pow(2, n-1)], p[(int)pow(2, n-1)];
    for(int i = 0; i < (int)pow(2, n-1); i++){
        q[i] = 1;
        p[i] = 1;
    }
    for(int i = 0; i < (int)pow(2, n-1); i++){
        for(int j = 0; j < ){
            q[i] = 
        }
    }
    return 0;
}
