public class StringBufferMutable {
    public static void main(String[] args) {
        StringBuffer stb1 = new StringBuffer("Hello");
        StringBuffer stb2 = new StringBuffer("World");
        StringBuffer stb3 = stb1.append(stb2);
        if(stb1.hashCode() == stb3.hashCode())
        {
            System.out.println("StringBuffer is Mutable");
        }
        else
        {
            System.out.println("Immutable");
        }

    }
}
