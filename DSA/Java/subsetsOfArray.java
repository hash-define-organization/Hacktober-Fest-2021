import java.util.*;

public class subsetsOfArray {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);

        int size = scn.nextInt();
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = scn.nextInt();
        }
        int lim = (1 << size);// lim -> limit -> total number of subsets

        // step 1 -> run loop from 0 -> limit
        for (int i = 0; i < lim; i++) {
            int dec = i;// dec -> decimal of 'i'

            // find binary of the decimal and if rem is 0 then don't print, otherwise print
            // element
            // decimal to binary conversion
            String str = "";
            for (int j = 0; j < arr.length; j++) {
                int rem = dec % 2;
                dec = dec / 2;
                if (rem == 0)
                    str = "-	" + str;
                else
                    str = arr[arr.length - 1 - j] + "	" + str;
            }
            System.out.println(str);
        }
        scn.close();
    }

}