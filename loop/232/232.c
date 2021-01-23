#include <stdio.h>
int main(){
    int year, firstday, cases;
    scanf("%d%d%d", &year, &firstday, &cases);
    int i, month[cases], day[cases];
    for(i = 0; i < cases; i++){
        scanf("%d%d", &month[i], &day[i]);
    }
    int days[12];
    for(i = 0; i < 12; i++){
        switch(i+1){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days[i] = 31;
                break;
            case 4: case 6: case 9: case 11:
                days[i] = 30;
                break;
            case 2:
                if((year%4 == 0 && year%100 != 0) || year%400 == 0){
                    days[i] = 29;
                }else{
                    days[i] = 28;
                }
                break;
        }
    }
    int j, totaldays = 0, output;
    for(i = 0; i < cases; i++){
        if(month[i] < 1 || month[i] > 12){
            printf("-1\n");
        }else if(day[i] < 1 || day[i] > days[month[i]-1]){
            printf("-2\n");
        }else{
            totaldays = 0;
            for(j = 1; j < month[i]; j++){
                totaldays += days[j-1];
            }
            totaldays += day[i];
            output = firstday - 1 + totaldays%7;
            if(output > 6){
                printf("%d\n", output - 7);
            }else if(output < 0){
                printf("%d\n", output + 7);
            }else{
                printf("%d\n", output);
            }
        }
    }
    return 0;
}
