/*
 * Student.h
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: to define the base class Student with private attributes
 *          (firstName, lastName, studentID), constructors, getters/setters,
 *          equals method, and virtual reportGrade method.
 *
 * Assumptions: the Student ID is a unique positive long integer.
 *              names are strings without special characters.
 *              reportGrade() will be ovverridden by the derived classes.
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string> // for string class
using namespace std;

class Student {
private:
	string firstName;
	string lastName;
	long studentID;

public:
	//default constructor
	Student ();
	Student (string fName, string lName, long sID); //constructor parameterized

	//Accessor - to access values
	string getFirstName() const;
	string getLastName() const;
	long getStudentID() const;

	//Mutator - to modify values
	void setFirstName(string fName);
	void setLastName(string lName);
	void setStudentID(long sID);

	//Method equals
	bool equals(const Student& other) const;

	//Method reportGrade
	virtual void reportGrade() const;

	//Mehtod isCourseWork
	virtual bool isCoursework() const {
		return false;
	}

	virtual ~Student();
};

#endif /* STUDENT_H_ */
