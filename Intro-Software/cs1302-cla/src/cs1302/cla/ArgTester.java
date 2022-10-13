package cs1302.cla;

public class ArgTester {

    public static void main(String [] args) {
        System.out.println("arguments:");
        for(int i = 0; i < args.length; i++) {
            String arg = args[i];
            System.out.printf("arg%d = %s\n", i, arg);
        } // for
    } // main
}
