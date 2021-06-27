package ThreedInJava;
class MyThreadRunnable1 implements Runnable
{
    public void run()
    {
        for(int i = 0;i<100;i++)
        {
            System.out.println("Now I am chat with my friend \t"+i);
        }
    }
}
class MyThreadRunnable2 implements Runnable
{
    public void run()
    {
        for(int i = 0;i<100;i++)
        {
            System.out.println("Now I am Cooking \t"+i);
        }

    }
}

public class ThreadRunnableClass {
    public static void main(String[] args) {
        MyThreadRunnable1 rt1 = new MyThreadRunnable1();
        Thread t1 = new Thread(rt1);

        MyThreadRunnable2 rt2 = new MyThreadRunnable2();
        Thread t2 = new Thread(rt2);

        t1.start();
        t2.start();

        /*
            t1.run();  // it is helps to normal run of t1 thread
         */
    }
}
