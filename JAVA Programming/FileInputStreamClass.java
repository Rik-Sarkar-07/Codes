mport java.io.*;
public class FileInputStreamClass {
    public static void main(String[] args) throws IOException {
        int i;
        FileInputStream fin = new FileInputStream ("..\\Myfile.txt");
        do{
            i=fin.read();
            if(i != -1)
            {
                System.out.print((char)i);
            }
        }while (i != -1);

        fin.close();
    }
}
