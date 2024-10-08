#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include <vector>
#include "Boost.h"
#include "Student.h"
#include "Head_Student.h"

using namespace std;

class Group_Mullayarov
{
	friend class boost::serialization::access;
	vector<shared_ptr<Student_Mullayarov>> students;
protected:
	
public:
	Group_Mullayarov();
	~Group_Mullayarov();
	void printFileGroup();
	void readFileGroup();
	void deleteGroup();
	void printStudents();
	void addStudents();
	void addStudentsWithPosition();
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& students;
	}
};

