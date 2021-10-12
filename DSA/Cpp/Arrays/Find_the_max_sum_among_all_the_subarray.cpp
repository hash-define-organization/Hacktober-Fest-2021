/*
Task:-Of all the possible sub-array's sum find which one is Maximum.
This is the cumulative sum array approch for finding the max sum among all the subarrays sum.
As there is a nested for loop Time complexity is O(n^2).
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int array_size;
    cin>>array_size;
    int arr[array_size];
    for(int i=0; i<array_size; i++){
        cin>>arr[i];
    }

    int CumSumArr[array_size]; // Cumulative Sum Array
    CumSumArr[0]=arr[0];
    for (int i=1; i<array_size; i++){ // Creating Cumulative Sum array 
        CumSumArr[i]=CumSumArr[i-1]+arr[i];
    }

    int max_sum = INT_MIN; // This will containe the possible MAX-sum among all the sum of possible subarrays 
    for (int i=0; i<array_size; i++){ // We are basically using 2-pointer approch here
        max_sum=max(CumSumArr[i], max_sum);

        for (int j=0; j<i; j++){
            max_sum=max(CumSumArr[i]-CumSumArr[j], max_sum);
        }
    }
    cout<<max_sum;
    return 0;
}