#include "MCQ.h"
#include <iostream>
using namespace std;

MCQ::MCQ(string qText, string opts[], int correct, int m) {
    questionText = qText;
    for (int i = 0; i < 4; i++) {
        options[i] = opts[i];
    }
    correctOption = correct;
    chosenOption = -1;
    marks = m;
}

void MCQ::display() {
    cout << questionText << " [Marks: " << marks << "]" << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}

void MCQ::setChosenOption(int opt) {
    chosenOption = opt;
}

bool MCQ::checkAnswer() {
    return chosenOption == correctOption;
}

void MCQ::saveToFile(ofstream& fout) {
    fout << "MCQ" << endl;
    fout << questionText << endl;
    for (int i = 0; i < 4; i++) {
        fout << options[i] << endl;
    }
    fout << correctOption << endl;
    fout << marks << endl;
}

MCQ* MCQ::loadFromFile(ifstream& fin) {
    string qText, opts[4];
    int correct, m;
    getline(fin, qText);
    for (int i = 0; i < 4; i++) {
        getline(fin, opts[i]);
    }
    fin >> correct;
    fin >> m;
    fin.ignore();
    return new MCQ(qText, opts, correct, m);
}

int MCQ::getMarks() {
    return marks;
}
