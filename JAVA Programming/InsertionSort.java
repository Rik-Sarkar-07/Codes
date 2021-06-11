public class InsertionSort {
    
    public static void Insertion_Sort(int A[],int n)
    {
        int i,j,k;

        for(i=1;i<n;i++)
        {
            k = A[i];  j = i-1;

            while(j>=0 && k<A[j])
            {
                A[j+1] = A[j];
                j--;
            }

            A[j+1] = k;
        }
    }

    public static void main(String[] args) {
        int arr[] = {4,7,9,21,3,4,5,1};    // size 8 ;
        int n = 8;
         System.out.println("Print Array Before Sorting ");
         for (int e : arr) {
 
             System.out.print("\t"+e);
             
         }
 
         System.out.println("\nPrint Array After Sorting ");
         Insertion_Sort(arr, n);
         for (int e : arr) {
 
             System.out.print("\t"+e);
             
         }
    }
}
