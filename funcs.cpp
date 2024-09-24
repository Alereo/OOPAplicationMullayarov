#pragma once
#include "funcs.h"
int checkInt(std::string str) {
    if (str.find(".") != str.npos) {
        cout << "������ ����� ������" << std::endl;
        return 0;
    }
    else {
        return stoi(str);
    }
}
double checkDouble(std::string str) {
    return stod(str);

}
std::string checkStr(std::string str) {
    if (str.find("/") != str.npos || str.find(".") != str.npos || std::regex_search(str, std::regex("[0-9]"))) {
        return "������ ����� ������";

    }
    else {
        return(str);
    }
}

void menu() {
    cout << "1)�������� ��������\n";
    cout << "2)����� ��������� ������\n";
    cout << "3)����� ��������� ������ � ����\n";
    cout << "4)���� ��������� �� �����\n";
    cout << "5)������� ������ ���������\n";
    cout << "0)�����\n";
}
