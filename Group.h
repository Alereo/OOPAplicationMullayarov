#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Student_Mullayarov;
class Group_Mullayarov
{
private:
	vector<Student_Mullayarov*> students;
public:
	Group_Mullayarov();
	void printFileGroup();
	void readFileGroup();
	void deleteGroup();
	void printStudents();
	void addStudents();
};

