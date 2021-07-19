import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MyAwtProgramming extends Frame implements ActionListener
{
    Button b1,b2,b3,b4,b5;
    MyAwtProgramming()
    {
        this.setLayout(null);

        b1 = new Button("Yellow");
        b2 = new Button("Red");
        b3 = new Button("Blue");
        b4 = new Button("Pink");
        b5 = new Button("Close");

        b1.setBounds(100,100,70,40);
        b2.setBounds(100,160,70,40);
        b3.setBounds(100,220,70,40);
        b4.setBounds(100,280,70,40);
        b5.setBounds(300,350,70,40);

        this.add(b1);
        this.add(b2);
        this.add(b3);
        this.add(b4);
        this.add(b5);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
    @Override
    public void actionPerformed(ActionEvent e) {
    String str = e.getActionCommand();
    if(str.equals("Yellow"))
    {
        this.setBackground(Color.YELLOW);
        b1.setBackground(Color.YELLOW);
    }
    if(str.equals("Red"))
    {
        this.setBackground(Color.red);
        b2.setBackground(Color.red);
    }
    if(str.equals("Blue"))
    {
        this.setBackground(Color.blue);
        b3.setBackground(Color.blue);
    }
    if(str.equals("Pink"))
    {
        this.setBackground(Color.pink);
        b4.setBackground(Color.pink);
    }
        if(str.equals("Close"))
        {
           this.addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosed(WindowEvent e) {
                    System.exit(0);
                }
            });

        }
    }

    @Override
    public void paint(Graphics g) {

        Font font = new Font("MyFont",Font.BOLD+Font.ITALIC,30);
        g.setFont(font);
        g.drawString("Choice Any Button",200,500);
    }

    public static void main(String[] args) {
        MyAwtProgramming myAwtProgramming = new MyAwtProgramming();
        myAwtProgramming.setSize(800,800);
        myAwtProgramming.setVisible(true);
        myAwtProgramming.setTitle("Press Button and Change Background ");

    }
}
