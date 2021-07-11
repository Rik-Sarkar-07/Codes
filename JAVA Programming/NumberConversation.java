import java.util.Scanner;
public class NumberConversation {
    public static void main(String[] args) {
        System.out.print("Enter A Decimal Number  = ");
        Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();
       String bin = Integer.toBinaryString(n);
       String oct  = Integer.toOctalString(n);
       String hex = Integer.toHexString(n);

        System.out.println("The Number's Binary Value = "+bin+"\t "+"Octal value = "+oct+"\t Hexadecimal Value is = "+hex);

    }
}
