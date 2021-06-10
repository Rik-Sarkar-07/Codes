// import java.util.Scanner;

class Manu {
    public static void Summation(double a, double b) {
        double c = a + b;
        System.out.println("The Summation of Two numbers are = " + c);
    }

    public static void Divition(double a, double b) {
        double c = a / b;
        System.out.println("The Divition of Two numbers are = " + c);
    }

    public static void Multiplication(double a, double b) {
        double c = a * b;
        System.out.println("The Multiplication of Two numbers are = " + c);
    }

    public static void Substraction(double a, double b) {
        double c = a - b;
        System.out.println("The Substraction of Two numbers are = " + c);
    }

    public static void Factorial(int n) {
        long fact = 1;
        int i = 1;
        for (i = 1; i <= n; i++) {
            fact = fact * i;
        }
        System.out.println("The Factorial is = " + fact);
    }

    public static void Power(double a, double b) {
        double c = Math.pow(a, b);
        System.out.println("The power of this Number = " + c);
    }
}

public class ManuDriven {

    public static void main(String[] args) {
        System.out.println("Inside main");

        double a = 15;
        double b = 14;
        int n = 6;
        Manu.Summation(a, b);
        Manu.Divition(a, b);
        Manu.Factorial(n);
        Manu.Multiplication(a, b);
        Manu.Power(a, 3);
        Manu.Substraction(a, b);
    }

}
