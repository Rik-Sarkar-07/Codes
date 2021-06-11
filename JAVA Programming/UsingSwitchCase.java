import java.util.Scanner;
import java.io.*;

    class ManuDrive{

        public static void Summation(int a,int b){

            int c = a+b;
            System.out.println("Summation is = "+c);
        }

        public static void Subtraction(int a,int b){

            int c = a-b;
            System.out.println("Subtraction is = "+c);
        }

        public static void Multiplication(int a,int b){

            int c = a*b;
            System.out.println("Multiplication is = "+c);
        }

        public static void Divition(float a,float b){

            float c = a/b;
            System.out.println("Divition is = "+c);
        }

        public static void Modulas(int a,int b){

            int c = a%b;
            System.out.println("Modulas is = "+c);
        }

        public static void Factorial(int n){

            long fact = 1;
            int i = 0;
            for(i=1;i<=n;i++)
            {
                fact = fact * i;
            }

            System.out.println("Factorial of this Number is "+fact);
        }


    }

public class UsingSwitchCase {

        public static void main(String args[]) {

            for( ; ; ) {
                Scanner str = new Scanner(System.in);

                System.out.print("Calculator On / Off = ");
                String s = str.nextLine();

                if(s.equals("on")||s.equals("On") ||s.equals("ON") ||s.equals("oN")){




                    System.out.println("Enter your operation or Oparand\n");
                    Scanner sc = new Scanner(System.in);
                    char ch;
                    int a,b;
                    float c,d;
                    System.out.print("Enter your Oparator Choice = ");
                    ch = sc.nextLine().charAt(0);
                    switch(ch){
                        case '+':
                            System.out.println("Enter Oparands");
                            a = sc.nextInt();
                            b = sc.nextInt();
                            ManuDrive.Summation(a,b);
                            break;
                        case '-':
                            System.out.println("Enter Oparands");
                            a = sc.nextInt();
                            b = sc.nextInt();
                            ManuDrive.Subtraction(a, b);
                            break;
                        case '*':
                            System.out.println("Enter Oparands ");
                            a = sc.nextInt();
                            b = sc.nextInt();
                            ManuDrive.Multiplication(a, b);
                            break;
                        case '/':
                            System.out.println("Enter Oparands ");
                            c = sc.nextFloat();
                            d = sc.nextFloat();
                            ManuDrive.Divition(c, d);
                            break;

                        case '!':
                            System.out.println("Enter Single Oparand");
                            a = sc.nextInt();
                            ManuDrive.Factorial(a);
                            break;


                        default:
                            System.out.println("Not Match ... Something Wrong plese cheak again\n");
                            break;
                    }




                }

                else
                {
                    System.out.println("Good Bye");
                    System.out.println("EXIT");
                    System.exit(0);
                    break;
                }

            } // For loop


        }
    }




