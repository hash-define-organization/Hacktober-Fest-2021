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
        int limit;
        for (int i = 0; i < lim; i++) {
            int dec = i;
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
