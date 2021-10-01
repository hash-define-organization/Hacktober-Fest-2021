import java.util.*;

public class CyclicSort {
    public static void main(String[] args) {
        int[] arr = {5, 3, 4, 2, 6, 1};
        cyclic(arr);
        System.out.println(Arrays.toString(arr));
    }
    //Cyclic sort is applicable on arrays containing 1 to n integers.
    //In this, element get swapped at the correct position in the given array.
    static void cyclic(int[] arr) {
        int i=0;
        while(i < arr.length){
            int correctIndex = arr[i] - 1;

            if(arr[i] != arr[correctIndex]){
                swap(arr, i ,correctIndex);
            }
            else{
                i++;
            }
        }
    }
    //Swap function
    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }



}
