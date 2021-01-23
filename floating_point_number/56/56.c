#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pos 16

int move(double x, double y, double R, double a, double b, double c, double d, double e, double f);
double resistance(double x, double y, double a, double b, double c, double d, double e, double f);

int main(void){
    double x, y, R, a, b, c, d, e, f, g, dt, T;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &x, &y, &R, &a, &b, &c, &d, &e, &f, &g, &dt, &T);
    printf("%.3lf %.3lf\n", x, y);
    double dx = x, dy = y;
    for(int ct = 0; ct < T / dt; ct++){
        dx = dx + g * dt * cos(M_PI / 8 * move(dx, dy, R, a, b, c, d, e, f));
        dy = dy + g * dt * sin(M_PI / 8 * move(dx, dy, R, a, b, c, d, e, f));
        if(dx <= 0.000 && dx > -0.001)
            dx = 0;
        if(dy <= 0.000 && dy > -0.001)
            dy = 0;
        printf("%.3lf %.3lf\n", dx, dy);
    }
    return 0;
}

int move(double x, double y, double R, double a, double b, double c, double d, double e, double f){ 
    int dir = 0;
    double dr = 0;
    for(int i = 0; i < pos; i++){
        double dx = x + R * cos(M_PI / 8 * i);
        double dy = y + R * sin(M_PI / 8 * i);
        double tr = resistance(dx, dy, a, b, c, d, e, f);
        if(i == 0 || tr < dr){
            dr = tr;
            dir = i;
        }
    }
    return dir;
}

double resistance(double x, double y, double a, double b, double c, double d, double e, double f){
    return a * x * x + b * x * y + c * y * y + d * x + e * y + f;
}
