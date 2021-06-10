import java.text.DateFormat;
import java.util.Date;
import java.util.Locale;

public class DATEClass {
    public static void main(String[] args) {
        Date d = new Date();
        DateFormat ftm = DateFormat.getDateInstance(DateFormat.FULL,Locale.UK);             // .MEDIUM & .LONG & .SHORT
        String str = ftm.format(d);

        System.out.println(str);
    }
}
