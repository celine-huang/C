#include <stdio.h>
#define ROW 15
#define COL 15

int moveWays (int matrix[][COL], int row, int col) {
    if(row == 0 || col == 0)
        return 1;
    return (moveWays(matrix, row - 1, col) + moveWays(matrix, row, col - 1));
}

int main (void) {
    int r, c;
    scanf("%d%d", &r, &c);
    int matrix[ROW][COL];
    printf("%d\n", moveWays(matrix, r - 1, c - 1));
    return 0;
}
