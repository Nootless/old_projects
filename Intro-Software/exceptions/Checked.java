package exceptions;

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Checked {
    public static void main (String[] args) {
        File notesFile = new File("notes.txt");
        Scanner input = null;
        try {
            input = new Scanner(notesFile);
        } catch(FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        System.out.println(input.nextLine());
    } // main
} // Checked
