#include <stdio.h>
int main(){
    int x;
    scanf("%d", &x);
    if(x%3==0 && x%5==0 && x%7!=0){
           printf("0\n");
    }else{
        printf("1\n");
    }
    return 0;
}
