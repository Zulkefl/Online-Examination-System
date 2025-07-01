#include "Admin.h"
#include "Exam.h"
#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    Admin admin;
    Exam exam;

    cout << "\n--- Online Examination System ---\n";
    exam.loadQuestionsFromFile();

    int choice;
    cout << "1. Create Exam (Admin)\n2. Conduct Exam (Student)\nChoice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        admin.createExam(exam);
    }
    else if (choice == 2) {
        string name;
        int roll;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your roll number: ";
        cin >> roll;
        cin.ignore();

        Student student(name, roll);
        exam.conductExam(student);
        admin.checkSubjective(exam, student);
        student.displayResult();
        student.saveResultToFile();

    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
