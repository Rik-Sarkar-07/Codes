import java.util.*;
public class LinkedHashSetDemo {
    public static void main(String[] args) {
        LinkedHashSet<Integer> roll = new LinkedHashSet<>();
        roll.add(727);
        roll.add(702);
        roll.add(708);
        roll.add(726);
        roll.add(728);
        roll.add(725);
        System.out.println("The Roll No Set is  = "+roll);

        Iterator it = roll.iterator();
        System.out.println("Printing Using Iterator ");
        while (it.hasNext())
        {
            Integer i = (Integer)it.next();
            System.out.println(i);
        }
    }
}
