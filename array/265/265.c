#include <stdio.h>
int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    int minx = x, maxx = x, miny = y, maxy = y;
    while(scanf("%d%d", &x, &y) != EOF){
        if(x > maxx)
            maxx = x;
        else if(x < minx)
            minx = x;
        if(y > maxy)
            maxy = y;
        else if(y < miny)
            miny = y;
    }
    printf("%d\n", (maxx - minx) * (maxy - miny));
    return 0;
}
