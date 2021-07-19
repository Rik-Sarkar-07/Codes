import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class RadioButton extends Frame implements ItemListener
{
    String msg =" ";
    CheckboxGroup cbg;
    Checkbox y,n;

    RadioButton()
    {
        setLayout(new FlowLayout());
        cbg = new CheckboxGroup();
        y = new Checkbox("YES",cbg,true);
        n = new Checkbox("NO",cbg,false);

        add(y);
        add(n);

        y.addItemListener(this);
        n.addItemListener(this);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        repaint();          // It is also help to call paint
    }

    @Override
    public void paint(Graphics g) {
      msg = " Current State = ";
      msg = msg + cbg.getSelectedCheckbox().getLabel();
      g.drawString(msg,10,100);
    }

    public static void main(String[] args) {
        RadioButton radioButton = new RadioButton();
        radioButton.setVisible(true);
        radioButton.setSize(400,500);
        radioButton.setTitle("Radio Button");
    }
}
