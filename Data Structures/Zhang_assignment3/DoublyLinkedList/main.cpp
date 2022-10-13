#include "DoublyLinkedList.h"
#include <string>
#include <stdio.h>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    
    char listType;
    ifstream ifs(argv[1], ios::in);

    if (!ifs) {
        cerr << "Error: File has failed to open or does not exist." << endl;
        exit(1);
    }
    // gets which list type to pull from
    cout << "Enter list type (i - int, f - float, s - std::string): ";
    cin >> listType;

    switch (listType) {
        case 'i': { // case for input linked list
            DoublyLinkedList<int> list;
            char userInput = 'a';
            // string userI;
            int listItems;
            
            while(ifs >> listItems) {
                list.insertItem(listItems);
            } // while

            cout << "insert (i), delete (d), length (l), print (p), deleteSub (b),"
                 << " mode (m), printReverse (r), swapAtl (s), quit (q)" << endl;
            
            while (userInput != 'q') { // while user does not quit
                cout << "Enter a command: ";
                cin >> userInput;

                switch (userInput) {
                    case 'i': {
                        int value;
                        cout << "Item to insert: ";
                        cin >> value;
                        list.insertItem(value); // insert item based on value
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'd': {
                        int value;
                        cout << "Item to delete: ";
                        cin >> value;
                        list.deleteItem(value); // delete item based on user value
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'l': {
                        cout << "The length is: " << list.lengthIs() << endl;
                        cout << endl;
                        break;
                    }
                    case 'p': {
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'b': {
                        int input;
                        int input2;
                        cout << "Enter lower bound: ";
                        cin >> input;
                        cout << "Enter upper bound: ";
                        cin >> input2;
                        cout << "Original List: ";
                        list.print();
                        list.deleteSubsection(input,input2);
                        cout << "Modified List: "; 
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'm': {
                        list.print();
                        cout << "Mode: " << list.mode() << endl;
                        cout << endl;
                        break;
                    }
                    case 'r': {
                        list.printReverse();
                        break;
                    }
                    case 's': {
                        cout << "Original List: ";
                        list.print();
                        list.swapAlternate();
                        cout << "Swapped List: ";
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'q': {
                        cout << "Quitting program..." << endl;
                        break;
                    } // quit
                    default:
                        cout << "Invalid command, try again!" << endl;
                        cout << endl;
                        break;
                    }
            } // while

            break;
        }
        case 'f': { 

            DoublyLinkedList<float> list;
            float listItems;
            char userInput = 'a';
            string userI;

            while(ifs >> listItems) {
                list.insertItem(listItems);
            } // while
            
            cout << "insert (i), delete (d), length (l), print (p), deleteSub (b),"
         << " mode (m), printReverse (r), swapAtl (s), quit (q)" << endl;

            while (userInput != 'q') {
                cout << "Enter a command: ";
                cin >> userInput;

                switch (userInput) {
                    case 'i': {
                        float value;
                        cout << "Item to insert: ";
                        cin >> value;
                        list.insertItem(value); // insert item based on value
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'd': {
                        float value;
                        cout << "Item to delete: ";
                        cin >> value;
                        list.deleteItem(value); // delete item based on user value
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'l': {
                        cout << "The length is: " << list.lengthIs() << endl;
                        cout << endl;
                        break;
                    }
                    case 'p': {
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'b': {
                        float input;
                        float input2;
                        cout << "Enter lower bound: ";
                        cin >> input;
                        cout << "Enter upper bound: ";
                        cin >> input2;
                        cout << "Original List: ";
                        list.print();
                        list.deleteSubsection(input,input2);
                        cout << "Modified List: "; 
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'm': {
                        list.print();
                        cout << "Mode: " << list.mode() << endl;
                        cout << endl;
                        break;
                    }
                    case 'r': {
                        list.printReverse();
                        break;
                    }
                    case 's': {
                        cout << "Original List: ";
                        list.print();
                        list.swapAlternate();
                        cout << "Swapped List: ";
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'q': {
                        cout << "Quitting program..." << endl;
                        break;
                    } // quit
                    default:
                        cout << "Invalid command, try again!" << endl;
                        cout << endl;
                        break;
                    }
            } // while

            break;
        }
        case 's': {
            DoublyLinkedList<string> list;
            string listItems;
            char userInput = 'a';

            while(ifs >> listItems) {
                list.insertItem(listItems);
            } // while

            cout << "insert (i), delete (d), length (l), print (p), deleteSub (b),"
                 << " mode (m), printReverse (r), swapAtl (s), quit (q)" << endl;

            while (userInput != 'q') {
                cout << "Enter a command: ";
                cin >> userInput;
                
                switch (userInput) {
                    case 'i': {
                        string value;
                        cout << "Item to insert: ";
                        cin >> value;
                        list.insertItem(value); // insert item based on value
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'd': {
                        string value;
                        cout << "Item to delete: ";
                        cin >> value;
                        list.deleteItem(value); // delete item based on user value
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'l': {
                        cout << "The length is: " << list.lengthIs() << endl;
                        cout << endl;
                        break;
                    }
                    case 'p': {
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'b': {
                        string input;
                        string input2;
                        cout << "Enter lower bound: ";
                        cin >> input;
                        cout << "Enter upper bound: ";
                        cin >> input2;
                        cout << "Original List: ";
                        list.print();
                        list.deleteSubsection(input,input2);
                        cout << "Modified List: "; 
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'm': {
                        list.print();
                        cout << "Mode: " << list.mode() << endl;
                        cout << endl;
                        break;
                    }
                    case 'r': {
                        list.printReverse();
                        break;
                    }
                    case 's': {
                        cout << "Original List: ";
                        list.print();
                        list.swapAlternate();
                        cout << "Swapped List: ";
                        list.print();
                        cout << endl;
                        break;
                    }
                    case 'q': {
                        cout << "Quitting program..." << endl;
                        break;
                    } // quit
                    default:
                        cout << "Invalid command, try again!" << endl;
                        cout << endl;
                        break;
                    }
            } // while
            break;
        }
        default: {
            cerr << "Error: Invalid list type provided." << endl;
            exit(1);
        }
    } // switch


    // options
    
} // main
