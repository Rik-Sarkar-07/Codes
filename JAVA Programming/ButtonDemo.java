/*  Push Button */


import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class ButtonDemo extends Frame implements ActionListener
{
    ButtonDemo()
    {
        this.setLayout(null);
        Button button1 = new Button("Yellow");
        button1.setBounds(100,100,70,50);
        Button button2 = new Button("Blue");
        button2.setBounds(100,200,70,50);
        Button button3 = new Button("Red");
        button3.setBounds(100,300,70,50);
        Button button4 = new Button("White");
        button4.setBounds(100,400,70,50);


        this.add(button1);
        this.add(button2);
        this.add(button3);
        this.add(button4);

        button1.addActionListener(this);
        button2.addActionListener(this);
        button3.addActionListener(this);
        button4.addActionListener(this);

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent et) {
                System.exit(0);
            }
        });

    }

    @Override
    public void actionPerformed(ActionEvent ek){
        String str = ek.getActionCommand();
        if(str.equals("Yellow")){
            this.setBackground(Color.yellow);
        }
        if(str.equals("Blue")){
            this.setBackground(Color.blue);
        }
        if(str.equals("Red")){
            this.setBackground(Color.red);
        }
        if(str.equals("White")){
            this.setBackground(Color.white);
        }
    }
    public static void main(String[] args) {

        ButtonDemo frame = new ButtonDemo();
        frame.setTitle("Push Button and Change Background Color");
        frame.setSize(500,500);
        frame.setVisible(true);

    }


}
