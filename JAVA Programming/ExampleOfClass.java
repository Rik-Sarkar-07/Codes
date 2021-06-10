package File_Handling;
import java.util.Scanner;

class Box
{
    Box(String color)
    {
        System.out.println("The Color of this box is  = "+color);
    }

    private double l;
    private double h;
    private double w;

    public double Length(double length)
    {
        this.l = length;
        return l;
    }

    public double Area(double length,double hight)
    {
        this.l = length;
        this.h = hight;
        return (l*h);
    }

    public double Volium(double length,double hight,double width)
    {
        this.l = length;
        this.h = hight;
        this.w = width;
        return (l*h*w);
    }


}
public class ExampleOfClass {

    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
    System.out.println("Enter Length , Higth & Width of this Box -");
    double a = sc.nextDouble();
    double b = sc.nextDouble();
    double c = sc.nextDouble();

    Box bx =new Box("Black");
   System.out.println("The Length odf this Box = "+bx.Length(a));
   System.out.println("The Area of this Box = "+ bx.Area(a,b));
   System.out.println("The Volium of this Box = "+ bx.Volium(a,b,c));
   sc.close();
    }
     
    
}
