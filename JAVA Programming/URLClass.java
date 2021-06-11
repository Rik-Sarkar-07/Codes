import java.net.*;
import java.util.*;
class URLClass{
    public static void main(String[] args) {
        try {
        	Scanner sc = new Scanner(System.in);
        		 System.out.print("Enter URL = ");
        	String url = sc.nextLine();
            URL u1 = new URL(url);
            System.out.println("The Protocol is = "+u1.getProtocol());
            System.out.println("The Host is = "+u1.getHost());
            System.out.println("The Prot is = "+u1.getPort());
            System.out.println("The Filename is = "+u1.getFile());
            sc.close();
        } catch (MalformedURLException e) {
            
            e.printStackTrace();
        }
    }
}

