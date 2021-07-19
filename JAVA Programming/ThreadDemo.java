class AThread extends Thread
{
    String name;
    AThread(String name)
    {
        this.name = name;
        start();
    }
    @Override
    public void run() {
        ThreadDemo.function(name);
    }
}

//class BThread extends Thread
//{
//    BThread(String name)
//    {
//        super.setName(name);
//        ThreadDemo.method(super.getName());
//        start();
//    }
//}

public class ThreadDemo
{

    synchronized public static void function(String str)
    {
        for (int i=1;i<=10;i++)
        {
            System.out.println("The Name of the thread is => "+str+" \t and No => "+i);
            try {
                Thread.sleep(500);
            }catch (InterruptedException e)
            {
                System.out.println(e.getMessage());
            }
        }
        System.out.println("\n-------------\t"+str+" End !! ------------ \n");
    }


//    synchronized public static void method(String str)
//    {
//        for (int i=1;i<=10;i++)
//        {
//
//            System.out.println("The Name of the thread is => "+str+" \t and No => "+i);
//            try {
//                Thread.sleep(500);
//            }catch (InterruptedException e)
//            {
//                System.out.println(e.getMessage());
//            }
//        }
//        System.out.println("\n-------------\t"+str+" End !! ------------ \n");
//    }


    public static void main(String[] args) {
        AThread aThread1 = new AThread("First Thread");
        AThread aThread2 = new AThread("Second Thread");

//        BThread bThread1 = new BThread("First Thread");
//        BThread bThread2 = new BThread("Second Thread");


    }
}
