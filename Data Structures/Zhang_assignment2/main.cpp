#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"

using namespace std;

// used to display all user options
void printOptions() {
    cout << "Commands:" << endl;
    cout << "(i) - Insert value" << endl;
    cout << "(d) - Delete value" << endl;
    cout << "(s) - Search value" << endl;
    cout << "(n) - Print next iterator value" << endl;
    cout << "(r) - Reset iterator" << endl;
    cout << "(a) - Delete alternate nodes" << endl;
    cout << "(m) - Merge two lists" << endl;
    cout << "(t) - Intersection" << endl;
    cout << "(p) - Print list" << endl;
    cout << "(l) - Print length" << endl;
    cout << "(q) - Quit program" << endl;
    

} // print options

int main(int argc, char* argv[])
{
    // opens up the stream and opens up
    ifstream ifs(argv[1], ios::in);

    if(!ifs) {
        cerr << "Error: File has failed to open or does not exist." << endl;
        exit(1);
    } // if
    
    // variables to hold the linked list and create it
    SortedLinkedList slinkList;
    int value = 0;
    ItemType item;

    // variables to hold the user's inputs
    char userInput = ' ';
    int userValue = 0;

    // creates the list from a file
    while (ifs >> value)
    {
        item.initialize(value);
        slinkList.insertItem(item);
    } // while
    
    printOptions();
    // main loop for program
    while (userInput != 'q')
    {
        cout << "Enter a command: ";
        cin >> userInput;

        switch(userInput) {
            case 'i':
                {
                    // inserts a value by creating the item
                    // based on user input
                    slinkList.printItems();
                    cout << "Enter number: ";
                    cin >> userValue;
                    item.initialize(userValue);
                    slinkList.insertItem(item);
                    slinkList.printItems();
                }
                break;
            case 'd':
                {   
                    // deletes the value by creating an item
                    // and deleting from list
                    slinkList.printItems();
                    cout << "Enter value to delete: ";
                    cin >> userValue;
                    item.initialize(userValue);
                    slinkList.deleteItem(item);
                    slinkList.printItems();
                }
                break;
                case 's':
                {
                    // searches for the value the user wants
                    // returns the index that the node is at
                    cout << "Enter a value to search: ";
                    cin >> userValue;
                    item.initialize(userValue);
                    int ind = slinkList.searchItem(item);
                    if (ind == -1) {
                        cout << "Item not found." << endl;
                    } else {
                        cout << "Index " << ind << endl;
                    }
                }
                break;
            case 'n':
                {
                    int nextItem = slinkList.GetNextItem().getValue();
                    // iterates through the list and gets item
                    if(!(nextItem == -1)) { // checks if next item exists
                        cout << nextItem << endl;
                    } // if
                } 
                break;
            case 'r':
                {
                    slinkList.ResetList();
                    cout << "Iterator reset." << endl;
                
                }
                break;
            case 'a':
                {
                    // deletes every other node starting on the 2nd
                    cout << "List before alternate delete: ";
                    slinkList.printItems();
                    slinkList.delAltNodes();
                    cout << "List after alternate delete: ";
                    slinkList.printItems();
                }
                break;
            case 'm':
                {
                    // variables used to keep track of user input
                    string elem;
                    cout << "Length of list to merge: ";
                    
                    // gets all values from user input
                    getline(cin, elem);
                    getline(cin,elem);
                    cout << "List of elements separated by spaces in order: ";
                    getline(cin,elem);
                    
                    
                    cout << "List 1: ";
                    slinkList.printItems();
                    cout << "List 2: " << elem << endl;
                    // calls merge functionality and reprints
                    slinkList.merge(elem);
                    slinkList.printItems();
                } // merge
                break;
            case 't':
                {
                    string elem;    
                    cout << "Length of list to find the intersection: ";
                    
                    // gets all values from user input
                    getline(cin, elem);
                    getline(cin, elem);
                    cout << "List of elements separated by spaces in order: ";
                    getline(cin, elem);
                    
                    cout << "List 1: ";
                    slinkList.printItems();
                    cout << "List 2: " << elem << endl;
                    // finds common values
                    slinkList.findCommonVals(elem);
                    cout << "Intersection: ";
                    slinkList.printItems();
                }
                break;
            case 'p':
                slinkList.printItems();
                break;
            case 'l':
                {
                    cout << "List Length is "<< slinkList.length() << endl;
                }
                break;
            case 'q':
                cout << "Quitting program..." << endl;
                ifs.close();
                break;
            default:
                {
                    cout << "Invalid command, try again!" << endl;
                }

        }
    } // while
    
} // main