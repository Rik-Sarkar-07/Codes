import java.util.Scanner;

class Factorial
{
    public static long factorial(int n)
    {
        long fact;

        if(n<0)
        {
            System.out.println("!!! Wrong !!!");
            fact =  -12;
            return fact;
        }
            else if(n==0)
            {
                return 1;
            }

            else
            {
                return(n * factorial(n-1));
            }
       
    }
    public static void main(String[] args) {
        
        System.out.print("Enter the number  = ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println("Fatorial of "+n+" ! "+"= "+factorial(n));

            sc.close();

    }
}
