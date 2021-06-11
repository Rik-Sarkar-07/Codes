import java.util.Scanner;

public class CheckANumberIsPrimeOrNot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num;
        boolean flag = true;
        System.out.print("Enter a number = ");
        num = sc.nextInt();
        if (num>2 && num % 2 ==0)
        {
            flag = false;
        }
        else {
            for (int i=3;i<=Math.sqrt(num);i=i+2)
            {
                if(num % i == 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                System.out.println(num + " is prime");
            }

           else {
                System.out.println(num + " is not prime");
            }

        }

    }
}
