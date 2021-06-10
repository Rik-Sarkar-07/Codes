public class ExaptionHandleing {
    public static void main(String[] args) {

        try{
            int a = 12;
            int b = 0;
            int c = a /b ;
            System.out.println(c);
        }

       catch (ArithmeticException e)
       {
           System.out.println(e.getMessage() + " Error !! ");
       }

    }
}
