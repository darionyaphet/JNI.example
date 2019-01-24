public class HelloJNI {
    static {
        System.loadLibrary("hello");
    }

    // Declare a native method sayHello() that receives nothing and returns void
    private native void sayHello();

    public static void main(String[] args) {
        new HelloJNI().sayHello();
    }
}
