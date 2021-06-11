import java.util.*;
public class FactorChekar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter The Number = ");
        double x = sc.nextDouble();

        for(int i =1;i<=x;i++)
        {
            if( x % i == 0)
            {
                System.out.println(i);
            }
        }
        sc.close();
    }
    
}
