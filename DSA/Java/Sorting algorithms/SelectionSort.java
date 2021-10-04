import java.util.*;

public class SelectionSort {
    public static void main(String[] args) {
        //An example array
        int[] arr = {-8, 2, -4, 3, 5, 1, 6};
        selection(arr);
        System.out.println(Arrays.toString(arr));
    }
    //Function to perform selection sort.
    //We will find and select maximum element in the array and then swap it on its correct position.
    static void selection(int[] arr){
        for(int i=0; i<arr.length; i++){
            int last = arr.length - i - 1;
            int maxIndex = getMaxIndex(arr, 0, last);
            swap(arr, maxIndex, last);
        }
    }
    //Function to get the maximum element in given array.
    private static int getMaxIndex(int[] arr, int start, int end){
        int max =  start;
        for (int i = start; i <= end; i++) {
            if(arr[max] < arr[i]) {
                max = i;
            }
        }
        return max;
    }
    //Function to swap the elements in given arrray
    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
