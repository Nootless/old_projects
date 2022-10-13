#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    // starting variables needed
    int userInput = 0;
    unsigned long long primeSum = 0;
    unsigned long long primeNum = 2;
    int count = 0;
    int factorNum = 0;

    // asking user for input
    cout << "Enter integer: ";
    cin >> userInput;

    while ( count < userInput ) {
        // goes from 1 to square root of the tested number
        // to find how many factors there are
        for (int i = 1; i*i <= primeNum; i++) {
            // if the tested number is divisible, add one to the amount
            // of factors it has
            if ( (primeNum % i) == 0) {
                factorNum += 1;
            } // if
        } // for

        // if the number has only one factor, it adds it to the prime sum
        if (factorNum <= 1) {
            primeSum += primeNum;
            count++;
        } // if

        // updates the prime number being tested and
        // resets the number of factors
        primeNum++;
        factorNum = 0;
    } // while


    cout << "Prime sum: " << primeSum << endl;


    return EXIT_SUCCESS;
} // main
