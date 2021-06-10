import java.util.Calendar;

public class CalenderClaas {
    public static void main(String[] args) {
        Calendar c = Calendar.getInstance();
       int d =  c.get(Calendar.DATE);
       int m = c.get(Calendar.MONTH);
       int y = c.get(Calendar.YEAR);
       int h = c.get(Calendar.HOUR);
       int mi = c.get(Calendar.MINUTE);
       int s = c.get(Calendar.SECOND);


        System.out.println("The Current Date = "+d+" - "+m+" - "+y);
        System.out.println("The Current Time = "+h+" : "+mi+" : "+s);

        int flag = c.get(Calendar.AM_PM);

        if(flag == 0)
        {
            System.out.println("Good Morning !!");
        }
        else {
            System.out.println("Good Evening !!");
        }

    }
}
