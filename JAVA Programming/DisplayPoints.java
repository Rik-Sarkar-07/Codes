import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class DisplayPoints extends Frame
{
    DisplayPoints()
    {
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent ek) {

                System.exit(0);
            }
        });
    }

    @Override
    public void paint(Graphics g) {
        g.setColor(Color.white);
        for ( ; ; )
        {
            int x = (int) (Math.random() * 800);
            int y = (int) (Math.random() * 600);
            g.drawLine(x,y,x,y);

            try
            {
                Thread.sleep(20);
            }catch (InterruptedException e)
            {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) {

        DisplayPoints dp = new DisplayPoints();
        dp.setSize(500,400);
        dp.setBackground(Color.black);
        dp.setVisible(true);
        dp.setTitle("---- Random Dot ---");

    }
}
