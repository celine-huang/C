#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int main(void){
    int m, n;
    scanf("%d%d", &m, &n);
    assert(m >= 3 && m <= 100 && n >= 3 && n <= 100);
    char map[m][n];
    int ct = 0;
    while(ct < m * n){
        char c;
        scanf("%c", &c);
        if(isgraph(c)){
            map[ct/n][ct%n] = c;
            ct++;
        }
    }
    int dm, dn;
    scanf("%d%d", &dm, &dn);
    char dir = ' ';
    while(isspace(dir)){
        scanf("%c", &dir);
    }
    int f;
    scanf("%d", &f);
    assert(f >= 0 && f <= 10000);
    for(int i = f; i > 0; i--){
		switch(dir){
			case 'N':
            	if(map[dm-1][dn] == '.'){
                	dm--;
                    dir = 'N';
                }else if(map[dm][dn+1] == '.'){
                    dn++;
                    dir = 'E';
                }else if(map[dm][dn-1] == '.'){
                    dn--;
                    dir = 'W';
                }else{
                    dm++;
                    dir = 'S';
                }
		        break;
            case 'W':
                if(map[dm][dn-1] == '.'){
                    dn--;
                    dir = 'W';
                }else if(map[dm-1][dn] == '.'){
                    dm--;
                    dir = 'N';
                }else if(map[dm+1][dn] == '.'){
                    dm++;
                    dir = 'S';
                }else{
                    dn++;
                    dir = 'E';
                }
                break;
            case 'E':
                if(map[dm][dn+1] == '.'){
                    dn++;
                    dir = 'E';
                }else if(map[dm+1][dn] == '.'){
                    dm++;
                    dir = 'S';
                }else if(map[dm-1][dn] == '.'){
                    dm--;
                    dir = 'N';
                }else{
                    dn--;
                    dir = 'W';
                }
                break;
            case 'S':
    	        if(map[dm+1][dn] == '.'){
                    dm++;
                    dir = 'S';
                }else if(map[dm][dn-1] == '.'){
                    dn--;
                    dir = 'W';
                }else if(map[dm][dn+1] == '.'){
                    dn++;
                    dir = 'E';
                }else{
                    dm--;
                    dir = 'N';
                }
                break;
    	}
	}
    printf("%d %d\n", dm, dn);
    return 0;
}

