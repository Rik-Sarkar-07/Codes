import java.util.Scanner;

public class Array_Oparations {

	public static void main(String[] args) {
		   int n;
	        try (Scanner sc = new Scanner(System.in)) {
				System.out.print("Enter How many Elements you wants = ");
				n = sc.nextInt();
				int a[] = new int[n];
				System.out.println("Enter those Elements");
				int i = 0;
				for (i = 0; i < n; i++) {
				    a[i] = sc.nextInt();
				}
				System.out.println("So, The Elements are - ");

				for (i = 0; i < n; i++) {
				    System.out.print(a[i] + "\t");
				}
				
				// Shorting 
				
				for(i=0;i<n;i++)
				{
					for(int j=0;j<n-1;j++)
					{
						if(a[j]>a[j+1])
						{
							int tmp;
							tmp = a[j];
							a[j] =a[j+1];
							a[j+1] = tmp;
						}
					}
				}
				
				System.out.print("\nAfter shorting \n");

				for (i = 0; i < n; i++) {
				    System.out.print(a[i] + "\t");
				}
				
				System.out.print("\nBig Element of this Array = "+a[n-1]+"\n");
				System.out.print("\nSmall Element of this Array = "+a[0]+"\n");
				
				int sum = a[0];
				
				for(i=1;i<n;i++)
				{
				sum = sum + a [i];
				}
				
				System.out.print("\nSummation of All Elements = "+sum+"\n");
				float avg = sum / n;
				System.out.print("\nAvg = "+avg+"\n");
			}
	}

}
