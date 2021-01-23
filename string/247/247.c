#include <stdio.h>
#include <string.h>
#include <assert.h>

void up(int *DNA, int m, int n, int column, int step);
void down(int *DNA, int m, int n, int column, int step);
void left(int *DNA, int m, int n, int row, int step);
void right(int *DNA, int m, int n, int row, int step);
void rotate(int *DNA, int m, int n, int row1, int column1, int row2, int column2, int step);

int main(void){
    int row, col;
    scanf("%d%d", &row, &col);
    assert(row > 0 && col > 0 && col % 16 == 0 && row * col <= 1600000);
    char dna[row][col];
    for(int i = 0; i < row; i++)
        scanf("%s", dna[i]);
    char command[10];
    scanf("%s", command);
    if(strcmp(command, "up") == 0){
        int column, step;
        scanf("%d%d", &column, &step);
        up(dna, row, col, column, step);
    }else if()
    return 0;
}
