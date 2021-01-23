#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int i, comp, out = 0;
    for(i = 7; i > 1; i--){
        comp = (m%(int)pow(10, i) - m%(int)pow(10, i-2)) / pow(10, i-2);
        if(n == comp){
            out++;
        }
    }
    printf("%d\n", out);
    return 0;
}
