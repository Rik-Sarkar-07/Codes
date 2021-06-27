import java.io.*;
public class FileOutputStreamClass {
    public static void main(String[] args) throws IOException {
        FileOutputStream fout;
      //  fout = new FileOutputStream("..\\Myfile.txt"); // Not update , always new content
        fout = new FileOutputStream("..\\Myfile.txt",true); //  update , always new content
        String s = "I am Sudipta Sarkar and My nick name is Rik Sarkar";
        char ch[] = s.toCharArray();
        for(int i=0;i<s.length();i++)
        {
            fout.write(ch[i]);
        }
        fout.close();
    }
}
