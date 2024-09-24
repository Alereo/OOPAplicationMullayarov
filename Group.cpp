#include "Group.h"
#include <string>
#include "funcs.h"
using namespace std;

Group_Mullayarov::Group_Mullayarov(){
}

void Group_Mullayarov::printStudents() {
    if (students.empty()) {
        cout << "Нет студентов" << endl;
    }
    else {
        for (int i = 0; i < students.size(); i++) {
            cout << students[i];
        }
    }
}

void Group_Mullayarov::printFileGroup() {
    string filename;
    cout << "Введи название файла" << endl;
    getline(cin, filename);
    ofstream fout;
    fout.open(filename);
    if (fout.is_open()) {
        for (int i = 0; i < students.size(); i++) {
            fout << students[i];
        }
        fout.close();
    }
    else {
        cout << "Файл не удалось открыть" << endl;
    }
}

void Group_Mullayarov::addStudents() {
    Student_Mullayarov* student = new Student_Mullayarov();
    cin >> student;
    students.push_back(student);
}

void Group_Mullayarov::deleteGroup() {
    for (auto student : students) {
        delete student;
    }
    students.clear();
}


void Group_Mullayarov::readFileGroup() {
    string filename;
    cout << "Введи название файла" << endl;
    getline(cin, filename);
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) {
        if (fin.peek() != EOF) {
            while (fin.peek() != EOF) {
                Student_Mullayarov* student = new Student_Mullayarov();
                fin >> student;
                students.push_back(student);
            }
        }
        else {
            cout << "Файл пустой" << endl;
        }
        fin.close();
    }
    else {
        cout << "Файл не удалось открыть" << endl;
    }
}