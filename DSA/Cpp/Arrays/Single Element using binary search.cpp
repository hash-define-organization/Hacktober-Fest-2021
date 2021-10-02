#include<bits/stdc++.h>
using namespace std;

// function to find the element appears only once in O(log n) time complexity
int singleEle(int arr[], int low, int high)
{
    if(low > high)
        return -1;
    while(low <= high)
    {
        if(low == high)
            return arr[low];
        int mid = (low + high)/2;
        if(mid % 2 == 0)        // mid is at even index so next element and curr element should be same
        {
            if(arr[mid] == arr[mid+1])
                low = mid+2;    // check in right half
            else
                high = mid;     // check in left half
        }
        else                    // if mid is at odd index so curr element and prev element should be equal
        {
            if(arr[mid] == arr[mid-1])
                low = mid+1;
            else
                high = mid-1;
        }
    }
}

int main()
{
    // taking input
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    // calling the function
    cout<<singleEle(arr, 0, n-1);
    return 0;
}