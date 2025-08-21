#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* student_Name;  
    char* exam_Date;     
    int score;

public:
    // Constructor
    Exam(const char* name, const char* date, int s) {
        student_Name = new char[strlen(name) + 1];
        strcpy(student_Name, name);

        exam_Date = new char[strlen(date) + 1];
        strcpy(exam_Date, date);

        score = s;
    }

    // No Copy Constructor (default shallow copy will be used)
    // No Assignment Operator (default shallow copy will be used)

    // Destructor
    ~Exam() {
        delete[] student_Name;
        delete[] exam_Date;
        cout << "Destructor called for Exam object!" << endl;
    }

    void display() const {
        cout << "Student: " << student_Name 
             << ", Date: " << exam_Date 
             << ", Score: " << score << endl;
    }
};

int main() {
    Exam exam1("Aqsa", "20-08-2025", 90);
    cout << "Exam1 details: ";
    exam1.display();

    // Shallow Copy happens here (default copy constructor)
    Exam exam2 = exam1;  
    cout << "Exam2 (shallow copy of Exam1) details: ";
    exam2.display();

    // When program ends, both exam1 and exam2 destructors run
    // Problem: both try to delete the same memory
    return 0;
}

