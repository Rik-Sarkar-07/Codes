public class BinarySearch {

    public static int Binary_Search(int A[], int n, int data) {
        int low = 0;
        int high = n - 1;
        int mid;

        while (high >= low) {
            mid = low + high;
            if (data == A[mid]) {
                return mid;
            }

            else if (data > A[mid]) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 }; // size 8 ;
        int n = 8;
        int k = Binary_Search(arr, n, 5);
        System.out.println("The place of this Element is  = " + k);

    }

}
