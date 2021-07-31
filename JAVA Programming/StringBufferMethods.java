import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class StringBufferMethods {
    public static void main(String[] args) {
        StringBuffer strb1 = new StringBuffer();
        System.out.println("Capacity => "+strb1.capacity()+" (Default capacity) \t Length => "+strb1.length()+"\t Content => "+strb1);
        StringBuffer strb2 = new StringBuffer(50);
        strb2.append("I am Java");
        System.out.println("Capacity => "+strb2.capacity()+"\t Length => "+strb2.length()+"\t Content => "+strb2);
        strb2.insert(9," JDK Version 16.2 ");
        System.out.println("After use Insert Method "+strb2);
        System.out.println("Position of java in strb2 => "+ strb2.indexOf("Java"));

        StringBuffer strb3 = new StringBuffer("New Computer");
        System.out.println("Sub string => "+strb3.substring(0,3));
        StringBuffer strb4 = new StringBuffer("High Cost");
        System.out.println("Replace High to Low => "+strb4.replace(0,4,"Low"));
        String str = null;
        try{
            System.out.print("Enter a String = ");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            str = br.readLine();
        }catch(IOException e)
        {
            System.out.println(e.getMessage());
        }

        System.out.println("The Str String Contains  => "+str);

    }
}
