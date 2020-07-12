#include <cmath>
#include <iostream>
using namespace std;
bool canPlace(int mat[][9], int i, int j, int n, int num)
{

    for (int x = 0; x < n; x++) {
        if (mat[x][j] == num || mat[i][x] == num)
            return false;
    }
    //for subgrid
    int rn = sqrt(n);
    int rowStart = (i / rn) * rn;
    int colStart = (j / rn) * rn;
    for (int x = rowStart; x < rowStart + rn; x++) {
        for (int y = colStart; y < colStart + rn; y++) {
            if (mat[x][y] == num)
                return false;
        }
    }
    return true;
}
bool solveSudoku(int mat[][9], int i, int j, int n)
{
    if (i == n) {
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                cout << mat[x][y] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if (j == n) {
        return solveSudoku(mat, i + 1, 0, n);
    }
    //skip prefilled cells
    if (mat[i][j] != 0) {
        return solveSudoku(mat, i, j + 1, n);
    }
    //fill current cells with possible options
    for (int num = 1; num <= n; num++) {
        if (canPlace(mat, i, j, n, num)) {
            //assume
            mat[i][j] = num;
            bool couldBeSolved = solveSudoku(mat, i, j + 1, n);
            if (couldBeSolved)
                return true;
        }
    }
    //backtrack
    mat[i][j] = 0;
    return false;
}
int main()
{
    int grid[9][9] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
        { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
        { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
        { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
        { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
        { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
        { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
        { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
        { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
    solveSudoku(grid, 0, 0, 9);
}