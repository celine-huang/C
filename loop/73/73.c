#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int num[n], i, out[3] = {0};
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
        if(num[i]%3 == 0){
            out[0]++;
        }else if(num[i]%3 == 1){
            out[1]++;
        }else if(num[i]%3 == 2){
            out[2]++;
        }
    }
    for(i = 0; i < 3; i++){
        printf("%d ", out[i]);
    }
    printf("\n");
    return 0;
}
