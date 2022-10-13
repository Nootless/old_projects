#ifndef STUDENT_H
#define STUDENT_H

#include <string>
class Student
{
public:
    bool login(std::string, std::string);
    std::string getStudentName();
    int getProjectGrade();
    int getQuizGrade();
    int getMidtermGrade();
    int getFinalGrade();
    double getOverallGrade();
    std::string getUserName();
    void setStudentName(std::string);
    void setProjectGrade(int);
    void setQuizGrade(int);
    void setMidtermGrade(int);
    void setFinalGrade(int);
private:
    std::string fullName;
    std::string userName;
    int projectGrade;
    int quizGrade;
    int midtermGrade;
    int finalGrade;
}; // Student
#endif
