#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>

class SortingAlgo 
{
public:
long unsigned SelectionSort (std::vector<int> &, int);
int MinIndex(std::vector<int>&, int, int, long unsigned &);
long unsigned MergeSort (std::vector<int> &, int, int, long & comparisons);
void Merge(std::vector<int>&, int, int, int, int, long &);
void HeapSort (std::vector<int>&, int, long&);
void ReheapDown(std::vector<int>&, int, int, long&);
void ReheapDownConstruct(std::vector<int>&, int, int);
int Split(std::vector<int>&, int, int, long&);
void QuickSortFirst (std::vector<int>&, int, int, long&);
int splitRecursive(std::vector<int>&, int, int, long&);
int splitRecursiveHelper(std::vector<int>&, int, int, long&);
void QuickSortRecursive(std::vector<int>&, int, int, long&);
void printVals();
std::vector<int> values;
private:
    
};

