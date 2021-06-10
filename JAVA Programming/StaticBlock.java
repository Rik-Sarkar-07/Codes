class StaticBlock {
    static
    {
        System.out.println("Before Main");
    }
    public static void main(String[] args) {
        
        System.out.println("Inside main");
    }
    
}
