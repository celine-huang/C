#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CO 8

int main(){
    int n;
    scanf("%d", &n);
    int i, j, array[n][CO];
    for(i=0; i<n; i++){
        for(j=0; j<CO; j++){
            scanf("%d", &array[i][j]);
        }
    }
    float a[n], b[n], c[n], d[n], e[n];
    for(i=0; i<n; i++){
    //cross produst - >0:counterclockwise, <0:clockwise
        if((array[i][0]*array[i][3]+array[i][2]*array[i][5]+array[i][4]*array[i][1])-(array[i][1]*array[i][2]+array[i][3]*array[i][4]+array[i][0]*array[i][5]) > 0){
            if((array[i][4]*array[i][7]+array[i][6]*array[i][1]+array[i][0]*array[i][5])-(array[i][5]*array[i][6]+array[i][7]*array[i][0]+array[i][1]*array[i][4]) > 0){
            //previous three points counterclockwise, fourth point between first and third point
                a[i] = pow((array[i][0]-array[i][2]), 2) + pow((array[i][1]-array[i][3]), 2);
                b[i] = pow((array[i][2]-array[i][4]), 2) + pow((array[i][3]-array[i][5]), 2);
                c[i] = pow((array[i][4]-array[i][6]), 2) + pow((array[i][5]-array[i][7]), 2);
                d[i] = pow((array[i][6]-array[i][0]), 2) + pow((array[i][7]-array[i][1]), 2);
                e[i] = pow((array[i][0]-array[i][4]), 2) + pow((array[i][1]-array[i][5]), 2);
            }else{
                if((array[i][0]*array[i][7]+array[i][6]*array[i][3]+array[i][2]*array[i][1])-(array[i][0]*array[i][3]+array[i][7]*array[i][2]+array[i][1]*array[i][6]) > 0){
                //previous three points counterclockwise, fourth point between first and second point
                    a[i] = pow((array[i][0]-array[i][6]), 2) + pow((array[i][1]-array[i][7]), 2);
                    b[i] = pow((array[i][6]-array[i][2]), 2) + pow((array[i][7]-array[i][3]), 2);
                    c[i] = pow((array[i][2]-array[i][4]), 2) + pow((array[i][3]-array[i][5]), 2);
                    d[i] = pow((array[i][4]-array[i][0]), 2) + pow((array[i][5]-array[i][1]), 2);
                    e[i] = pow((array[i][0]-array[i][2]), 2) + pow((array[i][1]-array[i][3]), 2);
                }else{
                //previous three points counterclockwise, fourth point between second and third point
                    a[i] = pow((array[i][0]-array[i][2]), 2) + pow((array[i][1]-array[i][3]), 2);
                    b[i] = pow((array[i][2]-array[i][6]), 2) + pow((array[i][3]-array[i][7]), 2);
                    c[i] = pow((array[i][6]-array[i][4]), 2) + pow((array[i][7]-array[i][5]), 2);
                    d[i] = pow((array[i][4]-array[i][0]), 2) + pow((array[i][5]-array[i][1]), 2);
                    e[i] = pow((array[i][0]-array[i][6]), 2) + pow((array[i][1]-array[i][7]), 2);
                }
            }
        }else{
            if((array[i][4]*array[i][7]+array[i][6]*array[i][1]+array[i][0]*array[i][5])-(array[i][5]*array[i][6]+array[i][7]*array[i][0]+array[i][1]*array[i][4]) < 0){
            //previous three points clockwise, fourth point between first and third point
                a[i] = pow((array[i][0]-array[i][2]), 2) + pow((array[i][1]-array[i][3]), 2);
                b[i] = pow((array[i][2]-array[i][4]), 2) + pow((array[i][3]-array[i][5]), 2);
                c[i] = pow((array[i][4]-array[i][6]), 2) + pow((array[i][5]-array[i][7]), 2);
                d[i] = pow((array[i][6]-array[i][0]), 2) + pow((array[i][7]-array[i][1]), 2);
                e[i] = pow((array[i][0]-array[i][4]), 2) + pow((array[i][1]-array[i][5]), 2);
            }else{
                if((array[i][0]*array[i][7]+array[i][6]*array[i][3]+array[i][2]*array[i][1])-(array[i][0]*array[i][3]+array[i][7]*array[i][2]+array[i][1]*array[i][6]) < 0){
                //previous three points clockwise, fourth point between first and second point
                    a[i] = pow((array[i][0]-array[i][6]), 2) + pow((array[i][1]-array[i][7]), 2);
                    b[i] = pow((array[i][6]-array[i][2]), 2) +pow((array[i][7]-array[i][3]), 2);
                    c[i] = pow((array[i][2]-array[i][4]), 2) +pow((array[i][3]-array[i][5]), 2);
                    d[i] = pow((array[i][4]-array[i][0]), 2) +pow((array[i][5]-array[i][1]), 2);                
                    e[i] = pow((array[i][0]-array[i][2]), 2) + pow((array[i][1]-array[i][3]), 2);
                }else{
                //previous three points clockwise, fourth point between second and third point
                    a[i] = pow((array[i][0]-array[i][2]), 2) +pow((array[i][1]-array[i][3]), 2);
                    b[i] = pow((array[i][2]-array[i][6]), 2) +pow((array[i][3]-array[i][7]), 2);
                    c[i] = pow((array[i][6]-array[i][4]), 2) +pow((array[i][7]-array[i][5]), 2);
                    d[i] = pow((array[i][4]-array[i][0]), 2) +pow((array[i][5]-array[i][1]), 2);
                    e[i] = pow((array[i][0]-array[i][6]), 2) + pow((array[i][1]-array[i][7]), 2);
                }
            }
        }
    }
    for(i=0; i<n; i++){
        if(a[i]==b[i] && b[i]==c[i] && c[i]==d[i]){
            if(a[i]+b[i]==e[i]){
                printf("square\n");
            }else{
                printf("diamond\n");
            }
        }else if(a[i]+b[i]==e[i]){
            printf("rectangle\n");
        }else{
            printf("other\n");
        }
    }
    return 0;
}
