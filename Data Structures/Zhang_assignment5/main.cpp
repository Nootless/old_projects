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

int main ( int argc, char * argv[]) 
{
    ifstream ifs(argv[1], ios::in);
    if (!ifs) { // file check
        cerr << "Error: File has failed to open or does not exist." << endl;
        exit(1);
    } // if

    // setting up the vector of values
    SortingAlgo item;
    int temp;
    while(ifs >> temp) {
        item.values.push_back(temp);
    } // while
    
    
    
    printCommands();
    long comps;
    char input;
    cout << "Enter the algorithm: ";
    cin >> input;
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