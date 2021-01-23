#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int m;
    scanf("%d", &m);
    int r[m];
    for(int i = 0; i < m; i++){
        r[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int rem;
        rem = arr[i]%m;
        r[rem]++;
    }
    for(int i = 0; i < m; i++){
        printf("%d\n", r[i]);
    }
    return 0;
}
