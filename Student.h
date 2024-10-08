#pragma once
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include "funcs.h"
#include "Boost.h"

using namespace std;

class Student_Mullayarov
{
    friend class boost::serialization::access;
protected:
    string name,surname;
    double mark;
    int age;
public:
    Student_Mullayarov();
    virtual void showStudent(ostream& out);
    virtual void createStudent(istream& in);
    virtual ~Student_Mullayarov();
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& name;
        ar& surname;
        ar& age;
        ar& mark;
    }
};



