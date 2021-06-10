import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class QueueDemo {
    public static void main(String[] args) {
        System.out.println("The Example of Queue Demo");
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<>();

        System.out.print("How Many Elements you wants = ");
        int n = sc.nextInt();

        System.out.println("Enter those Elements -- ");
        for(int i =0;i<n;i++)
        {
            int x;
            x = sc.nextInt();
            q.offer(x);
        }

        System.out.println("Queue is :");
        while (!q.isEmpty())
        {
            System.out.println(q.poll());
        }
    }
}
