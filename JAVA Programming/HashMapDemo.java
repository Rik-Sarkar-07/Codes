import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class HashMapDemo {
    public static void main(String args[])
    {
        HashMap<String,Integer> map1 = new HashMap<>();
        System.out.print("How Many students are presents in this class room = ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Enter those Student Names and corrisponding Rolls ---");
        String name;
        Integer x;
        int roll;
        for (int i =0;i<n;i++)
        {
            name = sc.nextLine();
            System.out.print("Name ["+(1+i)+"] = " );
            name = sc.nextLine();
            System.out.print("Roll ["+(1+i)+"] = ");
            roll = sc.nextInt();
            x = Integer.valueOf(roll);
            map1.put(name,x);
        }

        System.out.println("Collection is  = "+map1);



    }
}
