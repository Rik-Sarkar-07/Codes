package File_Handling;
import java.io.*;

public class CerateFile {
    public static void main(String[] args) {
        File myfFile = new File("Test.txt");
        try{
            myfFile.createNewFile();
            System.out.println("File Creating Complete");
        }
        catch(IOException e)
        {
            System.out.println("Unable to Create Files");
            e.printStackTrace();
        }

        //      Writing Some Informations
        try{
            FileWriter myFileWriter = new FileWriter("Test.txt");
            myFileWriter.write("Hello , I am Sudipta Sarkar from Computer Science Department in RKMVCC \n Have a Good day!!");
            myFileWriter.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }


    }

}
