#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "SortingAlgo.h"

using namespace std;


long unsigned SortingAlgo::SelectionSort(vector<int> & values, int length) {
    long unsigned comparisons = 0;
    int endIndex = length - 1;
    for (int current=0; current < endIndex; current++) {
        swap(values[current],values[MinIndex(values,current,endIndex,comparisons)]);
    } // for
    return comparisons;
} // SelectionSort

int SortingAlgo::MinIndex(vector<int> & values, int start, int end, long unsigned & comparisons) {
    
    int mindex = start;

    // iterate over everything from current iterator value to last value
    for (int index = start + 1; index <= end; index++) {
        if (values[index] < values [mindex]) {
            mindex = index;
        } // if
        comparisons++;
    } // for
    // sends the minimum index
    return mindex;

} // minIndex

long unsigned SortingAlgo::MergeSort (vector<int> & values, int first, int last, long & comparisons) {
    // while the value is not last
    if (first < last) {
        
        comparisons++;
        int middle = (first + last) / 2;
        MergeSort(values, first, middle, comparisons);
        MergeSort (values, middle + 1, last, comparisons);
        Merge(values, first, middle, middle + 1, last, comparisons);
    } // if

    return comparisons;
} // MergeSort

void SortingAlgo::Merge(vector<int> & values, int leftFirst, int leftLast, int rightFirst, int rightLast, long & comparisons) {
    int maxSize = 100000;
    int tempArray[maxSize];
    int index = leftFirst;
    int saveFirst = leftFirst;

    // keeps looping until the left first plus leftLast  and rightfirst plus rightlast are equivalent
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
        if (values[leftFirst] < values[rightFirst]) {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        } else {// inserts into index
            tempArray[index] = values[rightFirst];
            rightFirst++;
        } // if
    comparisons++;
    index++;
    } // while

    // copies over items from left half of array
    while(leftFirst <= leftLast) {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    } // while
    // copies over items from right half 
    while (rightFirst <= rightLast) {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    } // while

    // stores all the values from the temp array into the original array
    for (index = saveFirst; index <= rightLast; index++) {
        values[index] = tempArray[index];
    } // for
} // Merge

void SortingAlgo::HeapSort(vector<int> & values, int numValues, long & comparisons) {
    int index;

    // constructing list
    for (index = numValues/2 - 1; index >= 0; index--) {
        ReheapDownConstruct(values, index, numValues - 1);
    } // for 
    
    // Sorts the array by reheap down
    for (index = numValues - 1; index >= 1; index--) {
        swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1, comparisons);
    } // for
} // heapSort

void SortingAlgo::ReheapDown(vector<int> & values, int root, int bottom, long & comparisons) {
    int maxChild;
    int rightChild;
    int leftChild;
    leftChild = root*2 + 1;
    rightChild = root*2 + 2;
    
    // only keeps going if the left child of the node is less than the lowest value
    if (leftChild <= bottom) {
        comparisons++;
        // if the child is the bottom
        if (leftChild == bottom) {
            comparisons++;
            maxChild = leftChild;
        } else {
            comparisons++;
            // if statement to determine the max child
            if (values[leftChild] <= values[rightChild]) {
                comparisons++;
                maxChild = rightChild;
            } else {
                comparisons++;
                maxChild = leftChild;
            } // if
        } // if
        // goes only if the root value is less than the max child
        if (values[root] < values[maxChild]) {
            comparisons++;
            swap(values[root], values[maxChild]);
            ReheapDown(values, maxChild, bottom, comparisons);
        } // if
        
    } // if

} // ReheapDown
void SortingAlgo::ReheapDownConstruct(vector<int> & values, int root, int bottom) {
    int maxChild;
    int rightChild;
    int leftChild;
    leftChild = root*2 + 1;
    rightChild = root*2 + 2;

    // only keeps going if left child is less than lowest value
    if (leftChild <= bottom) {
        // sets max child
        if (leftChild == bottom) {
            maxChild = leftChild;
        } else {
            if (values[leftChild] <= values[rightChild]) {
                maxChild = rightChild;
            } else {
                maxChild = leftChild;
            } // if
        } // if
        // swaps max child with root
        if (values[root] < values[maxChild]) {
            swap(values[root], values[maxChild]);
            ReheapDownConstruct(values, maxChild, bottom);
        } // if
        
    } // if
} // reheapDownConstruct

int SortingAlgo::Split(std::vector<int>& values, int first, int last, long& comparisons) {
    int pivot =  values[first];
    int part1 = first + 1;

    // loops over every value but the pivot
    for (int i = first + 1; i <= last; i++) {

        // checks if the values are less than the pivot
        // then swaps them with the current index
        comparisons++;
        if (values[i] < pivot) {
            if (i != part1) {
                swap(values.at(part1),values.at(i));
            } // if
            part1++;
        } // if
    } // for
    values.at(first) =  values.at(part1 - 1);
    values.at(part1 - 1) = pivot;

    return part1 - 1;
} // split

void SortingAlgo::QuickSortFirst(vector<int>& values, int first, int last, long& comparisons) {
    // base case
    if (first < last) {
        int splitPoint = Split(values, first, last, comparisons);
        QuickSortFirst(values, first, splitPoint - 1, comparisons); // recursively call for first half
        QuickSortFirst(values, splitPoint + 1, last, comparisons); // recursively call for last half
    } // if 
} // QuickSortFirst

int SortingAlgo::splitRecursive(vector<int>& values, int first, int last, long& comparisons) {
    int pivot = values[last];
    int part1 =  first - 1;
    // uses the pivot to move the lesser values to the left 
    // moves higher values to the right, center has pivot
    for (int i = first; i <= last - 1; i++) {
        comparisons++;
        if (values[i] <= pivot) {
            part1++;
            swap(values.at(part1), values.at(i));
        } // if
    } // for
    // swaps the point where the partition should go
    // and the value it has
    swap(values[part1 + 1], values[last]); 
    return (part1 + 1);
} // splitRecursive

int SortingAlgo::splitRecursiveHelper(vector<int>& values, int first, int last, long& comparisons) {
    srand(time(NULL));
    // finds random value between the indicies
    int random = first + rand() % (last - first);

    // moves it so that the swapRecursive can utilize random value
    swap(values.at(random),values.at(last));
    return splitRecursive(values, first, last, comparisons);
} // splitRecursiveHelper

void SortingAlgo::QuickSortRecursive(vector<int>& values, int first, int last, long& comparisons) {
    if (first < last) {
        // breaks the vector recursively into two pieces and solves them
        // as seperate arrays
        int splitVal =  splitRecursiveHelper(values, first, last, comparisons);
        QuickSortRecursive(values, first, splitVal - 1, comparisons);
        QuickSortRecursive(values, splitVal + 1, last, comparisons);
    } // if
} // QuickSortRecursive

void SortingAlgo::printVals() {
    for (unsigned int i = 0; i < values.size(); i++) {
        cout << values.at(i) << " ";
    } // for
} // printVals