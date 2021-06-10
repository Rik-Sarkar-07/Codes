// import java.lang.*;
// import java.util.*;

interface My_methods {
    public void Price(double p);

    public void Color(String c);

    public void Old(int year);

    public void Engine(String e);

    public void Name(String name);

    public void Mileage(double m);
}

class Car implements My_methods {
    Car(String no) {
        System.out.println("Car No - " + no);
        System.out.println("\n The Details of This Car \n");
    }

    public void Price(double p) {
        System.out.println("The price of the car = " + p + " $");
    }

    public void Color(String c) {
        System.out.println("The Color of this car = " + c);
    }

    public void Old(int year) {
        System.out.println("The Car is " + year + " old");
    }

    public void Engine(String e) {
        System.out.println("Power = " + e + " CC");
    }

    public void Name(String name) {
        System.out.println("The name of this Car = " + name);
    }

    public void Mileage(double m) {
        System.out.println("The Mileage of this Car = " + m + " L/Km");
    }
}

public class CarProject {
    public static void main(String[] args) {

        Car cr = new Car("WB-741122");
        cr.Name("Fort BMW-4080X");
        cr.Color("Black");
        cr.Old(05);
        cr.Engine("942.22");
        cr.Mileage(30.56);
        cr.Price(70000);
    }
}
