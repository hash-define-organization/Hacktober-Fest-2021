/* -------------------------------------------------------------------------- */
/*                             Check Prime Number                             */
/*                              By @AnmolManocha                              */
/* -------------------------------------------------------------------------- */

import java.util.Scanner;

public class primeNum {

    public static Scanner scan = new Scanner(System.in);

    /* --------------------- Function to Check Prime Number --------------------- */

    public static boolean isPrime(int Num) {
        if (Num <= 1)
            return false;
        // else if (Num == 2)
        // return true;
        for (int i = 2; i * i <= Num; i++) { // Used i*i instead of i coz of less time consumption,
                                             // We can also use i < Num
            if (Num % i == 0)
                return false;
        }
        return true;
    }

    /* --------------- Function for checking Prime Multiple Times --------------- */

    public static void MultipleCheckPrime(int Cases) {
        for (int i = 0; i < Cases; i++) {
            System.out.print("Enter your Number: ");
            int Num = scan.nextInt();
            if (isPrime(Num) == true)
                System.out.println("Prime");
            else
                System.out.println("Non Prime");
        }
    }

    public static void main(String[] args) {
        System.out.print("Enter No. of Test Case: ");
        int Cases = scan.nextInt();
        MultipleCheckPrime(Cases);
    }
}
