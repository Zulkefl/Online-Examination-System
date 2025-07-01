#ifndef MCQ_H
#define MCQ_H

#include "Question.h"
#include <fstream>

class MCQ : public Question {
private:
    string options[4];
    int correctOption;
    int chosenOption;
    int marks;
public:
    MCQ(string qText, string opts[], int correct, int m);
    void display();
    bool checkAnswer();
    void setChosenOption(int opt);
    void saveToFile(ofstream& fout);
    static MCQ* loadFromFile(ifstream& fin);
    int getMarks();
};

#endif