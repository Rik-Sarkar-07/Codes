public class SortThreeNumber {
    public static void sort(int []a) {

        int n  = a.length;
        int []b = new int[n];
        int c=0;

        for (int j : a) {
            if (j == 0) {
                b[c] = j;
                c++;
            }
        }

        for (int j : a) {
            if (j == 1) {
                b[c] = j;
                c++;
            }
        }

        for (int j : a) {
            if (j == 2) {
                b[c] = j;
                c++;
            }
        }
        for (int e:b) {
            System.out.print("\t"+e);
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int []array = {1,2,0,1,2,0,2};
        sort(array);
    }
}
