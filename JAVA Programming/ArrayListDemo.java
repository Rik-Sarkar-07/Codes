import java.util.*;
public class ArrayListDemo {
    public static void main(String[] args) {
        ArrayList<String> arl = new ArrayList<>();
        arl.add("Sudipta");
        arl.add("jaidep");
        arl.add("Soumodip");
        arl.add("Anirudha");
        arl.add("Pankaj");
        arl.add("Anchal");
        arl.add("Sayantan");
        arl.add("Suhin Dube");
        arl.add("Sovik");
        arl.add("Ayan");
        arl.add("Souvangaya");
        arl.add("Rupkumar");
        arl.add("Aniket");
        arl.add("Sumit");
        arl.add("Arkodip");
        arl.add("Chandan");
        System.out.println("Contents = "+arl);
        arl.remove(1);
        arl.remove("Sudipta");
        System.out.println("Contents after removing = "+arl);
        System.out.println("size of ArrayList = "+arl.size());
        System.out.println("Iterator ---");
        Iterator it = arl.iterator();
        while (it.hasNext())
        {
            System.out.println(it.next());
        }

    }
}
