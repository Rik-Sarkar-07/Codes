class NegativeRadiusException extends Exception     // Programmer define (explicitly) Exception for throw key
{
    public String toString(){
        return "Radius can be Negative\n";
    }

    @Override
    public String getMessage() {
        return "Wrong !!";
    }
}

public class Throw_and_Throws {
    public static double area (int r) throws NegativeRadiusException      // it means that this method may throw an Exception
    {
        if(r<0)
        {
            throw new NegativeRadiusException();
        }

            double a = Math.PI * r *r;
         return a;
    }
    public static int divide(int a,int b) throws ArithmeticException     // it means that this method may throw an Exception
    {
        int d = a/b;
        return d;
    }


    public static void main(String[] args) {
    // ** Handling throws method
        try {
           divide(56,0);
        }
        catch (ArithmeticException e)
        {
            System.out.println(e.getMessage());
        }

        //  ** Handling throw and throws method   [only throw not exist]
        try {
            area(-12);
        }
       catch (NegativeRadiusException e)
       {
           System.out.println(e.toString());
           System.out.println(e.getMessage());
       }
        finally {                                 // it is always run
            System.out.println("End the program");
        }

    }

}

