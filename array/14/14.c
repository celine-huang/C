#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int array[n], i;
    for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    for(i = n - 1; i > 0; i--){
        printf("%d ", array[i]);
    }
    printf("%d\n", array[0]);
    return 0;
}
