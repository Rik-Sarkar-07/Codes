import java.util.*;
public class LinkedListDemo {
    public static void main(String[] args) {
        LinkedList<String> ll = new LinkedList<>();
        ll.add("India");
        ll.add("England");
        ll.add("Japan");
        ll.add("Spain");
        System.out.println("LinkedList = "+ll);
        int position,choice = 0;
        Scanner sc = new Scanner(System.in);
        String element;
        for ( ; ; )
        {
            System.out.println("\n LINKEDLIST OPERATIONS ");
            System.out.println("1 - Add Element");
            System.out.println("2- Remove Element");
            System.out.println("3- Change Element");
            System.out.println("4- EXIT");
            System.out.println("Enter your choice = ");
            choice = sc.nextInt();
            switch (choice)
            {
                case 1:
                    System.out.print("Enter Element = ");
                    element = sc.nextLine();
                    element = sc.nextLine();
                    System.out.print("At what position = ");
                    position = sc.nextInt();
                    ll.add(position-1,element);
                    break;
                case 2:
                    System.out.println("Enter Position : ");
                    position = sc.nextInt();
                    ll.remove(position-1);
                    break;
                case 3:
                    System.out.println("Enter Position ");
                    position = sc.nextInt();
                    System.out.println("Enter nwe Element = ");
                    element = sc.nextLine();
                    element = sc.nextLine();
                    ll.add(position-1,element);
                    break;
                default:
                    System.exit(0);
            }
            System.out.print("List = ");
            Iterator it = ll.iterator();
            while (it.hasNext())
            {
                System.out.println(it.next()+"  ");
            }
        }
    }
}
