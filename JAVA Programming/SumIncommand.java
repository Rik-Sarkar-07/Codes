public class SumIncommand {
    public static void main(String[] args) {
        int size = args.length;
        int Sum = 0;
        long Prod = 1;
        for(int i = 0;i<size;i++)
        {
            Sum = Integer.parseInt(args[i]) + Sum;
            Prod = Long.parseLong(args[i]) * Prod;
        }
        System.out.println("You Entered "+size+" Elements So Summation of Those Numbers = "+Sum+"\t"+" Product of those Numbers = " +Prod);
    }
}
