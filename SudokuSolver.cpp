#include <iostream>
using namespace std;
#define n 9

// Function to print the sudoku board
void printboard(int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if it's safe to place a number
bool issafe(int board[n][n], int i, int j, int num)
{
    for (int r = 0; r < n; r++)
    {
        if (board[i][r] == num || board[r][j] == num)
            return false;
    }

    int startrow = i - i % 3;
    int startcol = j - j % 3;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (board[x + startrow][y + startcol] == num)
                return false;

    return true;
}

// Solve using recursion and backtracking
bool solvesudoku(int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++) // FIXED range to 1-9
                {
                    if (issafe(board, i, j, num))
                    {
                        board[i][j] = num;

                        if (solvesudoku(board))
                            return true;

                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int board[n][n] = {
        {6, 8, 3, 0, 0, 2, 1, 0, 0},
        {3, 5, 0, 0, 9, 8, 0, 7, 6},
        {6, 5, 0, 9, 0, 8, 0, 6, 4},
        {4, 5, 6, 7, 9, 0, 0, 0, 8},
        {1, 2, 3, 4, 9, 8, 0, 0, 0},
        {0, 6, 0, 0, 0, 0, 3, 8, 0},
        {0, 0, 0, 0, 6, 0, 0, 5, 4},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
        {5, 8, 9, 0, 6, 4, 2, 1, 7} 
    };

    if (solvesudoku(board))
    {
        cout << "Solved Sudoku:\n";
        printboard(board);
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}
