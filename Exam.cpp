#include "Exam.h"
#include "MCQ.h"
#include "SubjectiveQuestion.h"
#include <iostream>
#include <fstream>
using namespace std;

Exam::Exam() {
    mcqMarks = 0;
    subjectiveMarks = 0;
}

void Exam::addQuestion(Question* q) {
    questions.push_back(q);
}

void Exam::conductExam(Student& student) {
    cout << "\n--- Exam Started ---" << endl;
    for (int i = 0; i < questions.size(); i++) {
        cout << "\nQuestion " << i + 1 << ":" << endl;
        questions[i]->display();

        MCQ* mcq = dynamic_cast<MCQ*>(questions[i]);
        if (mcq != NULL) {
            int choice;
            cout << "Enter your choice (1-4): ";
            cin >> choice;
            mcq->setChosenOption(choice);
            if (mcq->checkAnswer()) {
                mcqMarks += mcq->getMarks();
            }
        }

        SubjectiveQuestion* subj = dynamic_cast<SubjectiveQuestion*>(questions[i]);
        if (subj != NULL) {
            cout << "Write your answer: ";
            cin.ignore();
            string answer;
            getline(cin, answer);
            subj->setStudentAnswer(answer);
        }
    }
    student.setMCQMarks(mcqMarks);
    cout << "\nExam finished. MCQ Marks: " << mcqMarks << endl;
}

void Exam::manualCheck(Student& student) {
    cout << "\n--- Manual Checking for Subjective Questions ---" << endl;
    for (int i = 0; i < questions.size(); i++) {
        SubjectiveQuestion* subj = dynamic_cast<SubjectiveQuestion*>(questions[i]);
        if (subj != NULL) {
            cout << "\nQuestion:" << endl;
            subj->display();
            cout << "Student's Answer: " << subj->getStudentAnswer() << endl;
            int marks;
            cout << "Enter marks awarded: ";
            cin >> marks;
            subj->setMarksAwarded(marks);
            subjectiveMarks += marks;
        }
    }
    student.setSubjectiveMarks(subjectiveMarks);
}

void Exam::saveQuestionsToFile() {
    ofstream fout("Questions.txt");
    for (int i = 0; i < questions.size(); i++) {
        questions[i]->saveToFile(fout);
    }
    fout.close();
}

void Exam::loadQuestionsFromFile() {
    ifstream fin("Questions.txt");
    if (!fin) {
        cout << "No saved questions found." << endl;
        return;
    }
    string type;
    while (getline(fin, type)) {
        if (type == "MCQ") {
            addQuestion(MCQ::loadFromFile(fin));
        }
        else if (type == "SUBJ") {
            addQuestion(SubjectiveQuestion::loadFromFile(fin));
        }
    }
    fin.close();
}
