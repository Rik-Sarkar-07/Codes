import java.util.Scanner;

class Summation {
    public static void Addition(int a, int b, int c) {
        System.out.println("The Summation Result is  = " + (a + b + c));
    }

    public static void Addition(int a, int b) {
        System.out.println("The Summation Result is  = " + (a + b));
    }

}

public class FunctionOverloading {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a, b;
        System.out.println("How many Oparands are present = ");
        int ch = sc.nextInt();
        switch (ch) {
            case 2:
                System.out.println("Enter numbers ");
                a = sc.nextInt();
                b = sc.nextInt();
                Summation.Addition(a, b);
                break;
            case 3:
                System.out.println("Enter numbers ");
                a = sc.nextInt();
                b = sc.nextInt();
                int c = sc.nextInt();
                Summation.Addition(a, b, c);
                break;
            default:
                System.out.println("\t your choice is wrong \t \n");
        }

        sc.close();
    }

}
