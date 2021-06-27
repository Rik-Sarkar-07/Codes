import java.io.*;

public class BufferedWriterClass {
    public static void main(String[] args) throws IOException {
/**
 * Note: Buffer means a temporary storage area between memory and stream it is
 * better than File Streams because it is transfer contents at once but Streams are transfer data line by line.
 */
        BufferedWriter bw = new BufferedWriter(new FileWriter("..\\Myfile2.txt",true));

        bw.write("I am Sudipta Sarkar");
        bw.close();
    }
}
