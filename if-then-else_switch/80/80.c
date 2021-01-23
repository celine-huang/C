#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CO 6 

int main(){
    int n;
    scanf("%d", &n);
    int i, j, array[n][CO];
    for(i=0; i<n; i++){
        for(j=0; j<CO; j++){
            scanf("%d", &array[i][j]);
        }
    }
    float a, b, c;
    for(i=0; i<n; i++){
       a = pow((array[i][0]-array[i][2]), 2) + pow((array[i][1]-array[i][3]), 2);
       b = pow((array[i][0]-array[i][4]), 2) + pow((array[i][1]-array[i][5]), 2);
       c = pow((array[i][2]-array[i][4]), 2) + pow((array[i][3]-array[i][5]), 2);
       if(a==b || b==c || a==c){
           printf("isosceles\n");
       }else{
           if(a+b==c || b+c==a || a+c==b){
               printf("right\n");
           }else if(a+b>c && b+c>a && a+c>b){
               printf("acute\n");
           }else{
               printf("obtuse\n");
           }
       }
    }
    return 0;
}
