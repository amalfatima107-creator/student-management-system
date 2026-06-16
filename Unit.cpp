/*
 * Unit.cpp
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this implements Unit class methods including constructors,
 *          getEnrolmentType(), setEnrolmentType(), and reportGrade()
 *
 * Assumptions: -
 */

#include "Unit.h"
#include <iostream>
using namespace std;

//default constructor
Unit::Unit(){
	enrolmentType = 'C';
}

//constructor with parameter
Unit::Unit(char type) {
	enrolmentType = type;
}

//Accessors
char Unit::getEnrolmentType() const {
	return enrolmentType;
}

//Mutators
void Unit::setEnrolmentType(char type) {
	enrolmentType = type;
}

//method reportGrade - prints NA
void Unit::reportGrade() const {
	cout << "NA" << endl;
}
