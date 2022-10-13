#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include "Student.h"
#include "Instructor.h"
using namespace std;

int main(int argc, char* argv[])
{
    // exits with error if the arguments aren't equal to 2,
    // the arguments are not the correct name, or
    // there is an issue processing them
    ifstream file1("instructors.txt", ios::in);
    ifstream file2("students.txt", ios::in);

    if (argc != 3) {
        cerr << "Usage: main [instructors_file] [students_file]" << endl;
        exit(1);
    } else if (strcmp(argv[1], "instructors.txt") != 0 || !file1) {
        cerr << "Error: cannot parse intructors information from file "
             << argv[1] << endl;
        exit(1);
    } else if (strcmp(argv[2],"students.txt") != 0 || !file2) {
        cerr << "Error: cannot parse students information from file "
             << argv[2] << endl;
        exit(1);
    } // if

    int userInputNum = 0;
    // will exit if the user Input is 3 for selection
    while(userInputNum != 3) {
        // login information and whether instructor or student
        userInputNum = 0;
        string username;
        string password;

        cout << endl;
        cout << "User Types," << endl;
        cout << "\t 1 - Instructor" << endl;
        cout << "\t 2 - Student" << endl;
        cout << "Select a login user type or enter 3 to exit: ";
        cin >> userInputNum;

        if (userInputNum == 1) { // instructor login
            // gets user info and checks if they are an instructor or not
            cout << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            Instructor instructor;

            // if successful login, will prompt user
            // for more information
            if(instructor.login(username,password)) {
                cout << endl << "You are now logged in as instructor "
                     << instructor.getInstructorName() <<  "." << endl << endl;
                int instructorInput = 0;
                // shows the instructor options to view stats of a specific student or
                // stats for a specific category
                while (instructorInput != 1 && instructorInput != 2) {
                    instructorInput = 0; // reset instructorInput

                    // list options
                    cout << "Query options," << endl;
                    cout << "\t1 - view grades of a student" << endl;
                    cout << "\t2 - view stats" << endl;
                    cout << "Enter option number: ";
                    cin >> instructorInput;

                    if (instructorInput == 1) { // username
                        string studentUsername;
                        Student stu = instructor.getStudent(studentUsername);

                        // trys to get the student the user asks for
                        // will throw an error if the student's name is incorrect
                        // otherwise it will print out the grades of the student
                        do {
                            cout << endl;
                            cout << "Enter student username to view grades: ";
                            cin >> studentUsername;
                            cout << endl;
                            stu = instructor.getStudent(studentUsername);
                            if (stu.getStudentName() == "") {
                                cout << "Student username is not valid.\n" << endl;
                            } else {
                                cout << "Student name: " << stu.getStudentName() << endl;
                                cout << "\tProject\t" << stu.getProjectGrade() << "%" << endl;
                                cout << "\tQuiz\t" << stu.getQuizGrade() << endl;
                                cout << "\tMidterm\t" << stu.getMidtermGrade() << "%" << endl;
                                cout << "\tFinal\t" << stu.getFinalGrade() << "%" << endl;
                                cout << "\tOverall\t" << stu.getOverallGrade() << "%" << endl;
                            } // if
                        } while (stu.getStudentName() == "");

                    } else if (instructorInput == 2) {
                        int gradeType = -1;
                        // while loop that runs only when a grade type has not
                        // been chosen
                        while(gradeType <= 0 || gradeType >= 6) {
                            gradeType = -1; // reset gradeType

                            // printing the choices for user
                            cout << endl;
                            cout << "Grade types," << endl;
                            cout << "\t1 - Project grade" << endl;
                            cout << "\t2 - Quiz grade" << endl;
                            cout << "\t3 - Midterm grade" << endl;
                            cout << "\t4 - Final grade" << endl;
                            cout << "\t5 - Overall grade" << endl;
                            cout << "Select a grade type to view stats: ";
                            cin >> gradeType;
                            cout << endl;

                            // if user does not input a valid grade type
                            if(gradeType <= 0 || gradeType >= 6) {
                                cout << "Invalid option. Please enter a valid option."
                                     << endl;
                            } // if
                        } // while

                        // This switch case goes through the value of grade type
                        // and changes the output display with each
                        switch (gradeType) {
                        case 1:
                        {
                            // gets the min and max of project
                            // students and prints them out
                            // along with the average of the project category
                            Student stuMin = instructor.getMinStudent(1);
                            Student stuMax = instructor.getMaxStudent(1);
                            cout <<  "Project grade stats," << endl;
                            cout << "\tmin\t" << stuMin.getProjectGrade() << "% "
                                 << "(" << stuMin.getStudentName() << ")" << endl;
                            cout << "\tmax\t" << stuMax.getProjectGrade() << "% "
                                 << "(" << stuMax.getStudentName() << ")" << endl;
                            cout << "\tavg\t" << instructor.getAvg(1) << "%" << endl;
                            break;
                        }
                        case 2:
                        {
                            // gets the min and max of Quiz
                            // students and prints them out
                            // along with the average of the project category
                            Student stuMin = instructor.getMinStudent(2);
                            Student stuMax = instructor.getMaxStudent(2);
                            cout << "Quiz grade stats," << endl;
                            cout << "\tmin " << stuMin.getQuizGrade() << "% "
                                 << "(" << stuMin.getStudentName() << ")" << endl;
                            cout << "\tmax " << stuMax.getQuizGrade() << "% "
                                 << "(" << stuMax.getStudentName() << ")" << endl;
                            cout << "\tavg " << instructor.getAvg(2)<< "%" << endl;
                            break;
                        }
                        case 3:
                        {
                            // gets the min and max of midterm
                            // students and prints them out
                            // along with the average of the project category
                            Student stuMin = instructor.getMinStudent(3);
                            Student stuMax = instructor.getMaxStudent(3);
                            cout << "Midterm grade stats," << endl;
                            cout << "\tmin\t" << stuMin.getMidtermGrade() << "% "
                                 << "(" << stuMin.getStudentName() << ")" << endl;
                            cout << "\tmax\t" << stuMax.getMidtermGrade() << "% "
                                 << "(" << stuMax.getStudentName() << ")" << endl;
                            cout << "\tavg\t" << instructor.getAvg(3)<< "%" << endl;
                            break;

                        }
                        case 4:
                        {
                            // gets the min and max of final
                            // students and prints them out
                            // along with the average of the project category
                            Student stuMin = instructor.getMinStudent(4);
                            Student stuMax = instructor.getMaxStudent(4);
                            cout << "Final grade stats," << endl;
                            cout << "\tmin\t" << stuMin.getFinalGrade() << "% "
                                 << "(" << stuMin.getStudentName() << ")" << endl;
                            cout << "\tmax\t" << stuMax.getFinalGrade() << "% "
                                 << "(" << stuMax.getStudentName() << ")" << endl;
                            cout << "\tavg\t" << instructor.getAvg(4)<< "%" << endl;
                            break;
                        }
                        case 5:
                        {
                            // gets the min and max of overall grade
                            // students and prints them out
                            // along with the average of the project category
                            Student stuMin = instructor.getMinStudent(5);
                            Student stuMax = instructor.getMaxStudent(5);
                            cout << "Overall grade stats," << endl;
                            cout << "\tmin\t" << stuMin.getOverallGrade() << "% "
                                 << "(" << stuMin.getStudentName() << ")" << endl;
                            cout << "\tmax\t" << stuMax.getOverallGrade() << "% "
                                 << "(" << stuMax.getStudentName() << ")" << endl;
                            cout << "\tavg\t" << instructor.getAvg(5) << "%" << endl;
                            break;
                        }
                        default:
                            cerr << "Error in selection" << endl;


                        } // switch
                    } else {
                        // invalid choice
                        cout << endl;
                        cout << "Invalid option. Please enter a valid option." << endl;
                        cout << endl;
                    } // if
                } // while

            } else {
                // bad user and/or password
                cout << endl;
                cout << "Login as instructor failed." << endl;
            } // if

        } else if (userInputNum == 2) { // student login
            // gets user info and checks if they are a student
            cout << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            Student student;

            // upon successful login
            if(student.login(username,password)) {
                cout << endl;
                cout << "You are now logged in as student " << student.getStudentName()
                     << "." << endl << endl;
                cout << "Do you want to view grades (y/n)? ";
                string gradeView;
                cin >> gradeView;

                // opens only if 'y' is inputed
                if (gradeView == "y") {
                    cout << endl; // prints the grade
                    cout << "Student name: " << student.getStudentName() << endl;
                    cout << "\tProject\t" << student.getProjectGrade() << "%" << endl;
                    cout << "\tQuiz\t" << student.getQuizGrade() << "%" << endl;
                    cout << "\tMidterm\t" << student.getMidtermGrade() << "%" << endl;
                    cout << "\tFinal\t" << student.getFinalGrade() << "%" << endl;
                    cout << "\tOverall\t" << student.getOverallGrade()<< "%" << endl;
                } // if

            } else {
                cout << endl;
                cout << "Login as student failed." << endl;
            } // if

        } else if (userInputNum == 3) { // exit state
            exit(0);
        } else {
            cout << endl;
            cout << "Invalid option. Please enter a valid option." << endl;
        } // if
    } // while

} // main
