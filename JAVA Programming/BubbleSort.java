public class BubbleSort {

    public static void Bubble_Sort(int A[], int n) {
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                if (A[j] > A[j + 1]) {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
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
        Bubble_Sort(arr, n);
        for (int e : arr) {

            System.out.print("\t" + e);

        }
    }

}
