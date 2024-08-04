#include <iostream>

using namespace std;
const int NUM_SUBJECTS = 7;

class Student {
protected:
    int rollNumber;
    char name[20];

public:
    void getData() {
        cout << "Enter student roll no.: ";
        cin >> rollNumber;
        cout << "Enter student name: ";
        cin >> name;
    }

    void showData() {
        cout << "Roll No.: " << rollNumber << endl;
        cout << "Name: " << name << endl;
    }
};

class Exam : virtual public Student {
protected:
    int marks[NUM_SUBJECTS];

public:
    void getExamData(const string& examType) {
        cout << "Enter the marks student got in " << NUM_SUBJECTS << " subjects in " << examType << " exam: ";
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            cin >> marks[i];
        }
    }

    void showData() {
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            cout << marks[i] << "\t";
        }
        cout << endl;
    }
};

class InternalExam : public Exam {
public:
    void getExamData() {
        Exam::getExamData("internal");
    }
};

class FinalExam : public Exam {
public:
    void getExamData() {
        Exam::getExamData("final");
    }
};

class AverageMark : public InternalExam, public FinalExam {
private:
    float averageMarks;

public:
    void calculate() {
        int total = 0;
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            total += (InternalExam::marks[i] + FinalExam::marks[i]);
        }
        averageMarks = static_cast<float>(total) / (2 * NUM_SUBJECTS);
    }

    void showData() {
        Student::showData();
        cout << "Internal exam marks: " << endl;
        InternalExam::showData();
        cout << "Final exam marks: " << endl;
        FinalExam::showData();
        cout << "Average Marks: " << averageMarks;
    }
};

int main() {
    AverageMark averageMark;

    averageMark.getData();
    averageMark.InternalExam::getExamData();
    averageMark.FinalExam::getExamData();
    averageMark.calculate();
    averageMark.showData();

    return 0;
}