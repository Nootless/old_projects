#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    // starting variables
    int startTime;
    int durationTime;
    int endTime;

    // prompting the user for information
    cout << "Enter in a start time: ";
    cin >> startTime;
    cout << "Enter in a duration: ";
    cin >> durationTime;

    // convert time to minutes and hours
    int minutes = startTime % 100;
    startTime /= 100;
    int hours = startTime % 100;

    int durationMin = durationTime % 100;
    durationTime /= 100;
    int durationHours = durationTime % 100;

    // add up all the minutes and hours
    int finalMinutes = minutes + durationMin;
    int carryOverTime = finalMinutes / 60;
    finalMinutes %= 60;

    int finalHours = hours + durationHours + carryOverTime;
    finalHours %= 24;

    // convert the time to the standard input and prints it out
    endTime = (finalHours * 100) + finalMinutes;
    cout << "End time is: " << endTime << endl;

} // main
