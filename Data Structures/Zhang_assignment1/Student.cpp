#include <fstream>
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

bool Student::login(string username, string password)
{
    // opens file to read and error checks
    ifstream readFile("students.txt", ios::in);
    if (!readFile) {
        cerr << "File could not be opened" << endl;
        exit(1);
    } // if

    // read through entire file
    while (readFile.peek() != EOF) {
        // getting the line of info for the person and inserting it
        // into the user and pass variables
        string userInfo;
        string user;
        string pass;

        // get the line and assign the variables of information
        readFile >> user >> pass;

        // true if it matches a user
        if ( username == user && password == pass) {
            // set all the values from the doccument and
            // returns true

            // sets full name and username
            string firstName;
            string lastName;
            this->userName = user;
            readFile >> firstName;
            readFile >> lastName;
            setStudentName(firstName + " " + lastName);

            // sets the rest of the values
            readFile >> projectGrade;
            readFile >> quizGrade;
            readFile >> midtermGrade;
            readFile >> finalGrade;
            return 1;
        } // if

        // goes to the next line
        getline(readFile, userInfo);

    } // while

    return 0;
} // login

string Student::getStudentName()
{
    return fullName;
} //getStudentName

int Student::getProjectGrade()
{
    return projectGrade;
} // getProjectGrade

int Student::getQuizGrade()
{
    return quizGrade;
} // getQuizGrade

int Student::getMidtermGrade()
{
    return midtermGrade;
} // getMidtermGrade

int Student::getFinalGrade()
{
    return finalGrade;
} // getFinalGrade

double Student::getOverallGrade()
{
    // uses the values of the given grades and their weights
    // to find the overall grade
    return (getProjectGrade() * .3 + getQuizGrade() * .1 + getMidtermGrade() * .2 +
            getFinalGrade() * .4);
} // getOverallGrade
string Student::getUserName()
{
    return userName;
} // getStudentUserName
void Student::setStudentName(string fullName)
{
    this->fullName = fullName;
} // setStudentName

void Student::setProjectGrade(int grade)
{
    projectGrade = grade;
} // setProjectGrade

void Student::setQuizGrade(int grade)
{
    quizGrade = grade;
} // setQuizGrade

void Student::setMidtermGrade(int grade)
{
    midtermGrade = grade;
} // setMidtermGrade

void Student::setFinalGrade(int grade)
{
    finalGrade = grade;
} // setFinalGrade
