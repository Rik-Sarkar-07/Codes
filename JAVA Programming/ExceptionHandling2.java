import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionHandling2 {
    public static void main(String[] args) {

        try {
            function1();
        } catch (Exception e) {
           e.getStackTrace();
           System.out.println(e.getMessage());
        }
        
    }
    static void function1(){    function2();    }

     static void function2() throws InputMismatchException
     {    
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the two numbers  = ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = a/b;
        System.out.println("The Divition of two Numbers  = "+c);
        sc.close();
        if(b==0)
        {
            throw new InputMismatchException("Danger is Coming");
        }
       
     }
}
