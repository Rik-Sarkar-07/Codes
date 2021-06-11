class LinearSearch {
    public static int Linear_Search(int A[], int n, int data) {
        int i;
        for (i = 0; i < n; i++) {
            if (A[i] == data) {
                return i;

            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int arr[] = { 4, 7, 9, 21, 3, 4, 5, 1 }; // size 8 ;
        int n = 8;

        int k = Linear_Search(arr, n, 3);
        System.out.println("The Position of this Element = " + k);

    }
}
