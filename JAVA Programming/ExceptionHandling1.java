import java.util.Scanner;

class ExceptionHandling1 {
    public static void main(String[] args) {
        try {
            Scanner sc =new Scanner(System.in);
            int a = sc.nextInt();
            int b  =sc.nextInt();
            int d =a/b;
            System.out.println("THE Divition result is  = "+d);
            sc.close();
        } catch (Exception e) {
           
            System.out.println(e.getMessage());
        }
    }
    
}
