#include <stdio.h>
#include <assert.h>

int combination(int n, int k);

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    assert(0 < n && n < 15 && 0 <= m && m <= n);
    int sum = 0;
    int i = 0;
    while(i <= m){
        sum += combination(n, i);
        i++;
    }
    printf("%d\n", sum);
    return 0;
}

int combination(int n, int k){
    int c = 1;
    for(int i = k+1; i <= n; i++)
        c *= i;
    for(int i = 1; i <= n - k; i++)
        c /= i;
    return c;
}
