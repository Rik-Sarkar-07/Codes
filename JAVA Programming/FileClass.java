import java.io.*;
public class FileClass {
    public static void main(String[] args) throws IOException{
        File f = new File("..\\Myfile.txt");
        System.out.println("Is File is Exits = "+f.exists());
        f.createNewFile(); // Exception can throw   // create a file
        System.out.println("Is File is Exits = "+f.exists());
        System.out.println("The name of the file = "+f.getName());
        System.out.println("The length of this file = "+f.length());
        /**
         * @Note: Here File class is like a meta data of the existing file so, it is not modify the file
         */
        f.delete();  // delete the file

    }
}
