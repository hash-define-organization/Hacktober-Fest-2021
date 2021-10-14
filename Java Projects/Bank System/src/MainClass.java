import java.util.Scanner;

public class MainClass {
	
	public static void main(String[] args) {
		MainClass.display();
	}	
		
	public static void display() {
		Scanner sc = new Scanner(System.in);
		System.out.println("We Welcome You! \n Choose an Option. \n 1 Create an Account \n 2 Operate My Account \n 3 Exit");
		int option = sc.nextInt();
		switch(option) {
			case 1:
				CreateAccount.display();
				break;
				
			case 2:
				OperateAccount.display1();
				break;
				
			case 3:
				System.out.println("Thank You!");
				break;
		}
	}
}
