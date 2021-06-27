class MyThread1 extends Thread
{
    public void run()
    {
        for(int i = 0;i<1000;i++)
        {
            System.out.println("Now i am chat with my friend \t"+i);
        }
    }
}

class MyThread2 extends Thread
{
    public void run()
    {
        for(int i = 0;i<1000;i++)
        {
            System.out.println("Now i am cooking \t"+i);
        }
    }
}

public class ThreadClass {
    public static void main(String[] args) {

        MyThread1 t1 = new MyThread1();
        MyThread2 t2 = new MyThread2();

        t1.start();
        t2.start();

    }
}
