import java.util.*;
public class StackDemo {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        int choice = 0;
        int position, element;
        Scanner sc = new Scanner(System.in);
        for ( ; ; )
        {
        System.out.println("Stack Operations");
        System.out.println("1 - Push Element");
        System.out.println("2 - Pop Element");
        System.out.println("3 - Search Element");
        System.out.println("4 - Exit");
        System.out.print("Enter Your Choice -> ");
        choice = sc.nextInt();
        switch (choice) {
            case 1:
                System.out.print("Enter Element = ");
                element = sc.nextInt();
                Integer val = Integer.valueOf(element);
                st.push(val);
                break;
            case 2:
                Integer obj = st.pop();
                System.out.println("Popped Element = " + obj);
                break;
            case 3:
                System.out.print("Which Element = ");
                element = sc.nextInt();
                Integer val2 = Integer.valueOf(element);
                position = st.search(val2);
                if (position == -1) {
                    System.out.println("Not Match");
                } else {
                    System.out.println("Position is = " + position);
                }
                break;
            default:
                System.exit(0);

        }

            System.out.println("Stack = "+st);
    }               //



    }
}
