#ifndef EXAM_H
#define EXAM_H

#include <vector>
#include "Question.h"
#include "Student.h"
using namespace std;

class Exam {
private:
    vector<Question*> questions;
    int mcqMarks;
    int subjectiveMarks;
public:
    Exam();
    void addQuestion(Question* q);
    void conductExam(Student& student);
    void manualCheck(Student& student);
    void saveQuestionsToFile();
    void loadQuestionsFromFile();
};

#endif