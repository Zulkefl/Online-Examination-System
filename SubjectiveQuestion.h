#ifndef SUBJECTIVEQUESTION_H
#define SUBJECTIVEQUESTION_H

#include "Question.h"
#include <fstream>

class SubjectiveQuestion : public Question {
private:
    string studentAnswer;
    int marksAwarded;
    int marks;
public:
    SubjectiveQuestion(string qText, int m);
    void display();
    bool checkAnswer();
    void setStudentAnswer(string answer);
    string getStudentAnswer();
    void setMarksAwarded(int marks);
    int getMarksAwarded();
    int getMarks();
    void saveToFile(ofstream& fout);
    static SubjectiveQuestion* loadFromFile(ifstream& fin);
};

#endif