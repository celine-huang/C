#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LINE 1000
#define VAR 100
#define NAMELENGTH 10

enum Operator
    {ADD, SUB, MUL, DIV, MOD, EQL, NOTEQL, SMALLER, LARGER, SMALLEREQL, LARGEREQL};

enum StatementType
    {STOP, IF, GOTO, PRINT, ASSIGN};

int find(char *string, char *table[]){
   int index = 0;
   while(table[index] != NULL){
       if(strcmp(string, table[index]) == 0)
           return index;
       index++;
   }
   return(-1);
}

int findOprCode(char *name){
    char *operators[] = {"+", "-", "*", "/", "%", "==", "!=", "<", ">", "<=", ">=", NULL};
    int code = find(name, operators);
    if(code == -1)
        exit(-1);
    return(code);
}

int findVariable(char *name, char *varNameTable[]){
    int index = find(name, varNameTable);
    if(index == -1)
        exit(-1);
    return(index);
}

void processIF(int lineNum, char *varNameTable[], int opd1[], int compopr[], int opd2[], int gotoLine[]){
    char gotoStr[NAMELENGTH];
    char opd[NAMELENGTH], opr[NAMELENGTH];
    scanf("%s", opd);
    opd1[lineNum] = findVariable(opd, varNameTable);
    scanf("%s", opr);
    compopr[lineNum] = findOprCode(opr);
    scanf("%s", opd);
    opd2[lineNum] = findVariable(opd, varNameTable);
    scanf("%s", gotoStr);
    assert(strcmp(gotoStr, "GOTO") == 0);
    scanf("%d", &gotoLine[lineNum]);
}

void processASSIGN(int lineNum, char *first, char *varNameTable[], int opd1[], int compopr[], int opd2[], int target[]){
    char assignStr[NAMELENGTH];
    char opd[NAMELENGTH], opr[NAMELENGTH];
    target[lineNum] = findVariable(first, varNameTable);
    scanf("%s", assignStr);
    assert(strcmp(assignStr, "=") == 0);
    scanf("%s", opd);
    opd1[lineNum] = findVariable(opd, varNameTable);
    scanf("%s", opr);
    compopr[lineNum] = findOprCode(opr);
    scanf("%s", opd);
    opd2[lineNum] = findVariable(opd, varNameTable); 
}

void processCode(char *varNameTable[], int code[], int opd1[], int compopr[], int opd2[], int gotoLine[], int target[]){
    char first[NAMELENGTH];
    char opd[NAMELENGTH];
    int lineNum = 1;
    char *firstTable[] = {"STOP", "IF", "GOTO", "PRINT", NULL};
    while(scanf("%s", first) != EOF){
        int firstType = find(first, firstTable);
        switch(firstType){
            case STOP:
                code[lineNum] = STOP;
                break;
            case IF:
                code[lineNum] = IF;
                processIF(lineNum, varNameTable, opd1, compopr, opd2, gotoLine);
                break;
            case GOTO:
                code[lineNum] = GOTO;
                scanf("%d", &gotoLine[lineNum]);
                break;
            case PRINT:
                code[lineNum] = PRINT;
                scanf("%s", opd);
                target[lineNum] = findVariable(opd, varNameTable);
                break;
            default:
                code[lineNum] = ASSIGN;
                processASSIGN(lineNum, first, varNameTable, opd1, compopr, opd2, target);
                break;
        }
        lineNum++;
    }
}

int compare(int opd1, int opr, int opd2){
    switch(opr){
        case EQL:
            return (opd1 == opd2);
            break;
        case NOTEQL:
            return (opd1 != opd2);
            break;
        case SMALLER:
            return (opd1 < opd2);
            break;
        case LARGER:
            return (opd1 > opd2);
            break;
        case SMALLEREQL:
            return (opd1 <= opd2);
            break;
        case LARGEREQL:
            return (opd1 >= opd2);
            break;
        default:
            printf("invalid comp %d\n", opr);
            exit(-1);
    }
}

int arithmetic(int opd1, int opr, int opd2){
    switch(opr){
        case ADD:
            return (opd1 + opd2);
            break;
        case SUB:
            return (opd1 - opd2);
            break;
        case MUL:
            return (opd1 * opd2);
            break;
        case DIV:
            return (opd1 / opd2);
            break;
        case MOD:
            return (opd1 % opd2);
            break;
        default:
            printf("invalid comp %d\n", opr);
            exit(-1);
    }
}

void runCode(char varName[][NAMELENGTH], int varValue[], int code[], int opd1[], int compopr[], int opd2[], int gotoLine[], int target[]){
    int line = 1;
    while(code[line] != STOP){
        switch(code[line]){
            case IF:
                if(compare(varValue[opd1[line]], compopr[line], varValue[opd2[line]]))
                    line = gotoLine[line];
                else
                    line++;
                break;
            case GOTO:
                line = gotoLine[line];
                break;
            case PRINT:
                printf("%d\n", varValue[target[line]]);
                line++;
                break;
            case ASSIGN:
                varValue[target[line]] = arithmetic(varValue[opd1[line]], compopr[line], varValue[opd2[line]]);
                line++;
                break;
            default:
                printf("invalid code %d\n", code[line]);
                exit(-1);
        }
    }
}

void readVariable(char varName[][NAMELENGTH], int varValue[], char *varNameTable[]){
    int count = 0;
    char name[NAMELENGTH];
    scanf("%s", name);
    while(strcmp(name, "END") != 0){
        strcpy(varName[count], name);
        char assignStr[NAMELENGTH];
        scanf("%s", assignStr);
        assert(strcmp(assignStr, "=") == 0);
        scanf("%d", &varValue[count]);
        varNameTable[count] = varName[count];
        count++;
        scanf("%s", name);
    }
    varNameTable[count] = NULL;
    return;
}

int main(void){
    char varName[VAR][NAMELENGTH];
    int varValue[VAR];
    char *varNameTable[VAR];
    readVariable(varName, varValue, varNameTable);
    int code[LINE];
    int opd1[LINE], compopr[LINE], opd2[LINE];
    int gotoLine[LINE];
    int target[LINE];
    processCode(varNameTable, code, opd1, compopr, opd2, gotoLine, target);
    runCode(varName, varValue, code, opd1, compopr, opd2, gotoLine, target);
    return 0;
}
