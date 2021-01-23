#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int x_park[n], y_park[n], cap_park[n], i;
    for(i = 0; i < n; i++){
        scanf("%d%d%d", &x_park[i], &y_park[i], &cap_park[i]);
    }
    int m;
    scanf("%d", &m);
    int x_bike[m], y_bike[m];
    for(i = 0; i < m; i++){
        scanf("%d%d", &x_bike[i], &y_bike[i]);
    }
    int j, distance[m][n];
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(x_park[j] >= x_bike[i] && y_park[j] >= y_bike[i]){
                distance[i][j] = (x_park[j] - x_bike[i]) + (y_park[j] - y_bike[i]);
            }else if(x_park[j] < x_bike[i] && y_park[j] >= y_bike[i]){
                distance[i][j] = (x_bike[i] - x_park[j]) + (y_park[j] - y_bike[i]);
            }else if(x_park[j] >= x_bike[i] && y_park[j] < y_bike[i]){
                distance[i][j] = (x_park[j] - x_bike[i]) + (y_bike[i] - y_park[j]);
            }else{
                distance[i][j] = (x_bike[i] - x_park[j]) + (y_bike[i] - y_park[j]);
            }
        }
    }
    for(i = 0; i < m; i++){

    }
    for(i = 0; i < n; i++){
        printf("%d\n", );
    }
    return 0;
}
