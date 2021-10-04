import java.util.*;

public class bubbleSort {
    public static void main(String[] args) {
        int[] arr = {0, -3, -4, 10, 9, 1, 2, -5, 6};
        bubble(arr);
        System.out.println(Arrays.toString(arr));
    }
//In bubble sort, we compare adjacent values and swapping it if the element on the right side is smaller.
    static void bubble(int[] arr){
        boolean swapped;

        //run the steps n-1 times
        for (int i = 0; i < arr.length; i++) {
            swapped = false;
            //for each step, max item will come at the last respective index
            for (int j = 1; j < arr.length - i ; j++) {
                //swap if the item is smaller than the previous element
                if(arr[j] < arr[j-1]){
                    //swap
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    swapped = true;
                }
            }

            //if you did not swap for a particular value of i, it means the array is sorted,hence, stop the program
            if(!swapped){
                break;
            }
        }
    }
}
