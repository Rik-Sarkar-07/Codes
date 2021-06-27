import java.io.*;

public class BufferedReaderClass {
    public static void main(String[] args) throws IOException {
        int i;
        BufferedReader br = new BufferedReader(new FileReader("..\\Myfile2.txt"));
        while((i = br.read()) != -1)    // type costing char -> int
        {
            System.out.print((char)i);  // type costing int -> char
        }
        br.close();
    }
}
