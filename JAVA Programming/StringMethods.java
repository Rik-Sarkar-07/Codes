public class StringMethods {
    public static void main(String[] args) {

        String str1 = "I am a Linux User";      // Create String Object Using String Literals
        String str2 = "am i linux user ?";
        String str3 = "I AM DON NO - 1";
        String str4 = new String("Hello");          // Create String Object Using Dynamic Allocation by new Operator
        String str5 = new String("World");
        String str6 = "Hello";

        System.out.println("str4.concat(str5) Method => "+str4.concat(str5));
        System.out.println("str3.substring(int i,int j) Method => "+ str3.substring(5,8));
        System.out.println("str3.replace('x','y') Method => "+str3.replace('D','T'));
        System.out.println("toUpperCase() Method => "+ str2.toUpperCase());
        System.out.println("toLowerCase() Method => "+str3.toLowerCase());
        System.out.println("length() of Str1 => "+str1.length());
        System.out.println("charAt(int i) Method => "+str6.charAt(1));
        System.out.println("str4.compareTo(str5) Method => "+str4.compareTo(str5));
        System.out.println("str6.equals(str4) Method => "+str6.equals(str4));
        System.out.println("str4==str6 Method => "+ (str4==str6));

    }
}
