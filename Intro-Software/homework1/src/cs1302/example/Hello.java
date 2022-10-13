package cs1302.example;
import cs1302.utility.MyMethods;

public class Hello{
    public static void main(String[] args) {
	//Code block used to ask and display user's name
	java.util.Scanner keyboard = new java.util.Scanner(System.in);
	System.out.println("Enter your full name: ");
	String userName = keyboard.nextLine();
	System.out.println("Hello, " + userName);

	//Code block used to ask for two numbers and display the largest number
	//If two numbers are the same, it will display that number
	System.out.println("Enter a number: ");
	int numberOne = keyboard.nextInt();
	System.out.println("Enter a second number: ");
	int numberTwo = keyboard.nextInt();
	System.out.println("The max of the two numbers is: " + MyMethods.max(numberOne, numberTwo));

    }
}    
