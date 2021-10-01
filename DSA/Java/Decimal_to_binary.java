import java.util.Scanner;
public class Decimal_to_binary {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the binary number: ");
		int num=sc.nextInt();
		long rem=0,binary=0,count=0;
		while(num!=0) {
			rem=num%2;
			long value=(long)(Math.pow(10, count));
			binary=binary+(rem*value);
			num/=2;
			count++;
		}
		System.out.println(binary);

	}

}
