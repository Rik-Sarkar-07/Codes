import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class CheckBoxDemo extends Frame implements ItemListener {
    Checkbox c1,c2,c3;
    String msg = " ";
    CheckBoxDemo()
    {
        setLayout(new FlowLayout());

        c1 = new Checkbox("Bold",true);
        c2 = new Checkbox("Italic");
        c3 = new Checkbox("Underline");

        add(c1);
        add(c2);
        add(c3);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        c1.addItemListener(this);
        c2.addItemListener(this);
        c3.addItemListener(this);


        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public void itemStateChanged(ItemEvent ie)
    {
        repaint();
    }

    @Override
    public void paint(Graphics g) {
        g.drawString("Current State : ",10,100);
        msg = "Bold: "+c1.getState();
        g.drawString(msg,10,120);
        msg = "Italic: "+c2.getState();
        g.drawString(msg,10,140);
        msg = "Underline: "+c3.getState();
        g.drawString(msg,10,160);
    }

    public static void main(String[] args) {

        CheckBoxDemo cbd = new CheckBoxDemo();
        cbd.setTitle("Check Boxes");
        cbd.setSize(400,400);
        cbd.setVisible(true);

    }
}
