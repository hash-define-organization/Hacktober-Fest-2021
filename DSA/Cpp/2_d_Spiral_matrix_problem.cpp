/*
The task is to take an 2-d matrix and print it in spiral order
eg:-
Input:- 3 6
        1 2 3 4 5 6
        7 8 9 10 11 12
        13 14 15 16 17 18

Output:- 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11     
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int row, column;
    cin>>row>> column;
    int arr[row][column];
    
    // Taking in 2d array
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cin>>arr[i][j];
        }
    }

    int start_row=0, end_row=row-1, start_col=0, end_col=column-1;
    while(start_row<=end_row && start_col<=end_col){
        if (start_row<=end_row){
            for(int i=start_col; i<=end_col; i++){
                cout<<arr[start_row][i]<<" ";
            }
        }
        start_row++;
        if (start_col<=end_col){
            for(int i=start_row; i<=end_row; i++){
                cout<<arr[i][end_col]<<" ";
            }
        }
        end_col--;
        if (start_row<=end_row){
            for(int i=end_col; i>=start_col; i--){
                cout<<arr[end_row][i]<<" ";
            }
        }
        end_row--;
        if (start_col<=end_col){
            for(int i=end_row; i>=start_row; i--){
                cout<<arr[i][start_col]<<" ";
            }
        }
        start_col++;
    }
    return 0;
}
