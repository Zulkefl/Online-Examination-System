#include "SubjectiveQuestion.h"
#include <iostream>
using namespace std;

SubjectiveQuestion::SubjectiveQuestion(string qText, int m) {
    questionText = qText;
    marks = m;
    studentAnswer = "";
    marksAwarded = 0;
}

void SubjectiveQuestion::display() {
    cout << questionText << " [Marks: " << marks << "]" << endl;
}

void SubjectiveQuestion::setStudentAnswer(string answer) {
    studentAnswer = answer;
}

string SubjectiveQuestion::getStudentAnswer() {
    return studentAnswer;
}

void SubjectiveQuestion::setMarksAwarded(int marks) {
    marksAwarded = marks;
}

int SubjectiveQuestion::getMarksAwarded() {
    return marksAwarded;
}

bool SubjectiveQuestion::checkAnswer() {
    return false;
}

int SubjectiveQuestion::getMarks() {
    return marks;
}

void SubjectiveQuestion::saveToFile(ofstream& fout) {
    fout << "SUBJ" << endl;
    fout << questionText << endl;
    fout << marks << endl;
}

SubjectiveQuestion* SubjectiveQuestion::loadFromFile(ifstream& fin) {
    string qText;
    int m;
    getline(fin, qText);
    fin >> m;
    fin.ignore();
    return new SubjectiveQuestion(qText, m);
}