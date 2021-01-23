#include <stdio.h>

int operation (int multiplyA, int targetA, int multiplyB, int targetB) {
    return (multiplyA * targetA - multiplyB * targetB);
}

void cases (int n, int DA, int DB, int DC, int EA, int EB, int EC, int FA, int FB, int FC) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int unitA, unitB, unitC;
    int co = operation(operation(DC, EB, DB, EC), operation(DB, FA, DA, FB), operation(DB, EA, DA, EB), operation(DC, FB, DB, FC));
    int total = operation(operation(DC, EB, DB, EC), operation(DB, a, DA, b), operation(DB, EA, DA, EB), operation(DC, b, DB, c));
    if(total % co == 0 && total / co >= 0)
        unitC = total / co;
    else{
        printf("no\n");
        return;
    }
    co = operation(DB, EA, DA, EB);
    total = operation(DB, a, DA, b) - operation(DB, FA, DA, FB) * unitC;
    if(total % co == 0 && total / co >= 0)
        unitB = total / co;
    else{
        printf("no\n");
        return;
    }
    co = DA;
    total = a - EA * unitB - FA * unitC;
    if(total % co == 0 && total / co >= 0)
        unitA = total / co;
    else{
        printf("no\n");
        return;
    }
    printf("yes\n");
}

int main (void) {
    int DA, DB, DC, EA, EB, EC, FA, FB, FC;
    scanf("%d%d%d%d%d%d%d%d%d", &DA,&DB, &DC, &EA, &EB, &EC, &FA, &FB, &FC);
    int n;
    scanf("%d", &n);
    int ct = 0;
    while(ct < n){
        cases(n, DA, DB, DC, EA, EB, EC, FA, FB, FC);
        ct++;
    }
    return 0;
}
