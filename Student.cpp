#include "Student.h"
#include<fstream>
#include <iostream>
using namespace std;

Student::Student(string n, int roll) {
    name = n;
    rollNumber = roll;
    mcqMarks = 0;
    subjectiveMarks = 0;
}

void Student::setMCQMarks(int marks) {
    mcqMarks = marks;
}

void Student::setSubjectiveMarks(int marks) {
    subjectiveMarks = marks;
}

int Student::getTotalMarks() {
    return mcqMarks + subjectiveMarks;
}

void Student::displayResult() {
    cout << "\n--- Result ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "MCQ Marks: " << mcqMarks << endl;
    cout << "Subjective Marks: " << subjectiveMarks << endl;
    cout << "Total Marks: " << getTotalMarks() << endl;
}


void Student::saveResultToFile() {
    ofstream fout("Result.txt", ios::app); 
    fout << "Name: " << name << endl;
    fout << "Roll Number: " << rollNumber << endl;
    fout << "MCQ Marks: " << mcqMarks << endl;
    fout << "Subjective Marks: " << subjectiveMarks << endl;
    fout << "Total Marks: " << getTotalMarks() << endl;
    fout << "------------------------------" << endl;
    fout.close();
}
