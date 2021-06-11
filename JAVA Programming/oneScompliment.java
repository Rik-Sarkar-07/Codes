import java.util.Scanner;

public class oneScompliment {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String n;
		String m ="";
		System.out.print("Enter the binary Number = ");
		n = sc.nextLine();
		
		for(int i =0;i<n.length();i++)
		{
			if(n.charAt(i)=='1')
			{
				m = m + '0';
			}
			
			else
			{
				m = m + '1';
			}
		}
		
		System.out.print("\nThe one's Compliment of this Number = "+m);
		
		
	}

}
