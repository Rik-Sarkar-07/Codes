import java.util.Scanner;

class Fibonacii {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int a = 0,b = 1;
        int c  = a+b;
        
        System.out.print("Enter How many Fibonacii Number you want = ");
        int n = sc.nextInt();

        System.out.print("\t"+a+"\t"+b+"\t");

        for(int i=1;i<n-1;i++)
        {
            
            c = a + b;
            a = b;
            b = c;
            System.out.print(c+"\t");
        }
            sc.close();

    }
    
}
