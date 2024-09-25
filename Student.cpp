#include "Student.h"
#include <string>

using namespace std;
Student_Mullayarov::Student_Mullayarov()
{
    mark = age = 0;
    name = " ";
    surname = " ";
}

ostream& operator<<(ostream& out, Student_Mullayarov* s)
{
    out << "Имя студента: " << s->name << endl << "Фамилия студента: " << s->surname << endl << "Возраст студента: " << s->age << endl << "Средняя оценка по предметам: " << s->mark << endl;
    return out;
}

istream& operator>>(istream& in, Student_Mullayarov* s)
{
    bool exceptionOccured = true;
    string temp;
    string name;
    cout << "Введите имя студента\n";
    in >> ws;
    getline(in, temp);

    while ((temp = checkStr(temp)) == "Ошибка ввода строки" ) {

        cout << temp << endl;
        getline(in, temp);
    }
    s->name = temp;
    //if ((temp = checkStr(temp)) != "Ошибка ввода строки") {
    //    s->name = temp;
    //}
    //else {
    //    std::cout << "Не верно имя для студента - ошибка ввода :(" << endl;
    //}
    cout << "Введите фамилию студента\n";
    in >> ws;
    getline(in, temp);
    while ((temp = checkStr(temp)) == "Ошибка ввода строки") {

        cout << temp << endl;
        getline(in, temp);
    }
    s->surname = temp;
    //if ((temp = checkStr(temp)) != "Ошибка ввода строки") {
    //    s->surname = temp;
    //}
    //else {
    //    std::cout << "Не верна фамилия для студента - ошибка ввода :(" << endl;
    //}
    cout << "Введите возраст \n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            s->age = checkInt(temp);
            if (s->age < 18) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "Ошибка ввода :( Не верен возраст" << endl;
            getline(in, temp);
        }
    }
    exceptionOccured = true;
    cout << "Ввeдите среднюю оценку\n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            s->mark = checkDouble(temp);
            if (s->mark < 0.0 || s->mark > 5.0) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "Не верна оценка - ошибка ввода :(" << endl;
            getline(in, temp);
        }
    }
    return in;
}

ofstream& operator<<(ofstream& fout, Student_Mullayarov* s)
{

    fout << "Имя студента: " << s->name << endl << "Фамилия студента: " << s->surname << endl << "Возраст студента: " << s->age << endl << "Средняя оценка по предметам: " << s->mark << endl;
    return fout;
}

ifstream& operator>>(ifstream& fin, Student_Mullayarov* s)
{
    string line;
    getline(fin, line);
    s->name = line.substr(line.find_first_of(':') + 2);
    getline(fin, line);
    s->surname = line.substr(line.find_first_of(':') + 2);
    getline(fin, line);
    s->age = std::stoi(line.substr(line.find_first_of(':') + 2));
    getline(fin, line);
    s->mark = std::stod(line.substr(line.find_first_of(':') + 2));
    return fin;
}
