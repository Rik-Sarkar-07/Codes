import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingComponent extends JFrame implements ActionListener
{
    JCheckBox cb1,cb2;
    JRadioButton rb1,rb2;
    JTextArea ta;
    String msg="";
    ButtonGroup bg;
    SwingComponent()
    {
        Container container = getContentPane();
        container.setLayout(new FlowLayout());

        ta = new JTextArea(10,20);

        cb1 = new JCheckBox("Java",true);
        cb2 = new JCheckBox("C++");

        rb1 = new JRadioButton("Programming",true);
        rb2 = new JRadioButton("Coding");

        bg = new ButtonGroup();
        bg.add(rb1);
        bg.add(rb2);

        container.add(cb1);
        container.add(cb2);
        container.add(rb1);
        container.add(rb2);
        container.add(ta);

        cb1.addActionListener(this);
        cb2.addActionListener(this);
        rb1.addActionListener(this);
        rb2.addActionListener(this);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (cb1.getModel().isSelected()) {
            msg+="\nJava";
        }if (cb2.getModel().isSelected()) {
            msg+="\nC++";
        }if (rb1.getModel().isSelected()) {
            msg+="\nProgramming";
        }if (rb2.getModel().isSelected()) {
            msg+="\nCoding";
        }
        ta.setText(msg);
        msg = "";
    }

    public static void main(String[] args) {
        SwingComponent swingComponent = new SwingComponent();
        swingComponent.setTitle("My Swing Functionality");
        swingComponent.setVisible(true);
        swingComponent.setSize(500,500);
    }
}
