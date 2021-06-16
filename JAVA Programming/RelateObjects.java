
class Line
{
    double get(double x)
    {
        return x;
    }
}

class Area
{
    Line obj3;

    Area(Line obj3)
    {
        this.obj3 = obj3;
    }
    double square(double x)
    {
        double result = obj3.get(x)*x;
        return result;
    }

}

class Volume
{
    Area obj2;
    Volume(Area obj2)
    {
        this.obj2 = obj2;
    }
    double cube(double x)
    {
        double result = obj2.square(x)*x;
        return result;
    }
}

public class RelateObjects {
    public static void main(String[] args) {
        
        Line o1 = new Line();
        Area o2 = new Area(o1);
        Volume o3 = new Volume(o2);

        System.out.println("The Square of 5 = "+o2.square(5));
        System.out.println("The cube of 6 = "+o3.cube(6));

    }
    
}
