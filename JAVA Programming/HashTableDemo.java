import java.util.Enumeration;
import java.util.Hashtable;

public class HashTableDemo {
    public static void main(String[] args) {
        Hashtable<String,Integer> ht = new Hashtable<>();
        ht.put("Rohit Sharma",237);
        ht.put("Shekhar Dhawan",183);
        ht.put("Virat Kohli",188);
        ht.put("Ms Dhoni",187);
        ht.put("Kl Rahul",157);
        System.out.println("Players Names --");
        Enumeration e = ht.keys();
        while (e.hasMoreElements())
        {
            System.out.println(e.nextElement());
        }
    }
}
