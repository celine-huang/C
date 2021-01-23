#include <stdio.h>
int main(){
	int w, d;
	scanf(“%d”, &w, &d);
	int mirror[d][w], i, j;
	for(i = 0; i < d; i++){
		for(j = 0; j < w; j++){
			scanf(“%d”, &mirror[i][j]);
		}
	}
	for(i = 0; i < w; i++){
		if(mirror[d][i] == 0){//up
			d—-;
			
		}else{
			i++;
		}
		if()
		
	}
	return 0;
}