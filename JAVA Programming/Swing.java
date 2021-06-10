import javax.swing.JOptionPane;
import java.util.Scanner;

public class Swing {
    public static void main(String[] args) {

        System.out.println("Enter the Runs In Every Match");
       Scanner sc = new Scanner(System.in);
        int i;
        String input,num;
        float avg = 0;
      num = JOptionPane.showInputDialog("How Many Match played by MS Dhoni in IPL-2020  ");
      int index = Integer.parseInt(num);
        int runs[] = new int[index];
        for (i=0;i<index;i++)
        {
//            runs[i] = sc.nextInt();
            input = JOptionPane.showInputDialog("Enter Run in "+(1+i)+" Match = ");
            runs[i] = Integer.parseInt(input);
            avg = avg + runs[i];
        }
    float Average = avg / index;

        JOptionPane.showInputDialog(null,"The Average Run of MS Dhoni = "+Average);
    if(Average>70)
    {
        JOptionPane.showInputDialog(null," Great Average ");
    }
else if(Average>40 && Average<70)
        {
            JOptionPane.showInputDialog(null," Good Average ");
        }
else if(Average>25 && Average<40)
    {
        JOptionPane.showInputDialog(null," Average is Not Bad ");
    }

else
    {
        JOptionPane.showInputDialog(null," Very bad Average ");
    }

        System.exit(0);
    }
}
