class Test1
{
    int x,y;
   int z;
   Test1(int a, int b) 
   {
       this.x = a;      this.y = b;
       System.out.println("a = "+x);
       System.out.println("b = "+y);
       z = x + y;
   }

   protected void finalize()
   {
       System.out.println("Bye Bye !!");   
   }
}
class FinalizeM {

    public static void main(String[] args) {
        
        Test1 t = new Test1(12, 38);
      System.out.println(t.z);

         t = null;
        
    System.gc();
        

    }
    
}
