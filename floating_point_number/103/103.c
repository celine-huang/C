#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    double a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);
    double y[n];
    for(int i = 0; i < n; i++)
        scanf("%lf", &y[i]);
    double x[n];
    for(int i = n - 1; i >= 0; i--){
        x[i] = y[i];
        for(int j = n - 1; j > i; j--)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }
    for(int i = 0; i < n; i++)
        printf("%f\n", x[i]);
    return 0;
}
