#include "Head_Student.h"

Headman_Mullayarov::Headman_Mullayarov()
{
    position = "";
    amount_subjects = 0;
}

Headman_Mullayarov::~Headman_Mullayarov()
{
}

void Headman_Mullayarov::showStudent(ostream& out)
{
    Student_Mullayarov::showStudent(out);
    out << "���������: " << position << endl;
    out << "���������� ������� ��������� " << amount_subjects << endl;
}

void Headman_Mullayarov::createStudent(istream& in)
{
    string temp;
    bool exceptionOccured = true;
    Student_Mullayarov::createStudent(in);
    cout << "������� ��������� ��������\n";
    in >> ws;
    getline(in, temp);
    while ((temp = checkStr(temp)) == "������ ����� ������") {

        cout << temp << endl;
        getline(in, temp);
    }
    position = temp;
    cout << "������� ���������� ������� ��������� \n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            amount_subjects = checkInt(temp);
            if (amount_subjects <= 0) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "������ ����� :( �� ����� ����������" << endl;
            getline(in, temp);
        }
    }

}


