
/*
            To find the factorial of a given number  and Generate a Fibonacci Series
 */

import java.util.Scanner;

public class FactorialAndFibonacci {

   public static long Factorial(int n)
    {
        if(n<0)
        {
            System.out.println("Your Entered Number is Negative !!!!!!!");
            return -1;
        }
        else if(n==0 || n==1)
        {
                return 1;
        }
        else
        {
            return (n * Factorial(n-1));
        }
    }

    public static int Fibonacci(int n)
    {
        if(n==1 || n==0)
        {
           return 1;
        }
        else
        {
            return (Fibonacci(n-1) + Fibonacci(n-2));
        }
    }

    public static void main(String[] args) {

        System.out.print("Enter The Number = ");
        Scanner sc =new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Factorial of this Number  = "+Factorial(n));
        System.out.print("Enter How Many Fibonacci Numbers You want  = ");
        int m = sc.nextInt();
        System.out.println("The Fibonacci Series is ");
        for (int i =0;i<m;i++)
        {
            System.out.print("\t"+Fibonacci(i));
        }

    }

}
