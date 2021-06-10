
class Adder {
   public static int Sum(int a, int b) {
        return (a + b);
    }

    static int Sum(int a, int b, int c) {
        return (a + b + c);
    }

    static int Product(int a, int b, int c) {
        return (a * b * c);
    }

    static int Product(int a, int b) {
        return (a * b);
    }
}

public class MethodOverloading {

    public static void main(String[] args) {
        //  int x,y,z;
        System.out.println(Adder.Sum(12,12));

    }
}
