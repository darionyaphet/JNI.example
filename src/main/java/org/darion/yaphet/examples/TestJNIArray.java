package org.darion.yaphet.examples;

public class TestJNIArray {
    static {
        System.loadLibrary("values");
    }

    private native String mkString(Object[] values);

    private String ms(Object[] values) {
        for (Object o : values) {
            System.out.println(o.getClass().getCanonicalName());
        }
        return "";
    }

    public static void main(String args[]) {
        Object[] values = {false, 7, 1024L, 3.14F, 0.618, "darion.yaphet"}; // boolean int long float double String
        //Object[] values = {
        //        new Integer(1)
        //};
//        for (Object o : values) {
//            System.out.println(o.getClass().getName());
//        }

//        Object[] values = { 1,2,3,4};


        TestJNIArray instance = new TestJNIArray();
        System.out.println("MkString : " + instance.mkString(values));

    }
}

