#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution 
{
    
    vector <vector<string> > answer;
    
public:
    
    bool isSafe(vector <vector<int> > &arr, int row, int col)                                               //function to check if it's safe to place queen in the given block
    {
        for(int curRow = 0; curRow < row; curRow++)                                                         //checking if there is a queen in row
        {
            if(arr[curRow][col] == 1)
            {
                return false;
            }
        }
        
        for(int curRow = row -1, curCol = col -1; curRow >= 0 && curCol >= 0; curRow--, curCol--)               //checking if there is a queen in left diagonal
        {
            if(arr[curRow][curCol] == 1)
            {
                return false;
            }
        }
        
        for(int curRow = row -1, curCol = col +1; curRow >= 0 && curCol < arr[0].size(); curRow--, curCol++)        //checking if there is a queen in right diagonal
        {
            if(arr[curRow][curCol] == 1)
            {
                return false;
            }
        }
        
        return true;                                                                            //if no conditions are true, returning true
    }
    
    void nQueens(vector <vector<int> > &arr, int row)                                           //driver function, row increases w each call
    {   
        if(row == arr.size())                                                                   //basecase, if board is finished
        {
            vector<string> board;                                                               //forming appropriate board
            
            for(int curRow = 0; curRow < arr.size(); curRow++)
            {
                string line = "";
                
                for(int curCol = 0; curCol < arr[0].size(); curCol++)
                {
                    if(arr[curRow][curCol] == 0)
                    {
                        line += ".";
                    }
                    else
                    {
                        line += "Q";
                    }
                }
                
                board.push_back(line);
            }
            
            answer.push_back(board);
            
            return;
        }
        
        for(int col = 0; col < arr[0].size(); col++)                            //moving across col
        {
            if(isSafe(arr, row, col) == true)                                   //checking if it's safe to place queen
            {
                arr[row][col] = 1;                                              //placing queen
                
                nQueens(arr, row + 1);                                          //recursive call for next row (there can only be 1 queen in a col)
                
                arr[row][col] = 0;                                              //BACKTRACKING; when retruning, removing queen
            }
            
        }
        
        return;
        
    }
    
    vector< vector<string> > solveNQueens(int n) 
    {
        vector <vector<int> > arr;
        
        for(int idx = 0; idx < n; idx++)                                    //creating empty board
        {
            vector<int> temp;
            
            for(int curr = 0; curr < n; curr++)
            {
                temp.push_back(0);
            }
            
            arr.push_back(temp);
            
        }
        
        nQueens(arr, 0);
        
        return answer;
    }
};