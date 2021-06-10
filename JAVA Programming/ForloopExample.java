public class ForloopExample {
public static void main(String args[])
{
    int a[] = {1,2,4,5,6,7,8,9,2,34,6,8,9};
    int i =0;
//    for (i=0;i<13;i++)
//    {
//        System.out.println(a[i]);
//    }
//    System.out.println("\n");
//    for (int e:a) {
//        System.out.println(e);
//    }

    System.out.println("\n\n");
        int b[][] = { {1,2},{3,4},{5,6},{7,8},{2,6} };

        for (int []c:b ) {


            for(int arr:c)
            {
                System.out.println(arr);
           }


         //   System.out.println(b);
            }
}
}
