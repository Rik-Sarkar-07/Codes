package com.sudipta;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ThrowsAndThrow {
    public static void main(String[] args) {
        System.out.println("In Side Main Method");

        Integer i = Integer.parseInt("12354",10);

 ///        try {
//            System.out.println("Enter the two Numbers");
//            int a,b,c;
//            Scanner sc = new Scanner(System.in);
//            a = sc.nextInt();
//            b = sc.nextInt();
//            c = a / b;
//            System.out.println("Divide Result is = "+c);
//        }
//
//
//        catch (InputMismatchException e)
///        {
//            System.out.println(e.getMessage()+" Enter correct input");
//        }

        try{
            fun1();
            Thread.sleep(5000);
            System.out.println("Sorry To take some time");
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage()+" Exception");


        }

    }

    public static void fun1()
    {
        fun2();
    }

    public static void fun2() throws InputMismatchException
    {
        int a,b,c;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Two Numbers ");
        a = sc.nextInt();
        b = sc.nextInt();
        c = a/b;
        System.out.println("The Divide Result is = "+c);
        boolean isDenger = true;
        if(isDenger)
        {
            throw new InputMismatchException("Danger is Coming");
        }
    }

}
