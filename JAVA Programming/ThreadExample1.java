class D
{
    public void Hi()
    {
        System.out.println(" I am Indian ");
    }
}
class A1 extends D implements Runnable
{
    @Override
    public void run() {
        int i = 0;
        for(i=0;i<=10;i++)
        {
            System.out.println("Thread A = "+i);
        }
    }
}

class B1 implements Runnable
{
    @Override
    public void run() {
        int i = 0;
        for(i=0;i<=10;i++)
        {
            System.out.println("Thread B = "+i);
        }
    }
}

public class ThreadExample1 {
    public static void main(String[] args) {
        A1 obj1 = new A1();
        B1 obj2 = new B1();

        Thread T1 = new Thread(obj1);
        Thread T2 = new Thread(obj2);
        T1.start();
        T2.start();
        obj1.Hi();

    }
    
}
