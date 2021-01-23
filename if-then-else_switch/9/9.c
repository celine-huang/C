#include <stdio.h>
int main(){
    int x, score;
    scanf("%d", &x);
    if(x==0 || x<0){
        score = -100;
    }else{
        score = 0;
        if(x%3==0){
            score = score + 3;
        }
        if(x%5==0){
            score = score + 5;
        }
        if(x>=100 && x<=200){
            score = score + 50;
        }else{
            score = score - 50;
        }
    }
    printf("%d\n", score);
    return 0;
}
