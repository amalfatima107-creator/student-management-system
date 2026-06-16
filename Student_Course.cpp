/*
 * Student_Course.cpp
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this implements Student_Course methods including constructor,
 *          getUnit(), and overridden reportGrade()
 *
 * Assumptions: none
 */

#include "Student_Course.h"
#include <iostream>
using namespace std;


//default constructor
Student_Course::Student_Course() : Student() {
}

//parameterized constructor
Student_Course::Student_Course(string fName, string lName, long id,
                               string uID, int level, double a1, double a2, double a3, double a4, double exam)
    : Student(fName, lName, id), unit(uID, level, a1, a2, a3, a4, exam) {
	 unit.calcOverallMark();
	 unit.calcFinalGrade();
}

//Accessor
const Unit_Course& Student_Course::getUnit() const {
    return unit;
}


// method reportGrade overridden
void Student_Course::reportGrade() const {
    cout << getUnit().getEnrolmentType() << " " << getFirstName() << " " << getLastName() << " "
         << getStudentID() << " " << getUnit().getUnitID() << " "
         << getUnit().getOverallMark() << " " << getUnit().getFinalGrade() << endl;
}


