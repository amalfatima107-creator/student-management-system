/*
 * Student_Research.cpp
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this implements Student_Research methods including constructor,
 *          getResearch(), and overridden reportGrade()
 *
 * Assumptions: none
 */

#include "Student_Research.h"
#include <iostream>
using namespace std;

//default constructor
Student_Research::Student_Research() : Student() {
}

//parameterized constructor
Student_Research::Student_Research(string fName, string lName, long id,
     double pMark, double dMark) : Student(fName, lName, id), research(pMark, dMark) {
    research.calcOverallMark(); //calculates overall mark from proposal and dissertation
    research.calcFinalGrade(); //calculates final grade (HD,D,C,P,N)
}

//ACCESSOR
const Research& Student_Research::getResearch() const {
    return research;
}

//MUTATOR
void Student_Research::setResearch(Research r) {
    research = r;
}

//overridden reportGrade method - prints research student info
void Student_Research::reportGrade() const {
    cout << research.getEnrolmentType() << " " << getFirstName() << " " << getLastName()
         << " " << getStudentID() << " " << research.getOverallMark() << " "
         << research.getFinalGrade() << endl;
}


