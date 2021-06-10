import java.lang.*;
public class WrapperClassExample {
    public static void main(String[] args) {

        // Wrapper Class = Wrapper class is a class it have contains and wrap primitive data types.

        // Boxing = Converting a Primitive data type to its corresponding object is called Boxing.

        Integer boxing1 = Integer.valueOf("123");
        Integer boxing2 = Integer.valueOf(125);
        Integer autoboxing = 128;

        // Unboxing = Converting an Object ot its corresponding datatype is called Unboxing.

        int unboxing = Integer.parseInt("245");
        int autounboxing = boxing1.intValue();

    }
}
