#include <iostream>
#include <cstdlib>
#include "arrayutil.h"

using namespace std;

int getMax (int arr[], int length)
{
    // default max as 0
    int max = 0;

    /* goes through array and checks to see if
    the current index is higher than the current max
    and will replace it if it is higher */
    for (int i = 0; i < length; i++) {

        if (arr[i] > max) {
            max = arr[i];
        } // if
    } // for

    return max;

} // getMax method


double getMean (int arr[], int length)
{
    // default mean is 0
    double mean = 0;

    // gets the sum
    for (int i = 0; i < length; i++) {

        mean += (double)arr[i];

    } // for

    // divides the sum by the total amount of items
    mean /= (double)length;

    return mean;
} // getMean method


double getVar (int arr[], int length)
{
    // these are used to find the summation of the terms and squared terms
    double sumNum = 0;
    double squareSumNum = 0;

    // finds the sum of the numbers and sum of the squared numbers
    for (int i = 0; i < length; i++) {
        sumNum += arr[i];
        squareSumNum += arr[i] * arr[i];
    } // for

    // gets the terms for the variance
    double overLength = 1 / (double)length;
    double term1 = overLength * (squareSumNum);
    double term2 = overLength * (sumNum);

    return term1 - (term2 * term2);

} // getVar method

void sortArray (int arr[], int length)
{
    int hold;
    // bubble sort
    // iterates through the first values
    for ( int i = 0; i < length - 1; i++ ) {
        // iterates to through the values after
        for ( int j = 0; j < length - i - 1; j++ ) {
            if (arr[j] > arr[j + 1]) {
                hold = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = hold;
            } // if
        } // for

    } // for

} // sortArray method

void printArray (int arr[], int length)
{
    cout << "Original Array: " << endl;
    for (int i = 0; i < length; i++)  {
        cout << arr[i] << endl;
    } // for
    cout << endl;
    cout << "getMax of Array: " << getMax(arr, length) << endl;
    cout << "getMean of Array: " << getMean(arr, length) << endl;
    cout << "getVar of Array: " << getVar(arr, length) << endl;
    cout << "Sorted Array:" << endl;
    sortArray(arr, length);
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    } // for

    cout << endl;

} // printArray method
