#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>

class Instructor
{
public:
    bool login(std::string, std::string);
    std::string getInstructorName();
    Student getStudent(std::string);
    Student getMinStudent(int);
    Student getMaxStudent(int);
    double getAvg(int);
    void setInstructorName(std::string);
private:
    std::string fullName;
    static Student arr[20];
    void fillStudentList();
}; // Instructor class
#endif
