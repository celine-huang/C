#include <stdio.h>
#include <assert.h>

int combination(int n, int k);

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    assert(0 < n && n < 15 && 0 <= m && m <= n);
    printf("%d\n", combination(n, m));
    return 0;
}

int combination(int n, int k){
    if(k == 0 || k == n)
        return 1;
    else
        return combination(n - 1, k) + combination(n - 1, k - 1);
}
