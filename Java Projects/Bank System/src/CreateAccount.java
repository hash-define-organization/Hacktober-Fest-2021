import java.util.Random;
import java.util.Scanner;

public class CreateAccount {
	
	public static void display() {
		System.out.println("Enter Your Name");
		Scanner sc = new Scanner(System.in);
		String name = sc.nextLine();
		Random rand = new Random();
		int accountNo = rand.nextInt(9999) + 1000;
		System.out.println("Your Account is created. \n"+ name +" your Account Number is " + accountNo);
		System.out.println("Enter 0 to return.");
		int option = sc.nextInt();
		if(option == 0) {
			MainClass.display();
		}
	}

}
