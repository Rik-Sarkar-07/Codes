public class StringPollExample {
    public static void main(String[] args) {
        /*
        String name1 = "NUM";  means NUM is create in String constant pool , and other side String name2 = new String("NUM");
        means NUM create in Heep memory so both location are ont same ..

        ==  operator is use to determine the location of string objects are same of not (when Content is same),If it is same
        then return true and if it is not same then it is false.

        equals() method is used to determine the content is same or not(When location is same or not),If, Content is same then return
        true and if content is not same then return false.
         */
        String name1 = "Sudipta";
        String name2 = new String("Sudipta");
        String name3 = "Sudipta";
        String name4 = new String("Sudipta");
        System.out.println( (name1.equals(name2)));
        System.out.println(name1==name2);
        System.out.println(name1==name3);
        System.out.println(name2.equals(name4));
    }
}
