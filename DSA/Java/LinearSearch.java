class LinearSearch{
    // method to find element from the array using linear search
    public static int linearSearching(int arr[], int target)
    {
        int n = arr.length;
        for (int i = 0; i < n; i++)
        {
           // check if element in the array is equal to the element which the user wants to search for 
            if (arr[i] == target)
                return i;
        }
        return -1;
    }
    //driver function
    public static void main(String args[])
    {
        int arr[] = {1,4,9,6,19,12,14,13,97};
        int target = 13;
 
        int ans = linearSearching(arr, target);
        if (ans == -1)
            System.out.print("\nElement is not present in array\n");
        else
            System.out.print("\nElement is present at index " + ans + "\n");
    }
}
