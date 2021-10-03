import java.util.*;

public class InsertionSort {
    public static void main(String[] args) {
        //Example array
        int[] arr = {5,10, -3, 3, 1, 6, -4};
        insertion(arr);
        System.out.println(Arrays.toString(arr));
    }
    /*In insertion sort, we compare the current element with its predecessor,
    and if it is true, we check it with all previous element and then swapping it with greater number.*/
    static void insertion(int[] arr){
        for (int i = 0; i < arr.length - 1; i++) {//i<=n-2
            for(int j = i+1; j>0; j--){
                if(arr[j] < arr[j-1]){
                    swap(arr, j, j-1);
                }else{
                    break;
                }
            }
        }
    }
    //Swapping fucntion
    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
