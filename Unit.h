/*
 * Unit.h
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this defines the base class Unit with enrolmentType attribute,
 *          constructors, getter/setter, and virtual reportGrade()
 *
 * Assumptions:: enrolment type is 'C' for coursework or 'R' for research
 */

#ifndef UNIT_H_
#define UNIT_H_


#include <iostream>
using namespace std;

class Unit {
private:
	char enrolmentType;

public:
	//default constructor
	Unit();

	//constructor parameterized
	Unit(char enrolmentType);	// C for course, R for research


//Accessors - to access value
	char getEnrolmentType() const;

//Mutator - to modify value
	void setEnrolmentType(char type);

//method reportGrade
	virtual void reportGrade() const;

};

#endif /* UNIT_H_ */
