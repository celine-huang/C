#include <stdio.h>
int main(){
    int s, f, t, chicken, rabbit, crab;
    scanf("%d%d%d", &s, &f, &t);
    crab = s - t;
    rabbit = f/2 - 4*crab - t;
    chicken = s - crab - rabbit;
    if(chicken<0 || rabbit<0 || crab<0 || f%2!=0){
        printf("0\n");
    }else{
         printf("%d\n%d\n%d\n", chicken, rabbit, crab);
    } 
    return 0;
}

//feet:chicken-2,rabbit-4,crab-8,tail:chicken-1,rabbit-1,crab-0
