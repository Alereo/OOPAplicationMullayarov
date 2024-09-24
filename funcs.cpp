#pragma once
#include "funcs.h"
int checkInt(std::string str) {
    if (str.find(".") != str.npos) {
        cout << "Ошибка ввода строки" << std::endl;
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
        return "Ошибка ввода строки";

    }
    else {
        return(str);
    }
}

void menu() {
    cout << "1)Добавить студента\n";
    cout << "2)Вывод студентов группы\n";
    cout << "3)Вывод студентов группы в файл\n";
    cout << "4)Ввод студентов из файла\n";
    cout << "5)Очистка списка студентов\n";
    cout << "0)Выход\n";
}
