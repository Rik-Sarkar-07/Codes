public class MinimumAndMaximum {

    public static void MinAndMax(int []a)
    {
        int i,j,size = a.length;
        int min = a[0];
        int max = a[size-1];
        for (i=1;i<size;i++)
        {
            if(min>a[i])
            {
                min = a[i];
            }
        }
        for (i=size-2;i>=0;i--)
        {
            if(max<a[i])
            {
               max = a[i];
            }
        }
        System.out.println("Lowest Element is = "+min);
        System.out.println("Highest Element is = "+max);
    }

    public static void main(String[] args) {
        int []array = {1,3,0,4,5,6,70,8,9,10};
        MinAndMax(array);
    }
}
