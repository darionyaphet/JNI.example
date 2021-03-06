package org.darion.yaphet.examples;

public class TestJNIString {
    static {
        System.loadLibrary("string");
    }

    // Native method that receives a Java String and return a Java String
    private native String sayHello(String msg);

    public static void main(String args[]) {
        Object o = new Object();
        String result = new TestJNIString().sayHello("Hello from Java");
        System.out.println("In Java, the returned string is: " + result);
    }
}
