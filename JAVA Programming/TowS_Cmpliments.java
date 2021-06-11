

import java.util.Scanner;

public class TowS_Cmpliments {

	public static void main(String[] args) {
		
	
		Scanner sc =new Scanner(System.in);

		int  i = 0,j =0,k =0;
		String n;
		System.out.print("Enter the Binary Number = ");
		n = sc.nextLine();
		
		for(i=0;i<n.length();i++)
		{
			if(n.charAt(i)=='1')
			{
				k = i;
			}
		}
		
		// System.out.print(k);
		
		
		System.out.print("Tow's Compliments of this Number = ");
		
		for(i=0;i<k;i++)
		{
			if(n.charAt(i) == '0')
			{
			System.out.print(1);
			}
			
			else
			{
				System.out.print(0);
			}
		}
		
		for(i=k;i<n.length();i++)
		{
			if(n.charAt(i) == '0')
			{
			System.out.print(0);
			}
			
			else
			{
				System.out.print(1);
			}
		}
		
		System.out.print("\n\n");
		
	}

}
