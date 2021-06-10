package File_Handling;
import java.io.*;
public class DeleteFile {
    public static void main(String[] args) {
        File myFile = new File("Test.txt");
        if(myFile.delete()) {   System.out.println("File has been deleted ");   }
        else    {   System.out.println("File has been not deleted");    }
    }
}
