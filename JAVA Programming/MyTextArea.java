import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class MyTextArea extends Frame implements ActionListener
{
    TextField name , pass;
    MyTextArea()
    {
        setLayout(new FlowLayout());

        Label n = new Label("Name = ",Label.LEFT);
        Label p = new Label("Password = ",Label.LEFT);

        name = new TextField(20);
        pass = new TextField(20);
        pass.setEchoChar('*');  // Hide Password

        name.setBackground(Color.black);
        name.setForeground(Color.green);

        pass.setBackground(Color.black);
        pass.setForeground(Color.green);




    Font font = new Font("My Bank Account ",Font.PLAIN,25);

    add(n);
    add(name);
    add(p);
    add(pass);

    name.addActionListener(this);
    pass.addActionListener(this);

    addWindowListener(new WindowAdapter() {
        @Override
        public void windowClosing(WindowEvent e) {
            System.exit(0);
        }
    });

    }
    @Override
    public void actionPerformed(ActionEvent e) {

        Graphics g = this.getGraphics();
        g.drawString("Name = "+name.getText(),10,200);
        g.drawString("Password = "+pass.getText(),10,240);


    }

}
public class TextArea {

    public static void main(String[] args) {
        MyTextArea myTextArea = new MyTextArea();
        myTextArea.setSize(400,400);
        myTextArea.setVisible(true);
        myTextArea.setTitle("My Text Field");
    }
}
