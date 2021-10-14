import java.util.Scanner;

public class OperateAccount {
	int balance = 500 ;
	int previousTransaction;
	String customerName, customerID;
	Scanner sc = new Scanner(System.in); 
	public static void display1() {
		System.out.println("Enter your name.");
		Scanner sc = new Scanner(System.in); 
		String name = sc.nextLine();
		System.out.println("We Welcome You "+name);
		
		OperateAccount.display2();
	}
	
	public static void display2() {
		int option;
		OperateAccount oa = new OperateAccount();
		Scanner sc = new Scanner(System.in);
		System.out.println("Choose any option. \n 1 View Balance \n 2 Withdraw \n 3 Deposit \n 4 Check Previous Transaction \n 5 Previous Menu \n 6 Exit");
		
		
		do {
			System.out.println("Choose any option. 1 View Balance  2 Withdraw  3 Deposit  4 Check Previous Transaction  5 Previous Menu  6 Exit");
			option = sc.nextInt();
			
			switch(option) {
				case 1:
					oa.balance();
					break;
					
				case 2:
					oa.withdraw();
					break;
					
				case 3:
					oa.deposit();
					break;
				case 4:
					oa.previousTransaction();
					break;
					
				case 5:
					MainClass.display();
					break;
				
				case 6:
					System.out.println("Thank You!");
					break;	
			}
		}while(option != 6 && option != 5);
	}
	
	public void balance() {
		System.out.println("Your Account Balance = "+ balance);
	}
	
	public void withdraw() {
		if(balance==0) {
			System.out.println("You have insufficient balance.");
		}else {
			System.out.println("Enter the amount.");
			int amount = sc.nextInt();
			if(amount <= balance) {
				System.out.println("Withdrawel of Rs "+ amount +" is completed.");
				balance = balance-amount;
				previousTransaction = -amount;
				System.out.println("Your Current Balance is Rs "+ balance);
			}else {
				System.out.println("You have insufficient balance.");
			}
		 }
	}
	
	public void deposit() {
		System.out.println("Enter the amount.");
		int amount = sc.nextInt();
		if(amount > 0) {
			balance += amount;
			System.out.println("Transaction Successful");
			System.out.println("Your Current Balance is Rs "+ balance);
			previousTransaction = amount;
		}else {
			System.out.println("Please Check Your Amount");
		}
		
	}
	
	public void previousTransaction() {
		if(previousTransaction > 0) {
			System.out.println("Rs "+previousTransaction+" was Credited.");
		}else {
			System.out.println("Rs "+ Math.abs(previousTransaction)+" was Debited.");
		}
	}
	
}
