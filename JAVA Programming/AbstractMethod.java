abstract class Human
{
    public
    
    double hight;
    String name;
    int Age;
    abstract public void land(String c);
   
}

class Indian {
    Indian(double hight, String name, int Age) {
        System.out.println("Hight = " + hight + " ft");
        System.out.println("Name = " + name);
        System.out.println("Age = " + Age);

    }

    void land(String c) {
        System.out.println("I am "+ c);
    }
}

public class AbstractMethod {
    public static void main(String[] args) {

        Indian id = new Indian(5.11, "Sudipta Sarkar", 18);

        id.land("Indian");

    }

}
