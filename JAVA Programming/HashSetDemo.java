import java.util.*;
public class HashSetDemo {
    public static void main(String[] args) {
        HashSet<String> hs = new HashSet<>();
        hs.add("India");
        hs.add("USA");
        hs.add("England");
        hs.add("Japan");
        hs.add("China");
        hs.add("Israel");

        System.out.println("HashSet = "+hs);

        Iterator it = hs.iterator();
        System.out.println("Element Using Iterator : ");

        while (it.hasNext())
        {
            String s = (String) it.next();
            System.out.println(s);
        }

    }
}
