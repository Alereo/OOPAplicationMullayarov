#pragma once
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include "funcs.h"

using namespace std;

class Student_Mullayarov
{
private:
    string name,surname;
    double mark;
    int age;
public:
    Student_Mullayarov();
    friend ostream& operator << (ostream& out, Student_Mullayarov* s);
    friend istream& operator >> (istream& in, Student_Mullayarov* s);
    friend ofstream& operator << (ofstream& fout, Student_Mullayarov* s);
    friend ifstream& operator >> (ifstream& fin, Student_Mullayarov* s);
};

