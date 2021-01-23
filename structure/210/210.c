#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define FIELDNUM 8
#define STRINGLENGTH 80

enum field {LASTNAME, FIRSTNAME, ID, SALARY, AGE};
enum operator {EQL, NOTEQL, LARGER, SMALLER};

typedef struct database {
    char lastname[STRINGLENGTH];
    char firstname[STRINGLENGTH];
    char ID[STRINGLENGTH];
    int salary;
    int age;
} Database;

typedef struct command {
    int field[FIELDNUM];
    int fieldnum;
    int opd1;
    int opr;
    char opd2Str[STRINGLENGTH];
    int opd2Num;
} Command;

void readData (Database *database, int n) {
    scanf("%s", database[n].lastname);
    scanf("%s", database[n].firstname);
    scanf("%s", database[n].ID);
    scanf("%d", &database[n].salary);
    scanf("%d", &database[n].age);
}

int find (char *string, char *table[]) {
    int index = 0;
    while(table[index] != NULL){
        if(strcmp(string, table[index]) == 0)
            return index;
        index++;
    }
    return (-1);
}

int findOpr (char *name) {
    char *operator[] = {"==", "!=", ">", "<", NULL};
    int code = find(name, operator);
    if(code == -1)
        exit(-1);
    return code;
}

int findField (char *name) {
    char *field[] = {"lastname", "firstname", "ID", "salary", "age", NULL};
    int index = find(name, field);
    if(index == -1)
        exit(-1);
    return index;
}

int compareStr (char opd1[], int opr, char opd2[]) {
    switch(opr){
        case 0:
            return (strcmp(opd1, opd2) == 0);
        case 1:
            return (strcmp(opd1, opd2) != 0);
        default:
            printf("invalid comp %d\n", opr);
            exit(-1);
    }
}

int compareNum (int opd1, int opr, int opd2) {
    switch(opr){
        case 0:
            return (opd1 == opd2);
        case 2:
            return (opd1 > opd2);
        case 3:
            return (opd1 < opd2);
        default:
            printf("invalid comp %d\n", opr);
            exit(-1);
    }
}

void printField (Database *database, Command *command, int data, int n) {
    for(int i = 0; i < command[n].fieldnum; i++){
        switch(command[n].field[i]){
            case 0:
                printf("%s ", database[data].lastname);
                break;
            case 1:
                printf("%s ", database[data].firstname);
                break;
            case 2:
                printf("%s ", database[data].ID);
                break;
            case 3:
                printf("%d ", database[data].salary);
                break;
            case 4:
                printf("%d ", database[data].age);
                break;
        }
    }
    printf("\n");
}

void runCode (Database *database, Command *command, int n, int num) {
    for(int i = 0; i < num; i++){
        int real = 0;
        switch(command[n].opd1){
            case 0:
                real = compareStr(database[i].lastname, command[n].opr, command[n].opd2Str);
                break;
            case 1:
                real = compareStr(database[i].firstname, command[n].opr, command[n].opd2Str);
                break;
            case 2:
                real = compareStr(database[i].ID, command[n].opr, command[n].opd2Str);
                break;
            case 3:
                real = compareNum(database[i].salary, command[n].opr, command[n].opd2Num);
                break;
            case 4:
                real = compareNum(database[i].age, command[n].opr, command[n].opd2Num);
                break;
        }
        if(real == 1)
            printField(database, command, i, n);
    }
}

void processCode (Database *database, Command *command, int n, int num) {
    char selectStr[STRINGLENGTH];
    scanf("%s", selectStr);
    assert(strcmp(selectStr, "select") == 0);
    char fieldStr[STRINGLENGTH];
    int fieldnum = 0;
    scanf("%s", fieldStr);
    while(strcmp(fieldStr, "where") != 0){
        command[n].field[fieldnum] = findField(fieldStr);
        fieldnum++;
        scanf("%s", fieldStr);
    }
    command[n].fieldnum = fieldnum;
    char opd1Str[STRINGLENGTH], oprStr[STRINGLENGTH];
    scanf("%s", opd1Str);
    command[n].opd1 = findField(opd1Str);
    scanf("%s", oprStr);
    command[n].opr = findOpr(oprStr);
    char opd2Str[STRINGLENGTH];
    int opd2Num;
    switch(command[n].opd1){
        case 0: case 1: case 2:
            scanf("%s", opd2Str);
            strcpy(command[n].opd2Str, opd2Str);
            break;
        case 3: case 4:
            scanf("%d", &opd2Num);
            command[n].opd2Num = opd2Num;
            break;
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    Database database[n];
    for(int i = 0; i < n; i++)
        readData(database, i);
    int m;
    scanf("%d", &m);
    Command command[m];
    for(int i = 0; i < m; i++)
        processCode(database, command, i, n);
    for(int i = 0; i < m; i++)
        runCode(database, command, i, n);
    return 0;
}
