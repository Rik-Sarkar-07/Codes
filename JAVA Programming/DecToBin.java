import java.util.Scanner;
public class DecToBin {

	public static void main(String[] args) {
		Scanner Sc = new Scanner(System.in);
		System.out.print("Enter the Number = ");
		int n = Sc.nextInt();
		
		System.out.println(Integer.toBinaryString(n));

	}

}
