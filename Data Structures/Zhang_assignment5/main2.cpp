#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "SortingAlgo.h"

using namespace std;

void printCommands() { // prints commands
    cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp (q) quick-sort-rp (r)" << endl;
} // printCommands

void printSize() {
    cout << "Please input the size of the input desired: ";
} // printSize

int main () 
{
    

    // setting up the vector of values
    SortingAlgo item;

    // used to create the array
    int size;
    printSize();
    cin >> size;
    srand(time(0)); // creates randomly generated values
    for (int i = 0; i < size; i++) {
        item.values.push_back(rand() % size);
    } // for

    printCommands();
    long comps;
    char input;
    cout << "Enter the algorithm: ";
    cin >> input;
    cout << endl;
    switch(input) {
        case 's': {
            comps = item.SelectionSort(item.values, item.values.size());
            item.printVals();
            cout << endl << "\t#Selection-sort comparison: " << comps << endl;
            break;
        } // selection
        case 'm': {
            item.MergeSort(item.values, 0, item.values.size() - 1, comps);
            item.printVals();
            cout << endl << "\t#Merge-sort comparison: " << comps << endl;
            break;
        } // merge
        case 'h': {
            item.HeapSort(item.values, item.values.size(), comps);
            item.printVals();
            cout << endl << "\t#Heap-sort comparison: " << comps << endl;
            break;
        } // heap
        case 'q': {
            item.QuickSortFirst(item.values, 0, item.values.size() - 1, comps);
            item.printVals();
            cout << endl << "\t#Quick-sort-fp comparison: " << comps << endl;
            break;
        } // quicksort fixed
        case 'r': {
            item.QuickSortRecursive(item.values, 0, item.values.size() - 1, comps);
            item.printVals();
            cout << endl << "\t#Quick-sort-rp comparison: " << comps << endl;
            break;
        } // quicksort random
    } // switch

}   