import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class FrameDemo
{
    public static void main(String[] args) {
        Frame frame = new Frame("My First Frame");
        frame.setSize(500,500);
        frame.setVisible(true);
        frame.setLayout(null);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
