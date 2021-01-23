#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int f[n];
    for(int i = n-1; i >= 0; i--){
        scanf("%d", &f[i]);
    }
    int m;
    scanf("%d", &m);
    int g[m];
    for(int i = m-1; i >= 0; i--){
        scanf("%d", &g[i]);
    }
    int co[m+n-1];
    for(int i = 0; i <= m+n-2; i++){
        co[i] = 0;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >=0; j--){
            co[i+j] += f[i]*g[j];            
        }
    }
    for(int i = m+n-2; i >= 0; i--){
        printf("%d ", co[i]);
    }
    printf("\n");
    return 0;
}
