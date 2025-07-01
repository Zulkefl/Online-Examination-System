#include "Admin.h"
#include "MCQ.h"
#include "SubjectiveQuestion.h"
#include <iostream>
using namespace std;

void Admin::createExam(Exam& exam) {
    int num;
    cout << "--- Create Exam ---" << endl;

    cout << "How many MCQs? ";
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++) {
        string qText, opts[4];
        int correct, marks;

        cout << "\nEnter MCQ Question: ";
        getline(cin, qText);

        for (int j = 0; j < 4; j++) {
            cout << "Option " << j + 1 << ": ";
            getline(cin, opts[j]);
        }

        cout << "Correct Option (1-4): ";
        cin >> correct;

        cout << "Marks for this MCQ: ";
        cin >> marks;
        cin.ignore();

        exam.addQuestion(new MCQ(qText, opts, correct, marks));
    }

    cout << "\nHow many Subjective Questions? ";
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++) {
        string qText;
        int marks;

        cout << "\nEnter Subjective Question: ";
        getline(cin, qText);

        cout << "Marks for this Subjective Question: ";
        cin >> marks;
        cin.ignore();

        exam.addQuestion(new SubjectiveQuestion(qText, marks));
    }

    exam.saveQuestionsToFile();
    cout << "\nExam saved successfully.\n";
}

void Admin::checkSubjective(Exam& exam, Student& student) {
    exam.manualCheck(student);
}