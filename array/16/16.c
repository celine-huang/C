#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int array[n], i, odd[n], even[n], oddnum = 0, evennum = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
        if(array[i]%2 == 1){
            odd[oddnum] = array[i];
            oddnum++;
        }else{
            even[evennum] = array[i];
            evennum++;
        }
    }
    for(i = 0; i < oddnum - 1; i++){
        printf("%d ", odd[i]);
    }
    printf("%d\n", odd[oddnum - 1]);
    for(i = 0; i < evennum - 1; i++){
        printf("%d ", even[i]);
    }
    printf("%d\n", even[evennum - 1]);
    return 0;
}
