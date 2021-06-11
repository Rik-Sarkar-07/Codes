import java.util.Scanner;

class Summation {
    public void Addition(int a, int b) {
        System.out.println("The Summation Result is  = " + (a + b));
    }

}

class Sum extends Summation {
    public void Addition(int a, int b) {
        System.out.println("The Summation Result is  = " + (a + b));
        System.out.println(" Overriding Function ");
    }
}

public class FunctionOverridding {
    public static void main(String[] args) {
        Sum s1 = new Sum();
        Summation s2 = new Summation();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter two Numbers ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        s1.Addition(a, b); // Overriding Function
        s2.Addition(a, b);
        sc.close();
    }

}
