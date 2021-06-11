import java.util.*;
import java.net.*;
public class IpAddressUsingInetAddress {
    public static void main(String[] args) {
            try {
                Scanner sc = new Scanner(System.in);
                System.out.print("Enter The Host URL = ");
                String url = sc.nextLine();
                InetAddress ip = InetAddress.getByName(url);
                System.out.println("Host Name = "+ip.getHostName());
                System.out.println("Address of  Host = "+ip.getHostAddress());

                sc.close();      
              }
                 catch (Exception e) {
          System.out.println(e.getMessage());
        }
    }
    
}

