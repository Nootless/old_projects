package cs1302.exceptions;

public class PhoneNumberParser{
    public static void main(String[] args) {
        String phoneNumber = args[0];
        int areaCode = 0, prefix = 0, lineNumber = 0;
        try {
            areaCode = Integer.parseInt(phoneNumber.substring(0,3));
            prefix = Integer.parseInt(phoneNumber.substring(4,7));
            lineNumber = Integer.parseInt(phoneNumber.substring(8,12));
        } catch (StringIndexOutOfBoundsException exception) {
            System.out.println("Not long enough");
        } catch (NumberFormatException exception) {
            System.out.println("Not a number");
        } finally {
            System.out.println("Area code: " + areaCode);
            System.out.println("Prefix: " + prefix);
            System.out.println("Line Number: " + lineNumber);
        }
    }
}
