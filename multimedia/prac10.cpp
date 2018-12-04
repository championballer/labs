#include <bits/stdc++.h>
#define UNASSIGNED 0
#define N 9
using namespace std;
bool Find_empty(int grid[N][N], int &row, int &col)
{
 for (row = 0; row < N; row++)
 for (col = 0; col < N; col++)
 if (grid[row][col] == UNASSIGNED)
 return true;
 return false;
}
bool UsedInRow(int grid[N][N], int row, int num)
{
 for (int col = 0; col < N; col++)
 if (grid[row][col] == num)
 return true;
 return false;
}
bool UsedInCol(int grid[N][N], int col, int num)
{
 for (int row = 0; row < N; row++)
 if (grid[row][col] == num)
 return true;
 return false;
}
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
 for (int row = 0; row < 3; row++)
 for (int col = 0; col < 3; col++)
 if (grid[row + boxStartRow][col + boxStartCol] == num)
 return true;
 return false;
}
bool isSafe(int grid[N][N], int row, int col, int num)
{
 return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !
UsedInBox(grid, row - row % 3, col - col % 3, num);
}
bool SolveSudoku(int grid[N][N])
{
 int row, col;
 if (!Find_empty(grid, row, col))
 return true;
 for (int num = 1; num <= 9; num++)
 {
 if (isSafe(grid, row, col, num))
 {
 grid[row][col] = num;
 if (SolveSudoku(grid))
 return true;
 grid[row][col] = UNASSIGNED;
 }
 }
 return false;
}
void printGrid(int grid[N][N])
{
 for (int row = 0; row < N; row++)
 {
 for (int col = 0; col < N; col++)
 cout << grid[row][col] << " ";
 cout << endl;
 }
 cout << endl;
}
int main()
{
 int grid[N][N], temp[N][N];
 cout << "Enter the grid (0 for empty cells): " << endl;
 for (int i = 0; i < N; i++)
 for (int j = 0; j < N; j++)
 cin >> grid[i][j];
 for (int i = 0; i < N; i++)
 for (int j = 0; j < N; j++)
 temp[i][j] = grid[i][j];
 if (SolveSudoku(grid) == true)
 {
 char ch;
 int r = 0, c = 0, v = 0;
 if (!Find_empty(temp, r, c))
 cout << "Grid Filled\n";
 else
 {
 cout << endl
 << endl;
 cout << "***************************" << endl;
 cout << " MAIN MENU " << endl;
 cout << "***************************" << endl;
 cout << "1) Solve Sudoku" << endl;
 cout << "2) See Solution" << endl;
 cout << "***************************" << endl;
 cout << "Enter your choice (1/2): ";
 cin >> ch;
 if (ch == '1')
 {
 cout << "\nCurrent state of sudoku is: " << endl;
 printGrid(temp);
 ch = 'y';
 while (Find_empty(temp, r, c) && (ch == 'y' || ch == 'Y'))
 {
 r = 0;
 c = 0;
 v = 0;
 cout << "Enter 'Row Col value' for Input (e.g. 2 3 5):";
 cin >> r >> c >> v;
 if (temp[r][c] == 0)
 {
 if (grid[r][c] == v)
 {
 cout << "\nCorrect\n";
 temp[r][c] = v;
 }
 else
 {
 cout << "\nWrong value, Try again\n";
 }
 }
 else
 cout << "\nBlock not empty\n";
 cout << "\nCurrent state of sudoku is: " << endl;
 printGrid(temp);
 cout << "\nDo you want to continue (y/n): ";
 cin >> ch;
 }
 }
 cout << "\n\n\nCorrect solution for sudoku is: " << endl;
 printGrid(grid);
 }
 }
 else
 printf("No solution exists");
 return 0;
}