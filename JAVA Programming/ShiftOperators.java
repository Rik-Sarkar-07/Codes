import java.io.*;
public class ShiftOperators {
    public static void main(String[] args) {
        // Logical right shift = shift right as Full by 0 EX - 0..0011001 --> 0..0000110  (>>2)  Here MSB is Same
        int i = 10;         // 1010
        int k = i>>2;       // 0010

        System.out.println(k);  // 02

        // Unsigned right shift = shift right full by 0 EX - (111111.. 1011) --> (001111.. 1110)  (>>>2) Here MSB will change
        int m = -11;
        int l = m>>>2;
        System.out.println(l);

        // Left shift = shift left and full by 0 EX -  0..001111 0011 -->  0..111100 1100   (<<2)  Here MSB are same
        int x = 10;
        int y = x<<2;
        System.out.println(y);
        x = 12;
        y = x<<2;

        System.out.println(y);

        x = 15;
        y = x<<4;
        System.out.println(y);


    }

}
