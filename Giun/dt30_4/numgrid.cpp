#include <bits/stdc++.h> 
using namespace std; 
  
#define UNASSIGNED 0  
#define N 9  
  
bool ful(int grid[N][N], int &row, int &col);  
bool checks(int grid[N][N], int row, int col, int num);  
  
bool solve(int grid[N][N])  
{  
    int row, col;  
    if (!ful(grid, row, col)) return true;   
   
    for (int num = 1; num <= 9; num++)  
    {    
        if (checks(grid, row, col, num))  
        {  
            grid[row][col] = num;  
            if (solve(grid))  
                return true;    
            grid[row][col] = UNASSIGNED;  
        }  
    }  
    return false; 
}  
  
bool ful(int grid[N][N], int &row, int &col)  
{  
    for (row = 0; row < N; row++)  
        for (col = 0; col < N; col++)  
            if (grid[row][col] == UNASSIGNED)  
                return true;  
    return false;  
}  
  
bool checkr(int grid[N][N], int row, int num)  
{  
    for (int col = 0; col < N; col++)  
        if (grid[row][col] == num)  
            return true;  
    return false;  
}  
  
bool checkc(int grid[N][N], int col, int num)  
{  
    for (int row = 0; row < N; row++)  
        if (grid[row][col] == num)  
            return true;  
    return false;  
}  
  
bool checkb(int grid[N][N], int boxStartRow, int boxStartCol, int num)  
{  
    for (int row = 0; row < 3; row++)  
        for (int col = 0; col < 3; col++)  
            if (grid[row + boxStartRow][col + boxStartCol] == num)  
                return true;  
    return false;  
}  
  
bool checks(int grid[N][N], int row, int col, int num)  
{  
    return !checkr(grid, row, num) &&  
           !checkc(grid, col, num) &&  
           !checkb(grid, row - row % 3 , col - col % 3, num) && grid[row][col] == UNASSIGNED;  
}  
  
void printGrid(int grid[N][N])  
{  
    for (int row = 0; row < N; row++)  
    {  
        for (int col = 0; col < N; col++)  
            cout << grid[row][col] << " ";  
        cout << endl; 
    }  
}  

int main()  
{  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.inp", "r", stdin);
    freopen("o.out", "w", stdout);  
    int grid[N][N] = {{0}};
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> grid[i][j];
        }
    }
    solve(grid);  
    printGrid(grid);
    return 0;  
}  