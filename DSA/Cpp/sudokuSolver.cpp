#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool issafetoplace(vector<vector<char>>& board , int row , int col , char ch)   //checking if we can place our number 
    {
        int row_idx = 3 * (row/3);
        int col_idx = 3 * (col/3);
        
        for(int idx=0; idx<9 ; idx++)
        {
            if(board[row][idx]== ch)
            {
                return false;
            }
            
            if(board[idx][col]== ch)
            {
                return false;
            }
            
            if(board[row_idx+(idx/3)][col_idx+(idx%3)]== ch)
            {
                return false;
            }
        }
         
        return true;
        
    }
    
    bool fillanswer(vector<vector<char>>& board )
    {
        for(int idx=0 ;idx<9 ;  idx++)
        {
           for(int ind=0 ; ind<9 ; ind++)
           {
               if(board[idx][ind]== '.')      //if nothing is placed then place a number here
               {
                   for(char ch= '1' ; ch<= '9' ; ch++)
                   {
                       if(issafetoplace(board , idx , ind , ch))
                       {
                           board[idx][ind]= ch;
                           
                          if(fillanswer(board))        //if we can place return true
                          {
                            return true;
                          }
                           
                           board[idx][ind]='.';      //backtrack if we are not able to place any number
                           
                       }
                   }
                   return false;
               }
           }
        }
        return true;                              //if our whole matrix if filled then return matrix
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        fillanswer(board);
    }
};