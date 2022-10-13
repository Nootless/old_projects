#include <cstdlib>
#include <iostream>
#include "arrayutil.h"

using namespace std;

int main()
{

    int array1[] = { 4, 3,  2,  1 };
    int array2[] = { 2, 5 , 1 , 3 , 9 };
    int array3[] = { 12, 6, 1, 3, 9, 22, 13};

    // printArray is a helper function which just prints out every
    // one of the results from each of the functions
    cout << "----------Array 1----------" << endl << endl;
    printArray (array1, 4);

    cout << "----------Array 2----------" << endl << endl;
    printArray (array2, 5);

    cout << "----------Array 3----------" << endl << endl;
    printArray (array3, 7);


} // main
