#include <iostream>
#include <string>
#include <Vector>
#include <fstream>
#include "Group.h"
#include "Student.h"
#include "funcs.h"
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Group_Mullayarov group = Group_Mullayarov();
    string temp;
    int res;
    while (true) {
        menu();
        getline(cin, temp);
        try {
            res = checkInt(temp);
        }
        catch (invalid_argument) {
            cout << "Ошибка\n";
            continue;
        }
        switch (res) {
        case 1:
            group.addStudents();
            break;
        case 2:
            group.printStudents();
            break;
        case 3:
            group.printFileGroup();
            break;
        case 4:
            group.deleteGroup();
            group.readFileGroup();
            break;
        case 5:
            group.deleteGroup();
            break;
        case 0:
            group.deleteGroup();
            return 0;
        default: cout << "Неверный ввод:(\n";
            break;
        }
    }
}