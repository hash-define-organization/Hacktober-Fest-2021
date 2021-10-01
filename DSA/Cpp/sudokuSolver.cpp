#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafeToPlace(vector<vector<char>>& board, int row, int col, char ch)
    {   
        int rowStart = 3 * (row/3) , colStart = 3 * (col/3);  

        for (int idx=0; idx<9; idx++)
        {
            if (board[row][idx] == ch) return false;

            if (board[idx][col] == ch) return false;

            if (board[rowStart + (idx/3)][colStart + (idx%3)] == ch) return false;
        }

        return true;
    }

    bool fillBoard(vector<vector<char>>& board) 
    {

        for (int rowIdx=0; rowIdx<9; rowIdx++)
        {
            for (int colIdx=0; colIdx<9; colIdx++)
            {
                if (board[rowIdx][colIdx] == '.')
                {   
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isSafeToPlace(board, rowIdx, colIdx, ch))
                        {
                           board[rowIdx][colIdx] = ch;

                           if (fillBoard(board)) return true;

                           board[rowIdx][colIdx] = '.'; 
                        }
                    }
                    return false; 
                }
            }

        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        fillBoard(board);
    }
};