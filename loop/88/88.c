#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int i, j, a = 0, b = 0, guess, ans;
    for(i = 4; i > 0; i--){
        guess = (n%(int)pow(10, i) - n%(int)pow(10, i-1)) / pow(10, i-1);
        for(j = 4; j > 0; j--){
            ans = (m%(int)pow(10, j) - m%(int)pow(10, j-1)) / pow(10, j-1);
            if(i == j && guess == ans){
                a++;
            }else if(i != j && guess == ans){
                b++;
            }
        }
    }
    printf("%dA%dB\n", a, b);
    return 0;
}
