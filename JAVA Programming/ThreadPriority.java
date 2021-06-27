class PriorityThread extends Thread
{
    @Override
    public void run() {
        System.out.println("I am in thread "+Thread.currentThread().getName());
        System.out.println("the thread "+Thread.currentThread().getPriority());
    }
}
public class ThreadPriority {
    public static void main(String[] args) throws InterruptedException {
        PriorityThread pt1 = new PriorityThread();
        PriorityThread pt2 = new PriorityThread();
        pt1.setPriority(Thread.MIN_PRIORITY);
        pt2.setPriority(10); // max priority

        pt1.start();
        Thread.sleep(12333);
        pt2.start();
    }

}
