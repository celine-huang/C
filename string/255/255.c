#include <stdio.h>
#include <string.h>
#define LINE 100
#define WORD 27
#define CHAR 27

enum StatementType{STOP, IF, GOTO, PRINT, ASSIGN};

int find(char *string, char *table[]){
    int index = 0;
    while(table[index] != NULL){
        if(strcmp(string, table[index]) == 0)
            return index;
        index++;
    }
    return(-1);
}

int newline(int code[], int lineNum[], int gotoLine[], int line){
	int regoto = line;
	while(code[regoto] == GOTO){
		line = regoto;
		regoto = 0;
		while(lineNum[regoto] != gotoLine[line])
			regoto++;	
	}
	return regoto; 
}

int main(void){
    int code[LINE] = {0}, lineNum[LINE] = {0}, gotoLine[LINE] = {0};
    char first[CHAR] = {0};
    char *firstTable[] = {"STOP", "IF", "GOTO", "PRINT", NULL};
    char ifLine[LINE][WORD][CHAR] = {0};
    char printLine[LINE][CHAR] = {0};
    char assignLine[LINE][WORD][CHAR] = {0};
    int line = 0, word = 0;
    while(scanf("%d", &lineNum[line]) != EOF){
        scanf("%s", first);
        int firstType = find(first, firstTable);
        switch(firstType){
            case GOTO:
                code[line] = GOTO;
                scanf("%d", &gotoLine[line]);
                break;
            case STOP:
                code[line] = STOP;
                break;
            case IF:
                code[line] = IF;
                word = 0;
                scanf("%s", ifLine[line][word]);
                while(strcmp(ifLine[line][word], "GOTO") != 0){
                    word++;
                    scanf("%s", ifLine[line][word]);
                }
                scanf("%d", &gotoLine[line]);
                break;
            case PRINT:
                code[line] = PRINT;
                scanf("%s", printLine[line]);
                break;
            default:
                code[line] = ASSIGN;
                word = 0;
                strcpy(assignLine[line][word], first);
                word++;
                while(1){
                    scanf("%s", assignLine[line][word]);
                    word++;
                    char c;
                    scanf("%c", &c);
                    if(c == '\n')
                        break;
                }
                break;
        }
        line++;
    }
    int renumber[LINE] = {0};
    line = 0;
    while(lineNum[line] != 0){
        renumber[line] = (line + 1) * 100;
        line++;
    }
    line = 0;
    while(lineNum[line] != 0){
        int regoto = 0;
        printf("%d ", renumber[line]);
        switch(code[line]){
            case GOTO:
				regoto = newline(code, lineNum, gotoLine, line);
                printf("GOTO %d", renumber[regoto]);
                break;
            case STOP:
                printf("STOP");
                break;
            case IF:
                regoto = 0;
                while(lineNum[regoto] != gotoLine[line])
                    regoto++;
                regoto = newline(code, lineNum, gotoLine, regoto);
                printf("IF ");
                word = 0;
                while(strcmp(ifLine[line][word], "GOTO") != 0){
                    printf("%s ", ifLine[line][word]);
                    word++;
                }
                printf("GOTO %d", renumber[regoto]);
                break;
            case PRINT:
                printf("PRINT %s", printLine[line]);
                break;
            case ASSIGN:
                word = 0;
                printf("%s", assignLine[line][word]);
                word++;
                while(assignLine[line][word][0] != '\0'){
                    printf(" %s", assignLine[line][word]);
                    word++;
                }
                break;
        }
        printf("\n");
        line++;
    }
    return 0;
}
