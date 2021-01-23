#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int i, j, x[n][3], y[n][3], r[n][3];
    for(i = 0; i < n; i++){
        for(j = 0; j < 3; j++){
            scanf("%d%d%d", &x[i][j], &y[i][j], &r[i][j]);
        }
    }
    int xt, yt, dot[n];
    for(i = 0; i < n; i++){
        for(j = 0; j < 3; j++){
            for(xt = x[i][j] - r[i][j]; xt < x[i][j] + r[i][j]; xt++){
                for(yt = y[i][j] - r[i][j]; yt < y[i][j] + r[i][j]; yt++){
						if((xt - x[i][0])*(xt - x[i][0]) + (yt - y[i][0])*(yt - y[i][0]) <= r[i][0]*r[i][0] && (xt - x[i][1])*(xt - x[i][1]) + (yt - y[i][1])*(yt - y[i][1]) > r[i][1]*r[i][1] && (xt - x[i][2])*(xt - x[i][2]) + (yt - y[i][2])*(yt - y[i][2]) > r[i][2]*r[i][2]){
							dot[i]++;
						}else if((xt - x[i][0])*(xt - x[i][0]) + (yt - y[i][0])*(yt - y[i][0]) > r[i][0]*r[i][0] && (xt - x[i][1])*(xt - x[i][1]) + (yt - y[i][1])*(yt - y[i][1]) <= r[i][1]*r[i][1] && (xt - x[i][2])*(xt - x[i][2]) + (yt - y[i][2])*(yt - y[i][2]) > r[i][2]*r[i][2]){
                      dot[i]++;
                   }else if((xt - x[i][0])*(xt - x[i][0]) + (yt - y[i][0])*(yt - y[i][0]) > r[i][0]*r[i][0] && (xt - x[i][1])*(xt - x[i][1]) + (yt - y[i][1])*(yt - y[i][1]) > r[i][1]*r[i][1] && (xt - x[i][2])*(xt - x[i][2]) + (yt - y[i][2])*(yt - y[i][2]) <= r[i][2]*r[i][2]){
                      dot[i]++;
                   }else if((xt - x[i][0])*(xt - x[i][0]) + (yt - y[i][0])*(yt - y[i][0]) <= r[i][0]*r[i][0] && (xt - x[i][1])*(xt - x[i][1]) + (yt - y[i][1])*(yt - y[i][1]) <= r[i][1]*r[i][1] && (xt - x[i][2])*(xt - x[i][2]) + (yt - y[i][2])*(yt - y[i][2]) <= r[i][2]*r[i][2]){
                      dot[i]++;
                   }
					}
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d\n", dot[i]);
    }
    return 0;
}
