package File_Handling;

import java.io.*;
import java.util.*;

public class ReadFile {
    public static void main(String[] args) {
        File myFile = new File("Test.txt");

        try {
            Scanner sc = new Scanner(myFile);
            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                System.out.println(line);
            }
            sc.close();
        } catch (FileNotFoundException e) {

            e.printStackTrace();
        }

    }
}
