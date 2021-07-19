public class ReverseArray {


    public static void reverse(int []a)
    {
        System.out.println("Reverse of The Array is ---");
        int size = a.length;
        for(int i = size-1;i>=0;i--)
        {
            System.out.print("\t" + a[i]);
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int []array = {1,2,3,5,7};
       reverse(array);

    }
}
