class MyThr extends Thread
{
    MyThr(String name)
    {
        super(name);
    }
    @Override
    public void run() {
        for(int i=0;i<100;i++)
        System.out.println("Thread = "+i);
    }
}
public class ThreadConstructors {
    public static void main(String[] args) {
        MyThr t1 = new MyThr("Hello");
        MyThr t2 = new MyThr("World");

        t1.start();
        t2.start();

        System.out.println("The id of thread t1 = "+t1.getId());
        System.out.println("The name of thread t1 = "+t1.getName());
        System.out.println("The Priority of thread t1 = "+t1.getPriority());
        System.out.println("The id of thread t2 = "+t1.getId());
        System.out.println("The Priority of thread t2 = "+t2.getPriority());
    }
}
