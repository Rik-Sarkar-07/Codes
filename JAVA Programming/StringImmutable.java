public class StringImmutable {
    public static void main(String[] args) {

        String str1 = "Hello";
        String str2 = "World";
        String str3 = str1;

        if (str1.hashCode() == str3.hashCode())
        {
            System.out.println("STR1 = STR3");
        }else
        {
            System.out.println("STR1 != STR3");
        }


          str1 = str1 + str2;

        if (str1.hashCode() == str3.hashCode())
        {
            System.out.println("Mutable");
        }else
        {
            System.out.println("immutable");
        }

    }
}
