import java.util.Scanner;

class BankAccount
{
   private double bal;
   BankAccount(double b)
   {
       bal = b;
   }
   void contact(double r)
   {
       Scanner sc = new Scanner(System.in);
       System.out.print("Enter the Password = ");
       String pass = sc.nextLine();
       if(pass.equals("xyz123"))
       {
           System.out.println("Match !!!");
           Interest in = new Interest(r);
           in.CalculateInterrest();
       }
       else
       {
           System.out.println("Sorry!!\t You are not an authorized person\n");
       }
       sc.close();
   }


   // Inner Class ---
   private class Interest
   {
       private double rate;
       Interest(double r)
       {
           rate = r;

      }
      void CalculateInterrest()
      {
          double interest = bal*rate/100;
          bal+=interest;
          System.out.println("Updated Balance= "+bal);
      }
   }

}

class InnerClass
{
    public static void main(String args[])
    {

        // Here we can't accseess Interrst class
        BankAccount obj = new BankAccount(100000);
        obj.contact(9.8);

    }
}
