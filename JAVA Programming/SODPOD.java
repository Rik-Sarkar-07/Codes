import java.util.Scanner;

public class SODPOD {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number = ");
        n = sc.nextInt();
        int pod = 1;
        int sod = 0;
        int rev = 0;
        int rem = 0;
        int cot = 0;
        while (n > 0) {
            rem = n % 10;
            pod = pod * rem;
            sod = sod + rem;
            rev = rev * 10 + rem;
            n = n / 10;
            cot++;
        }

        System.out.println("Reverse of the number = " + rev);
        System.out.println("The Product of Digit = " + pod);
        System.out.println("The sum of Digit = " + sod);
        System.out.println("Didts count = " + cot);
        sc.close();
    }
}
