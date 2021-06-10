public class UsingTernaryOp {
    public static void main(String[] args) {
        int a =10,b=20,c=30;
        int max = a>b?(c>a?c:a):(c>b?c:b);
        System.out.println("The Leargest Element is  = "+max);
    }
    
}
