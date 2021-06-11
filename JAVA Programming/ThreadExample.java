import java.lang.Thread;
class A extends Thread
{
    public void run() {         
        for(int i =0;i<=10;i++)
        {
            System.out.println("Thread A "+i);
        }
    }
}

class B extends Thread
{
    public void run() {         
        for(int i =0;i<=10;i++)
        {
            System.out.println("Thread B "+i);
        }
    }
   
}

public class ThreadExample {
    public static void main(String[] args) {
        
        A obj1 = new A();
        B obj2 = new B();

       Thread T1 = new Thread(obj1);
        Thread T2 = new Thread(obj2);
        T1.start();
        T2.start();

    }
    
}
