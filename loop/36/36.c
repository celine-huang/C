#include <stdio.h>
int main(){
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);
	if(year < 1000 || year > 3000 || month < 1 || month > 12 || day < 0 || day > 6){
		printf("invalid\n");
	}else{
		printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
		int days;
		switch(month){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			days = 31;
			break;
			case 4: case 6: case 9: case 11:
			days = 30;
			break;
			case 2:
			if((year%4 == 0 && year%100 != 0) || year%400 == 0){
				days = 29;
			}else{
				days = 28;
			}
			break;
		}
		int i;
		for(i = 0; i < day; i++){
			printf("   ");
		}
		int d = 1;
		for(i = 0; i < 7 - day; i++){
			printf("%3d", d);
			d++;
		}
		printf("\n");
        i = 0;
        while(d <= days){
            if(i >= 7){
                printf("\n");
                i = 0;
            }
            printf("%3d", d);
			d++;
            i++;
		}
        printf("\n=====================\n");
	}
	return 0;
}
