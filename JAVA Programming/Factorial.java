import java.util.Scanner;

public class Factorial {

    public static void main(String[] args) {

            int n;
            long f = 1;
            Scanner sc = new Scanner(System.in);
            n = sc.nextInt();

            for (int i = 1; i <= n; i++) {
                f = f * i;
            }

            System.out.println("Factorial = "+f);


    }
}
