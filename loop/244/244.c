#include <stdio.h>
int main(){
    int special[3], first[3], i;
    for(i = 0; i < 3; i++)
        scanf("%d", &special[i]);
    for(i = 0; i < 3; i++)
        scanf("%d", &first[i]);
    int n, dollar = 0;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < 3; i++){
            if(n == special[i]){
                dollar += 2000000;
            }
        }
        for(i = 0; i < 3; i++){
            if(n == first[i]){
                dollar += 200000;
            }else if(n%10000000 == first[i]%10000000){
                dollar += 40000;
            }else if(n%1000000 == first[i]%1000000){
                dollar += 10000;
            }else if(n%100000 == first[i]%100000){
                dollar += 4000;
            }else if(n%10000 == first[i]%10000){
                dollar += 1000;
            }else if(n%1000 == first[i]%1000){
                dollar += 200;
            }
        }
    }
    printf("%d\n", dollar);
    return 0;
}
