public class Varablelengtharg {
    public static void Varargs(String... str)       // N numbers of strings args contains
     {
       System.out.println("\n The number of arguments = " + str.length);
       System.out.println("The arguments are: ");
       for (String s : str)
          System.out.println(s);
    }
    public static void main(String args[]) {
       Varargs("Hp", "Dell", "Mac");
       Varargs();
       Varargs("Realmi","Redmi MI","Xaomi","Sony");
    }
 }
