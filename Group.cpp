#include "Group.h"
#include <string>
#include "funcs.h"

using namespace std;

BOOST_CLASS_EXPORT(Headman_Mullayarov)

using boost::archive::archive_flags;

Group_Mullayarov::Group_Mullayarov(){
}

Group_Mullayarov::~Group_Mullayarov()
{
    deleteGroup();
}

void Group_Mullayarov::printStudents() {
    if (students.empty()) {
        cout << "Нет студентов" << endl;
    }
    else {
        for (int i = 0; i < students.size(); i++) {
            students[i]->showStudent(cout);
        }
    }
}

void Group_Mullayarov::printFileGroup() {
    string filename;
    cout << "Введи название файла" << endl;
    getline(cin, filename);
    ofstream fout;
    fout.open(filename, ios::trunc);
    if (fout.is_open()) {
        boost::archive::text_oarchive write(fout, archive_flags::no_header);
        write << students;
        fout.close();
    }
    else {
        cout << "Файл не удалось открыть" << endl;
    }
}


void Group_Mullayarov::addStudents() {
    shared_ptr<Student_Mullayarov> student = make_shared<Student_Mullayarov>();
    student->Student_Mullayarov::createStudent(cin);
    students.push_back(student);
}

void Group_Mullayarov::addStudentsWithPosition() {
    shared_ptr<Headman_Mullayarov> student = make_shared<Headman_Mullayarov>();
    student->Headman_Mullayarov::createStudent(cin);
    students.push_back(student);
}

void Group_Mullayarov::deleteGroup() {
    students.clear();
}




void Group_Mullayarov::readFileGroup()
{
    deleteGroup();
    string filename;
    cout << "введи название файла" << endl;
    getline(cin, filename);
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) {
        if (fin.peek() != EOF) {
            while (fin.peek() != EOF) {
                boost::archive::text_iarchive load(fin, archive_flags::no_header);
                load >> students;
            }
        }
        else {
            cout << "файл пустой" << endl;
        }
        fin.close();
    }
    else {
        cout << "файл не удалось открыть" << endl;
    }
}