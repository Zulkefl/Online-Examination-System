# Online Examination System (C++)

This project is a complete console-based Online Examination System built using Object-Oriented Programming in C++. It allows an Admin to create and save exams with both Multiple Choice Questions (MCQs) and Subjective Questions. Students can take the exam, get their results, and the system automatically saves results to a file.

## Features

**For Admin:**

✔ Create MCQs with options, correct answer and marks
✔ Create Subjective Questions with marks
✔ All questions are saved to a file so they are not lost after closing the program

**For Students:**

✔ Enter name and roll number before starting the exam
✔ Attempt MCQs and get immediate marks based on answers
✔ Attempt Subjective Questions
✔ Admin manually checks Subjective Questions and awards marks
✔ Final result is displayed on screen and also saved to a file

**File Handling:**

✔ Questions are saved to `Questions.txt`
✔ Student results are saved to `Result.txt`

## Concepts Used

This project uses all major concepts of Object-Oriented Programming:

* Classes and Objects
* Inheritance
* Polymorphism using virtual functions
* Abstraction
* File Handling (reading and writing to files)

## How to Run

1. Open the project in Microsoft Visual Studio 2022
2. Make sure all `.h` and `.cpp` files are added to the project
3. Build and Run the project
4. Choose option `1` for Admin to create the exam
5. Choose option `2` for a student to attempt the exam
6. Check `Questions.txt` for saved questions and `Result.txt` for saved results

## Project Structure

The project is divided into separate files for better understanding:

* `Question.h` and `Question.cpp`
* `MCQ.h` and `MCQ.cpp`
* `SubjectiveQuestion.h` and `SubjectiveQuestion.cpp`
* `Student.h` and `Student.cpp`
* `Exam.h` and `Exam.cpp`
* `Admin.h` and `Admin.cpp`
* `main.cpp`


