import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class IntroductionToAwt extends Frame {
   public IntroductionToAwt()
    {
        Frame frame = new Frame("Welcome to AWT");
//        setSize(400,300);
                            // those are allow if extends Frame class is written
//        setVisible(true);
        //  add(button);
        Button button = new Button("Click me");
        button.setBackground(Color.green);
        button.setForeground(Color.black);
        button.setBounds(180,180,80,40);

        Label label = new Label("Hello My brothers");
        label.setBounds(80,90,150,30);
        label.setBackground(Color.red);
        label.setForeground(Color.yellow);
      //  TextField textField = new TextField("Enter some Text");

        button.addActionListener(new ActionListener() {         // clicked Actions
            @Override
            public void actionPerformed(ActionEvent e) {
                label.setText("Clicked Completed");
            }
        });

        /*
         *  @ Add_Checkbox
         */

        Checkbox checkbox = new Checkbox("Java");
        Checkbox checkbox1 = new Checkbox("Python");
        checkbox.setBounds(300,200,40,40);
        checkbox1.setBounds(300,250,40,40);

        TextArea textArea =new TextArea(" ");
        textArea.setBounds(250,40,100,100);

        TextField textField = new TextField();
        textField.setBounds(120,150,200,30);

        frame.setSize(400,400);
        frame.setLayout(null);
        frame.setVisible(true);
        
        frame.add(button);
        frame.add(label);
        frame.add(textField);
        frame.add(textArea);
        frame.add(checkbox);
        frame.add(checkbox1);

        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowOpened(WindowEvent e) {
                System.out.println("Now Windows is open");
            }

            @Override
            public void windowActivated(WindowEvent e) {
                System.out.println("Windows is Activated");
            }

            @Override
            public void windowClosing(WindowEvent e) {
            frame.dispose();    // for closing pop-pop
                System.out.println("Windows is now Closed");
            }
        });
    }
    public static void main(String[] args) {

    //  new IntroductionToAwt(); // no space in memory
        IntroductionToAwt obj = new IntroductionToAwt(); // take some space in memory

    }

}
