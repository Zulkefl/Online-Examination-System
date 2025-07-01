#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    int mcqMarks;
    int subjectiveMarks;
public:
    Student(string n, int roll);
    void saveResultToFile();
    void setMCQMarks(int marks);
    void setSubjectiveMarks(int marks);
    int getTotalMarks();
    void displayResult();
};

#endif