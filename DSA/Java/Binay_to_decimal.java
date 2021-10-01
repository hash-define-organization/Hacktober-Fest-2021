import java.util.*;
public class Binay_to_decimal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the binary number: ");
		int num=sc.nextInt();
		int rem=0,decimal=0,count=0;
		while(num!=0) {
			rem=num%10;
			int value=(int)(Math.pow(2, count));
			decimal=decimal+(rem*value);
			num/=10;
			count++;
		}
		System.out.println(decimal);

	}

}
