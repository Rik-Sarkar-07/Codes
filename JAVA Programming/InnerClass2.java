class OuterClass {
    public int pv = 10;
    private int prv = 20;
    int dv = 30;

    private void prmathode() {
        System.out.println("I am Private Mathode");
    }

    public void pmathode() {
        System.out.println("I am Public Mathode");
    }

    Inner in = new Inner();

    public void InnerPrivateMathode() {
        in.mathode();
    }

    OuterClass() {
        System.out.println("\n \t I am Constructor and i will run all privte parts of Outer class");
        prmathode();
        System.out.println("This is private variable = " + in.k);
    }

    class Inner {
        public int k = prv;

        private void mathode() {
            System.out.println("I am Inner Class Private Methode");
        }
    }
}

class InnerClass {
    public static void main(String[] args) {

        OuterClass oc = new OuterClass();

        oc.InnerPrivateMathode();

    }
}
