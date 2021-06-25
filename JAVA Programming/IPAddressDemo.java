import java.net.InetAddress;
import java.net.UnknownHostException;

public class IPAddressDemo {
    public static void main(String[] args) {
        try
        {
            InetAddress ip = InetAddress.getByName("www.google.com");
            System.out.println("The Host name is = "+ip.getHostName());
            System.out.println("The IP = "+ip.getHostAddress());
        }
        catch (UnknownHostException e)
        {
            System.out.println("Website is not found");
        }
    }
}
