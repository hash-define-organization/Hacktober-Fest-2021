#include<bits/stdc++.h>
using namespace std;

    /*Function to get gcd of a and b*/
    int gcd(int x, int y)       // gcd(a,b) number of blocks are formed
    {
    if (y == 0)
    return x;
    else
    return gcd(y, x % y);   //gcd(or HCF) of 6 and 2 is 2
    }



    /*Function to left rotate array by n ie. number of rotations*/
    void array_left_rotate(int arr[], int d, int n)
    {
    int i, j, k, temp;
    for (i = 0; i < gcd(d, n); i++) // gcd(d,n) times the loop will iterate
    {
    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while (true) {
    k = j + d;
    if (k >= n) // The element has to be shifted to its rotated position
    k = k - n;
    if (k == i) // If condition to check if element is already in its rotated position
    break;
    arr[j] = arr[k];
    j = k;
    }
    arr[j] = temp;
    }}

    
    /*Main Function*/
    int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]); // Finding the size of the array
    cout<<"\nArray elements before rotating : \n";
    
        for(int i = 0; i < n; i++)
        {
        cout<<arr[i]<<"\t"; // Printing the array elements
        }
    
    int no_of_rotations = 2; // Input for no. of rotations to take place
    
    array_left_rotate(arr, no_of_rotations, n);
    
    cout<<"\n\nArray elements after rotating : \n";
    
        for(int i = 0; i < n; i++)
            {
            cout<<arr[i]<<"\t"; // After Rotation print the array
            }
    cout<<"\n";
    return 0;
}