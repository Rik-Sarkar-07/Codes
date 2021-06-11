abstract class Animal {

    abstract void Bread(String name);

    abstract void Name(String name);

    private String Gender;
    private int N_O_H;
    private int N_O_L;
    private int N_O_E;

    public Animal(String gender, int hands, int leges, int eyes) {
        this.Gender = gender;
        this.N_O_E = eyes;
        this.N_O_H = hands;
        this.N_O_L = leges;
        System.out.println("The Gender of this Animal is = " + Gender);
        System.out.println("The Numbers of Legs of this Animal = " + N_O_L);
        System.out.println("The Numbers of Hands of this Animal = " + N_O_H);
        System.out.println("The Numbers of Eyes of this Animal = " + N_O_E);
    }

}

public class Human extends Animal {
    public Human(String gender, int hands, int leges, int eyes) {

        super(gender, hands, leges, eyes);

    }

    void Bread(String name) {
        System.out.println("The Name of this Bread = " + name);
    }

    void Name(String name) {
        System.out.println("The Name of this person = " + name);

    }

    // # Feature of human class members
    public static void SchoolDetails(String Sname, int roll, int Class, String FatherName) {
        System.out.println("The Father name of the Student is = " + FatherName);
        System.out.println("The School name of the Student is = " + Sname);
        System.out.println("The Roll No of the Student is = " + roll);
        System.out.println("The class of the Student is = " + Class);
    }
}

class Dog extends Animal {
    public Dog(String gender, int hands, int leges, int eyes) {

        super(gender, hands, leges, eyes);

    }

    void Bread(String name) {
        System.out.println("The Name of this Bread = " + name);
    }

    void Name(String name) {
        System.out.println("The Name of this Dog = " + name);

    }

    // # Feature of human class members
    public static void Details(int Class, String FatherName) {
        System.out.println("The Oner name of the Dog is = " + FatherName);

        System.out.println("The Dog is " + Class + " years OLD");
    }
}

class ClassExample1 {
    public static void main(String[] args)
     {
        Human Rik = new Human("mail", 2, 2, 2);
        Rik.Bread("Human");
        Rik.Name("Rik Sarkar");
        Human.SchoolDetails("HASNHS", 212, 12, "Ramendra");

        Dog Tom = new Dog("mail", 4, 4, 2);
        Tom.Bread("DOG");
        Tom.Name("TOMY");
        Dog.Details(3, "Rik Sarkar");
    }
}
