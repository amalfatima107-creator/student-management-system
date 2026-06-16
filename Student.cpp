/*
 * Student.cpp
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: to implement the Student class methods including constructors,
 *          getters, setters, equals() and reportGrade().
 *
 * Assumptions: none.
 */

#include "Student.h"
#include <iostream>
#include <string> // for string class
using namespace std;

//default constructor
Student::Student() {
	firstName = "";
	lastName = "";
	studentID = 0;
}

//constructor with parameter
Student::Student(string fName, string lName, long sID) {
	firstName = fName;
	lastName = lName;
	studentID = sID;
}

//Accessors
string Student::getFirstName() const {
	return firstName;
}

string Student::getLastName() const {
	return lastName;
}

long Student::getStudentID() const {
	return studentID;
}

//Mutators
void Student::setFirstName(string fName) {
	firstName = fName;
}

void Student::setLastName(string lName) {
	lastName = lName;
}

void Student::setStudentID(long sID) {
	studentID = sID;
}

//Method Equalss
bool Student::equals(const Student& other) const {
	return (studentID == other.studentID);
}

//Method reportGrade
void Student::reportGrade() const {
	cout << "There is no grade here!" << endl;
}

Student::~Student() { //for virtual desctructor warning
}


















