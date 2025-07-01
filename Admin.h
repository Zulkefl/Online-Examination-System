#ifndef ADMIN_H
#define ADMIN_H

#include "Exam.h"
#include "Student.h"

class Admin {
public:
    void createExam(Exam& exam);
    void checkSubjective(Exam& exam, Student& student);
};

#endif
