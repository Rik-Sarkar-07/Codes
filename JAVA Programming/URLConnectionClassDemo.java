import java.net.*;
import java.io.*;
import java.util.*;
public class URLConnectionClassDemo {
    public static void main(String[] args) throws Exception {
        URL ob = new URL("https://github.com/Rik-Sarkar-07/Codes/blob/main/C%2B%2B%20Programming/Introductions.txt");
    URLConnection uc = ob.openConnection();
    InputStream str = uc.getInputStream();

    int i;
    while ( (i = str.read() ) != -1)
    {
        System.out.print((char)i);
    }

    }
}
