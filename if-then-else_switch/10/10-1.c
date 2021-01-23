#include <stdio.h>
int main(){
    int n, i, j, pro=1;
    scanf("%d%d", &n, &i);
    for(j=0; j<i; j++){
        pro = pro*n;
    }
    printf("%d\n", pro);
    return 0;
}
