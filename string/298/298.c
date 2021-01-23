#include <stdio.h>
#include <string.h>

enum OutputType{CORRECT, CANDIDATE, MISSPELL};
enum DiffType{LESS = 1, DIFF, MORE};

int main(void){
    int dictnum;
    scanf("%d", &dictnum);
    char dict[dictnum][100000];
    for(int i = 0; i < dictnum; i++)
        scanf("%s", dict[i]);
    int wordnum;
    scanf("%d", &wordnum);
    char word[wordnum][100000];
    for(int i = 0; i < wordnum; i++){
        scanf("%s", word[i]);
        int output[3] = {-1, -1, -1};
        int diff[dictnum];
        for(int j = 0; j < dictnum; j++){
            diff[j] = 0;
            int k = 0;
            while(word[i][k] != '\0'){
                if(output[MISSPELL] == j)
                    break;
                switch(diff[j]){
                    case LESS:
                        if(word[i][k] != dict[j][k+1]){
                            output[MISSPELL] = j;
                        }
                        break;
                    case DIFF:
                        if(word[i][k+1] != dict[j][k+1]){
                            output[MISSPELL] = j;
                        }
                        break;
                    case MORE:
                        if(word[i][k+1] != dict[j][k]){
                            output[MISSPELL] = j;
                        }
                        break;
                    default:
                        if(word[i][k] != dict[j][k]){
                            if(word[i][k] == dict[j][k+1])
                                diff[j] = LESS;
                            else if(word[i][k+1] == dict[j][k+1])
                                diff[j] = DIFF;
                            else if(word[i][k+1] == dict[j][k])
                                diff[j] = MORE;
                            else{
                                output[MISSPELL] = j;
                            }
                        }else{
                            output[CORRECT] = j;
                        }
                }
                k++;
            }
        }
		if(output[CORRECT] != -1)
			printf(">%s", dict[output[CORRECT]]);
		else{
			int flag = 0;
			for(int j = 0; j < dictnum; j++){
				if(diff[j] != 0 && flag == 0){
					printf("?%s ", dict[j]);
					flag = 1;				
				}else if(diff[j] != 0 && flag == 1)
					printf("%s ", dict[j]);
			}
			if(flag == 0)
				printf("!aple");
		}
		printf("\n");
    }
    return 0;
}
