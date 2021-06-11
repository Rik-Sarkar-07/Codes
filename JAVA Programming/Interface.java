interface Method {
    public void method1(int a, int b);

    public void method2(int a, int b);

    public void method3(int a, int b);

    public void methode4(int a, int b);

    public void methode5(int a);
}

class Impliment implements Method {
    Impliment() {
        System.out.println("\t Welcome to Virtual calculator");
    }

    public void method1(int a, int b) {
        System.out.println("Summation = " + (a + b));
    }

    public void method2(int a, int b) {
        System.out.println("Divition = " + (a / b));
    }

    public void method3(int a, int b) {
        System.out.println("Multiplicatin = " + (a * b));
    }

    public void methode4(int a, int b) {
        System.out.println("Subtraction = " + (a - b));
    }

    public void methode5(int a) {
        long fact = 1;
        int i = 0;
        for (i = 1; i <= a; i++) {
            fact = fact * i;
        }
        System.out.println("Factorial of this number = " + fact);
    }
}

public class Interface {
    public static void main(String[] args) {
        Impliment ip = new Impliment();
        int a = 6;
        int b = 2;
        ip.method1(a, b);
        ip.method2(a, b);
        ip.method3(a, b);
        ip.methode4(a, b);
        ip.methode5(a);
    }

}
