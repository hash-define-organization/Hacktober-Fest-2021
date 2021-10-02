class Solution
{
    //Function to find a solved Sudoku. 
    public static boolean SolveSudoku(int[][] board)  
    { 
        int row = -1; 
        int col = -1; 
        boolean isEmpty = true; 
        for (int i = 0; i < 9; i++) 
        { 
            for (int j = 0; j < 9; j++)  
            { 
                if (board[i][j] == 0)  
                { 
                    row = i; 
                    col = j; 
                      
                    //we still have some remaining missing values in Sudoku.
                    isEmpty = false;  
                    break; 
                } 
            } 
            if (!isEmpty) 
            { 
                break; 
            } 
        } 
      
        // no empty space left 
        if (isEmpty)  
        { 
            return true; 
        } 
      
        //else for each-row backtrack 
        for (int num = 1; num <= 9; num++) 
        { 
            if (isSafe(board, row, col, num)) 
            { 
                board[row][col] = num; 
                if (SolveSudoku(board))  
                { 
                    return true; 
                }  
                else
                { 
                    //replacing it.
                    board[row][col] = 0; 
                } 
            } 
        } 
        return false; 
    }
    
    
    public static boolean isSafe(int[][] board,int row, int col, int num)  
    { 
        //row has the unique numbers(row-clash).
        for (int d = 0; d < board.length; d++)  
        { 
            //if the number we are trying to place is already present 
            //in that row, we return false. 
            if (board[row][d] == num)  
            { 
                return false; 
            } 
        } 
          
        //column has the unique numbers (column-clash).
        for (int r = 0; r < board.length; r++) 
        { 
            //if the number we are trying to place is already present 
            //in that column, we return false.
            if (board[r][col] == num) 
            { 
                return false; 
            } 
        } 
      
        //corresponding square has unique number (box-clash).
        int sqrt = (int) Math.sqrt(board.length); 
        int boxRowStart = row - row % sqrt; 
        int boxColStart = col - col % sqrt; 
      
        for (int r = boxRowStart; 
                 r < boxRowStart + sqrt; r++)  
        { 
            for (int d = boxColStart;  
                     d < boxColStart + sqrt; d++)  
            { 
                if (board[r][d] == num)  
                { 
                    return false; 
                } 
            } 
        } 
      
        // if there is no clash, it's safe.
        return true; 
    } 
    
    //Function to print grids of the Sudoku.
    static void printGrid(int grid[][])
    {
        for (int r = 0; r < 9; r++) 
        { 
            for (int d = 0; d < 9; d++) 
            { 
                System.out.print(grid[r][d]); 
                System.out.print(" "); 
            } 
           
        } 
    }
    
}
