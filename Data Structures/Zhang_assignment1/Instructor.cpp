#include <fstream>
#include <iostream>
#include <string>
#include "Student.h"
#include "Instructor.h"
using namespace std;

Student Instructor::arr[] = {};
bool Instructor::login(string username, string password)
{
    // opens and checks if it successfully opens
    ifstream readFile("instructors.txt", ios::in);
    if(!readFile) {
        cerr << "File could not be opened" << endl;
        exit(1);
    } // if

    while(readFile.peek() != EOF) {
        // gets a login from the file and allows for
        // comparison between user input and file
        string userInfo;
        string user;
        string pass;

        readFile >> user >> pass;

        if( username == user && password == pass) {

            // gets the name of the instructor and returns true
            string firstName;
            string lastName;
            readFile >> firstName;
            readFile >> lastName;
            setInstructorName(firstName + " " + lastName);
            // helper method which gets all students into an array
            fillStudentList();
            return 1;
        } // if
        getline(readFile, userInfo);
    } // while

    return 0;
} // login

string Instructor::getInstructorName()
{
    return fullName;
} // getInstructorName

Student Instructor::getStudent(string userName)
{
    Student stu;
    int index;
    // goes through the array and looks to compare the student
    // to find their information
    for (int i = 0; i < 20; i++) {
        if(userName == arr[i].getUserName()) {

            return arr[i];

        } // if
    } // for
    // returns empty student if the username does not define a student
    return stu;

} // getStudent

Student Instructor::getMinStudent(int gradeType)
{
    Student student;
    int minGrade = 100;
    switch (gradeType)
    {
    case 1:
        // project min student
        for (int i = 0; i < 20; i++) { // loops through and finds the min grade student
            if (minGrade > arr[i].getProjectGrade()) {
                minGrade = arr[i].getProjectGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    case 2:
        // quiz min student
        for (int i = 0; i < 20; i++) {
            if (minGrade > arr[i].getQuizGrade()) {
                minGrade = arr[i].getQuizGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    case 3:
        // midterm min student
        for (int i = 0; i < 20; i++) {
            if (minGrade > arr[i].getMidtermGrade()) {
                minGrade = arr[i].getMidtermGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    case 4:
        // final min student
        for (int i = 0; i < 20; i++) {
            if (minGrade > arr[i].getFinalGrade()) {
                minGrade = arr[i].getFinalGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    case 5:
        // overall min student
        for (int i = 0; i < 20; i++) {
            if (minGrade > arr[i].getOverallGrade()) {
                minGrade = arr[i].getOverallGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    default:
        break;
    } // switch
    return student;
} // getMinStudent

Student Instructor::getMaxStudent(int gradeType)
{
    int maxGrade = 0;

    Student student;
    switch (gradeType)
    {
    case 1:
        // project grade max student
        for (int i = 0; i < 20; i++) { // loops through and finds max grade student
            if (maxGrade < arr[i].getProjectGrade()) {
                maxGrade = arr[i].getProjectGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    case 2:
        // quiz grade max student
        for (int i = 0; i < 20; i++) {
            if (maxGrade < arr[i].getQuizGrade()) {
                maxGrade = arr[i].getQuizGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    case 3:
        // midterm grade max student
        for (int i = 0; i < 20; i++) {
            if (maxGrade < arr[i].getMidtermGrade()) {
                maxGrade = arr[i].getMidtermGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    case 4:
        // final grade max student
        for (int i = 0; i < 20; i++) {
            if (maxGrade < arr[i].getFinalGrade()) {
                maxGrade = arr[i].getFinalGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;

    case 5:
        // overall grade max student
        for (int i = 0; i < 20; i++) {
            if (maxGrade < arr[i].getOverallGrade()) {
                maxGrade = arr[i].getOverallGrade();
                student = arr[i];
            } // if
        } // for
        return student;
        break;
    default:
        // default case
        break;
    } // switch
    // used as a default case for error checking
    return student;
} // getMaxStudent

double Instructor::getAvg(int gradeType)
{
    double grade = 0;
    // switch case allows for switching between each grade type and
    // finds the average of all students in that specific category.
    // default case for error checking
    switch (gradeType)
    {
    case 1:
        // project grade average
        for (int i = 0; i < 20; i++) { // sums up all the grades and divides by the total students
            grade += arr[i].getProjectGrade();
        }
        grade /= 20;
        return grade;
        break;
    case 2:
        // quiz grade average

        for (int i = 0; i < 20; i++) {
            grade += arr[i].getQuizGrade();
        } // for
        grade /= 20;

        return grade;
        break;
    case 3:
        // midterm grade average

        for (int i = 0; i < 20; i++) {
            grade += arr[i].getMidtermGrade();
        } // for
        grade /= 20;

        return grade;
        break;
    case 4:
        // final grade average

        for (int i = 0; i < 20; i++) {
            grade += arr[i].getFinalGrade();
        } // for
        grade /= 20;

        return grade;
        break;
    case 5:
        // overall grade average
        for (int i = 0; i < 20; i++) {
            grade += arr[i].getOverallGrade();
        } // for
        grade /= 20;

        return grade;
        break;
    default:
        // creates an error case
        grade = -1;
        return grade;
        break;

    } // switch
    return grade;
} // getAvg

void Instructor::setInstructorName(string fullName)
{
    this->fullName = fullName;
} // setInstructorName

void Instructor::fillStudentList()
{
    string userInfo;

    // opens up the student file
    ifstream readFile("students.txt", ios::in);
    if(!readFile) {
        cerr << "File could not be opened.";
        exit(1);
    } // if


    // loops through and assigns the entire array
    for (int i = 0; i < 20; i++) {
        Student student;
        string user;
        string pass;
        string userInfo;

        // logs in to the student object and assigns it to
        // the i index in the array
        readFile >> user >> pass;
        student.login(user, pass);
        arr[i] = student;

        // goes to next line
        getline(readFile, userInfo);
    } // for
} // fillStudentList
