import java.net.*;
import java.io.*;
import java.util.*;
public class OnlineContentReadUsingURL {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            String url;
            System.out.print("Enter the URL = ");
            url = sc.nextLine();
            URL u1 = new URL(url);

            URLConnection u2 = u1.openConnection();
            InputStream i = u2.getInputStream();
            while(i.read() != -1)
            {
                System.out.print(i);
            }
            
            System.out.println("\n\n");

            sc.close();
        } 
        
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}

