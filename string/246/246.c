#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define LINE 200
#define NAMELENGTH 10

enum Operator{ADD, SUB, MUL, DIV, MOD, EQL, NOTEQL, SMALLER, LARGER, SMALLEREQL, LARGEREQL};
enum StatementType{STOP, IF, GOTO, PRINT, ASSIGN, COMPUTE};

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

int findVariable(char *name, char varTable[][NAMELENGTH]){
    int index = 0;
    while(strcmp(name, varTable[index]) != 0)
        index++;
    return(index);
}

int findNum(int num, int numTable[]){
    int index = 0;
    while(num != numTable[index])
        index++;
    return(index);
}

int StringToNum(char *string){
    int stringLen = strlen(string);
    int num = 0;
    for(int i = 0; i < stringLen; i++)
        num += (string[i] - 48) * pow(10, (stringLen - i - 1));
    return num;
}

void processCode(char varName[][NAMELENGTH], int varValue[], int assignValue[], int lineNum[], int code[], int opd1[], int compopr[], int opd2[], int num1[], int num2[], int gotoLine[]){
    char first[NAMELENGTH];
    char str[NAMELENGTH];
    char judge;
    char *firstTable[] = {"STOP", "IF", "GOTO", "PRINT", NULL};
    int line = 1;
    while(1){
        scanf("%d", &lineNum[line]);
        assert(lineNum[line] > 0 && lineNum[line] <= 65535);
        scanf("%s", first);
        int firstType = find(first, firstTable);
        switch(firstType){
            case GOTO:
                code[line] = GOTO;
                scanf("%d", &gotoLine[line]);
                break;
            case STOP:
                code[line] = STOP;
                return;
            case IF:
                code[line] = IF;
                scanf("%s", str);
                opd1[line] = findVariable(str, varName);
                scanf("%s", str);
                compopr[line] = findOprCode(str);
                scanf("%s", str);
				if(isalpha(str[0]))
                    opd2[line] = findVariable(str, varName);
                else
                    num2[line] = StringToNum(str);
                scanf("%s", str);
                assert(strcmp(str, "GOTO") == 0);
                scanf("%d", &gotoLine[line]);
                break;
            case PRINT:
                code[line] = PRINT;
                scanf("%s", varName[line]);
                varValue[line] = findVariable(varName[line], varName);
                break;
            default:
                strcpy(varName[line], first);
                scanf("%s", str);
                assert(strcmp(str, "=") == 0);
                scanf("%s", str);
                scanf("%c", &judge);
                if(judge == '\n'){
                    code[line] = ASSIGN;
                    if(isalpha(str[0]))
                        assignValue[line] = findVariable(str, varName);
                    else{
                        varValue[line] = StringToNum(str);
                        opd1[line] = StringToNum(str);
                    }
                }else{
                    code[line] = COMPUTE;
                    varValue[line] = findVariable(varName[line], varName);
                    if(isalpha(str[0]))
                        opd1[line] = findVariable(str, varName);
                    else
                        num1[line] = StringToNum(str);
                    scanf("%s", str);
                    compopr[line] = findOprCode(str);
                    scanf("%s", str);
                    if(isalpha(str[0]))
                        opd2[line] = findVariable(str, varName);
                    else
                        num2[line] = StringToNum(str);
                }
                break;
        }
        line++;
    }
}

/*
void printCode(char varName[][NAMELENGTH], int varValue[], int assignValue[], int lineNum[], int code[], int opd1[], int compopr[], int opd2[], int num1[], int num2[], int gotoLine[]){
    int line = 1;
    while(1){
        printf("%d ", lineNum[line]);
        switch(code[line]){
            case STOP:
                printf("STOP\n");
                return;
                break;
            case IF:
                printf("IF %s %d ", varName[opd1[line]], compopr[line]);
                if(opd2[line] == 0)
                    printf("%d ", num2[line]);
                else
                    printf("%s ", varName[opd2[line]]);
                printf("GOTO %d", gotoLine[line]);
                break;
            case GOTO:
                printf("GOTO %d", gotoLine[line]);
                break;
            case PRINT:
                printf("PRINT %s", varName[varValue[line]]);
                break;
            case ASSIGN:
                if(assignValue[line] == 0)
                    printf("%s = %d", varName[line], opd1[line]);
                else
                    printf("%s = %s", varName[line], varName[assignValue[line]]);
                break;
            case COMPUTE:
                printf("%s = ", varName[line]);
                if(opd1[line] == 0)
                    printf("%d %d ", num1[line], compopr[line]);
                else
                    printf("%s %d ", varName[opd1[line]], compopr[line]);
                if(opd2[line] == 0)
                    printf("%d", num2[line]);
                else
                    printf("%s", varName[opd2[line]]);
                break;
        }
        printf("\n");
        line++;
    }
}
*/

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

void runCode(char varName[][NAMELENGTH], int varValue[], int assignValue[], int lineNum[], int code[], int opd1[], int compopr[], int opd2[], int num1[], int num2[], int gotoLine[]){
    int line = 1;
    while(code[line] != STOP){
        switch(code[line]){
            case IF:
				if(opd2[line] == 0){
					if(compare(varValue[opd1[line]], compopr[line], num2[line]))
						line = findNum(gotoLine[line], lineNum);
					else
						line++;
                }else{
					if(compare(varValue[opd1[line]], compopr[line], varValue[opd2[line]]))
                    	line = findNum(gotoLine[line], lineNum);
                	else 
                    	line++;
				}
                break;
            case GOTO:
                line = findNum(gotoLine[line], lineNum);
                break;
            case PRINT:
                printf("%d\n", varValue[varValue[line]]);
                line++;
                break;
            case ASSIGN:
                if(assignValue[line] == 0)
                    varValue[line] = opd1[line];
                else
                    varValue[line] = varValue[assignValue[line]];
                line++;
                break;
            case COMPUTE:
                if(opd1[line] == 0 && opd2[line] == 0)
                    varValue[varValue[line]] = arithmetic(num1[line], compopr[line], num2[line]);
                else if(opd1[line] != 0 && opd2[line] == 0)
                    varValue[varValue[line]] = arithmetic(varValue[opd1[line]], compopr[line], num2[line]);
                else if(opd1[line] == 0 && opd2[line] != 0)
                    varValue[varValue[line]] = arithmetic(num1[line], compopr[line], varValue[opd2[line]]);
                else
                    varValue[varValue[line]] = arithmetic(varValue[opd1[line]], compopr[line], varValue[opd2[line]]);
                line++;
                break;
            default:
                printf("invalid code %d\n", code[line]);
                exit(-1);
        }
    }
}

int main(void){
    char varName[LINE][NAMELENGTH] = {0};
    int varValue[LINE] = {0}, assignValue[LINE] = {0};
    int lineNum[LINE] = {0};
    int code[LINE];
    int opd1[LINE] = {0}, compopr[LINE], opd2[LINE] = {0}, num1[LINE] = {0}, num2[LINE] = {0};
    int gotoLine[LINE];
    processCode(varName, varValue, assignValue, lineNum, code, opd1, compopr, opd2,num1, num2, gotoLine);
	//printCode(varName, varValue, assignValue, lineNum, code, opd1, compopr, opd2, num1, num2, gotoLine);
    runCode(varName, varValue, assignValue, lineNum, code, opd1, compopr, opd2, num1, num2, gotoLine);
    return 0;
}
