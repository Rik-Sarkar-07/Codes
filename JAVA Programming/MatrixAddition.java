import java.util.Scanner;

public class MatrixAddition {
    public static void main(String[] args) {
        
        System.out.println("Enter the numbers of rows and collums --");
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int i = 0,j = 0;

        int array1[][] = new int[m][n];
        int array2[][] = new int[m][n];

        System.out.println("Enter the First Array's elements --");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                array1[i][j] = sc.nextInt();
            }
        }


        System.out.println("Enter the Second Array's elements --");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                array2[i][j] = sc.nextInt();
            }
        } 


        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                array1[i][j] = array2[i][j] + array1[i][j];
            }
        }

        System.out.println("\t -- The Additon of Array's --");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                System.out.print("\t"+array1[i][j]);
                
            }
            System.out.println("\n");
        }


System.out.println("\n\n\n\n");

        sc.close();
    }
    
}
