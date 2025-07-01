#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question {
protected:
    string questionText;
public:
    virtual void display() = 0;
    virtual bool checkAnswer() = 0;
    virtual void saveToFile(ofstream& fout) = 0;
    virtual ~Question() {}
};

#endif