public class K_nthMaxAndMin {
    public static void K_nthMin(int []a,int k)
    {
        int i,j,temp;
        int n = a.length;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n-1;j++)
            {
                if (a[j]>a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
            int l = k-1;

            System.out.println("The " + k + "th Min Element is = " + a[l]);

    }
    public static void K_nthMax(int []a,int k)
    {
        int i,j,temp;
        int n = a.length;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n-1;j++)
            {
                if (a[j]>a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        int l = n-k;

        System.out.println("The " + k + "th Max Element is = " + a[l]);
    }

    public static void main(String[] args) {
        int []array = {1,2,9,3,4,7,8,15,6,0};
        K_nthMin(array,4);
        K_nthMax(array,3);
    }
}
