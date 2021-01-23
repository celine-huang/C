#include <stdio.h>
#include <stdbool.h>

void printp (int *print, int m, int i) {
    if(i == m - 1){
        printf("%d\n", print[i]);
        return;
    }
    printf("%d ", print[i]);
    printp(print, m, i + 1);
}

bool found (int num, int *print, int m, int i) {
    if(i >= m)
        return false;
    if(num == print[i])
        return true;
    found(num, print, m, i + 1);
}

int find (int *n, int *print, int m, int i) {
    if((found(n[i], print, i, 0)) == false)
        return i;
    find(n, print, m, i + 1);
}

void permutation (int *n, int *print, int m, int i) {
    if(i >= m){
        printp(print, m, 0);
        return;
    }
    print[i] = n[find(n, print, m, i)];
    permutation(n, print, m, i + 1);
}

int main (void) {
    int m;
    scanf("%d", &m);
    int n[m];
    for(int i = 0; i < m; i++)
        scanf("%d", &n[i]);
    //bubbleSort
    int print[m];
    permutation(n, print, m, 0);
    /*for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(j != i){
                for(int k = 0; k < m; k++){
                    if(k != i && k != j){
                        for(int l = 0; l < m; l++){
                            if(l != i && l != j && l != k)
                                printf("%d %d %d %d\n", n[i], n[j], n[k], n[l]);
                        }
                    }
                }
            }
        }
    }*/
    return 0;
}
