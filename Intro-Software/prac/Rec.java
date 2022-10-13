public class Rec {

    public static void main(String[] args) {
        printRow(10);

    } // main

    public static void printRow(int num) {
        if (num != 0) {
            printRow(num - 1) ;

        printCol(num - 1);

        System.out.println();
        }

    } // printRow

    public static void printCol (int num) {
        if (num == 0) {

            return;
        } // if

        printCol(num - 1);
        System.out.print("*");

    }

}
