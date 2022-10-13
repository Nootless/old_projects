#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
    // sets up starting variables and asks for input
    string userInput = "";
    int returnValue = 0;
    int num = 0;

    // asks user for input
    cout << "Enter integers: ";
    getline(cin, userInput);

    // turns string into stream
    stringstream ss(userInput);

    // takes number from stream and XOR's it with current number assigned
    while (ss >> num) {
        returnValue ^= num;

    } // while

    cout << "Exclusive: " << returnValue << endl;
    return EXIT_SUCCESS;

} // main
