import java.net.URL;

public class URLClassDemo {
    public static void main(String[] args)throws  Exception
    {
        URL obj = new URL("https://google.com/index.html");

        System.out.println("Protocol = "+obj.getProtocol());
        System.out.println("Host = "+obj.getHost());
        System.out.println("File = "+obj.getFile());
        System.out.println("Port = "+obj.getPort());
        System.out.println("Path = "+obj.getPath());
        System.out.println("External Form = "+obj.toExternalForm());
    }
}
