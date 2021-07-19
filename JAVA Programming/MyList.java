import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MyList extends Frame implements ItemListener
{
    int msg[];
    List list;
    MyList()
    {
        setLayout(new FlowLayout());

        list = new List(4,true);
        list.add("Bengali");
        list.add("Hindi");
        list.add("English");
        list.add("Sanskrit");

        add(list);

        list.addItemListener(this);



        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
    @Override
    public void itemStateChanged(ItemEvent e) {
        repaint();

    }

    @Override
    public void paint(Graphics g) {

        g.drawString("------ Selected Language ----- ",100,200);
        msg = list.getSelectedIndexes();

        for(int i=0;i<msg.length;i++)
        {
            String item = list.getItem(msg[i]);
            g.drawString(item,100,220+i*20);
        }

    }

    public static void main(String[] args) {

        MyList m1 = new MyList();
        m1.setVisible(true);
        m1.setSize(500,500);
        m1.setName("My Lists");
    }
}
