import javax.swing.*;
import java.awt.*;
class MyPanel extends JPanel
{
MyPanel()
{
    this.setBackground(Color.BLACK);  // before
}
    @Override
    public void paint(Graphics g) {
      super.paintComponent(g);
        g.setColor(Color.GREEN);
       g.setFont(new Font("Helvetica",Font.BOLD,34));
        g.drawString("I am Hacker No 1",150,150);
    }
}
public class CreateFrame extends  JFrame{
    public static void main(String[] args) {

        // Create A Simple Frame
        CreateFrame createFrame = new CreateFrame();
        createFrame.setTitle("My Java Swing Frame");

        createFrame.setVisible(true);
        createFrame.setSize(700,400);
        // Close the Simple Frame
       createFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Background of the Simple Frame
        Container container = createFrame.getContentPane();
        container.setBackground(Color.BLACK);
        // Draw A string
        MyPanel myPanel = new MyPanel();
        container.add(myPanel);

    }
}
