public class SelectionSort {
    public static void Selection_Sort(int A[], int n) {
        int i, j, min;

        for (i = 0; i < n - 1; i++) {
            min = i;
            for (j = i + 1; j < n; j++) {
                if (A[j] < A[min]) {
                    min = j;
                }
            }

            int temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }

    public static void main(String[] args) {

        int arr[] = { 4, 7, 9, 21, 3, 4, 5, 1 }; // size 8 ;
        int n = 8;
        System.out.println("Print Array Before Sorting ");
        for (int e : arr) {

            System.out.print("\t" + e);

        }

        System.out.println("\nPrint Array After Sorting ");
        Selection_Sort(arr, n);
        for (int e : arr) {

            System.out.print("\t" + e);

        }
    }

}
