import java.util.*;
public class VectorClass {
    public static void main(String[] args) {
        Vector<Integer> vec = new Vector<>();
        int x[] = {12,5,46,36,5,6,46,4,616,63};
    for (int i =0 ;i<x.length;i++)
    {
       vec.add(x[i]);
    }
    for (int  i=0;i<vec.size();i++)
    {
        System.out.println(vec.get(i));
    }
        System.out.println("Print using iterator --");
        System.out.println("forward direction");
        ListIterator lit = vec.listIterator();  // Bidirectional but Iterator is Unidirectional
        while (lit.hasNext())
        {
            System.out.print(lit.next()+"\t");
        }
        System.out.println("backward direction --");

        while (lit.hasPrevious())
        {
            System.out.print(lit.previous()+"\t");
        }

    }
}
