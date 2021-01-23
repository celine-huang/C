#include <stdio.h>
int main(){
    int a, b, c, d, e, f, g, h, i, j;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    switch(d){
        case 0://+
            h = a + e;
            if(a < 0){
                i = -b*g + c*f;
            }else if(e < 0){
                i = b*g - c*f;
            }else{
                i = b*g + c*f;
            }
            j = c*g;
            break;
        case 1://-
            h = a - e;
            if(a < 0){
                i = -b*g - c*f;
            }else if(e < 0){
                i = b*g + c*f;
            }else{
                i = b*g - c*f;
            }
            j = c*g;
            break;
        case 2://*
            h = a*e;
            if(a < 0){
                i = a*f*c - b*e*g - b*f;
            }else if(e < 0){
                i = -a*f*c + b*e*g - b*f;
            }else{
                i = a*f*c + b*e*g + b*f;
            }
            j = c*g;
            break;
        case 3:///
            h = 0;
            if(a < 0){
                i = a*c*g - b*g;
                j = c*e*g + c*f;
            }else if(e < 0){
                i = a*c*g + b*g;
                j = c*e*g - c*f;
            }else{
                i = a*c*g + b*g;
                j = c*e*g + c*f;
            }
            break;
    }
    if(i/j>=1){
        i = i%j;
        h = h + i/j;
    }
    if(h<0 && i<0){
        i = -i;
    }else if(h>0 && i<0){
        h = h - 1;
        i = j + i;
    }else if(h<0 && i>0){
        h = h + 1;
        i = j - i;
    }
    while(i!=0 && j!=0){
        if(i > j){
            i = i%j;
        }else(j > i){
            j = j%i;
        }
    }
	 if(a >= b){
		  i = i/a;
		  j = j/a;
	 }else{
		  i = i/b;
        j = j/b;	
	 }
    printf("%d\n%d\n%d\n", h, i, j);
    return 0;
}
