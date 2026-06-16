/*
 * Unit_Course.cpp
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this implements Unit_Course methods including constructors with validation,
 *          getters/setters, calcOverallMark(), calcFinalGrade(), and reportGrade()
 *
 * Assumptions: thee marks are validated between 0-100, invalid marks set to 0
 */

#include "Unit_Course.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor- sets everything to empty/zero
Unit_Course::Unit_Course() : Unit('C') {
    unitID = "";
    unitLevel = 0;
    assignmentMarks.resize(4);
    for (int i = 0; i < 4; i++) assignmentMarks[i] = 0;
    finalExam = 0;
    overallMark = 0;
    finalGrade = "";
}

//Parameterizsed constructor- copies values and validates marks
Unit_Course::Unit_Course(string uID, int unitLvl, double a1, double a2, double a3,
		double a4, double fExam) : Unit('C') {
	unitID = uID; //copy para to instance var
	unitLevel = unitLvl;
	assignmentMarks.resize(4); //make space for 4 assignments

    // Validate assignment marks (0-100)
    if (a1 >= 0 && a1 <= 100)
        assignmentMarks[0] = a1;
    else
        assignmentMarks[0] = 0;

    if (a2 >= 0 && a2 <= 100)
        assignmentMarks[1] = a2;
    else
        assignmentMarks[1] = 0;

    if (a3 >= 0 && a3 <= 100)
        assignmentMarks[2] = a3;
    else
        assignmentMarks[2] = 0;

    if (a4 >= 0 && a4 <= 100)
        assignmentMarks[3] = a4;
    else
        assignmentMarks[3] = 0;

    // Validate final exam (0-100)
    if (fExam >= 0 && fExam <= 100)
        finalExam = fExam;
    else
        finalExam = 0;

    overallMark = 0; //both will be calculaed later
    finalGrade = "";
}

//Accessors
string Unit_Course::getUnitID() const {
	return unitID;
}

int Unit_Course::getUnitLevel() const {
	return unitLevel;
}

//Accessor for a specific assignment mark by index
double Unit_Course::getAssignmentMarks(int index) const{
	if (index >= 0 && index < 4){
		return assignmentMarks[index];
	}
	return -1; //erorr value if index is invalid
}

double Unit_Course::getFinalExam() const {
	return finalExam;
}

double Unit_Course::getOverallMark() const{
	return overallMark;
}

string Unit_Course::getFinalGrade() const {
	return finalGrade;
}


//Mutator
void Unit_Course::setUnitID(string uID){
	unitID = uID;
}

void Unit_Course::setUnitLevel(int unitLvl) {
	unitLevel = unitLvl;
}

//Mutator for a specific assignment mark by index
void Unit_Course::setAssignment(int index, double mark) {
	if (index >=0 && index < 4) {
		assignmentMarks[index] = mark; //set modified value into position index
	}
}

void Unit_Course::setFinalExam(double fExam) {
	finalExam = fExam;
}

void Unit_Course::setOverallMark(double totalMark) {
	overallMark = totalMark;
}

void Unit_Course::setFinalGrade(string fGrade) {
	finalGrade = fGrade;
}

//calculates overall mark: 60% from assignments, 40% from final exam
void Unit_Course::calcOverallMark() {
    double assignmentTotal = 0;
    for (int i = 0; i < 4; i++) {
        assignmentTotal += assignmentMarks[i];
    }
    double assignmentAvg = assignmentTotal / 4;
    overallMark = (assignmentAvg * 0.6) + (finalExam * 0.4);
}

//determines final grade from overall mark using threshold
void Unit_Course::calcFinalGrade() {
	if (overallMark >= 80) {
	    finalGrade = "HD";
	}
    else if (overallMark >= 70) {
        finalGrade = "D";
    }
    else if (overallMark >= 60 ) {
        finalGrade = "C";
    }
    else if (overallMark >= 50) {
        finalGrade = "P";
    }
    else if (overallMark >= 0) {
        finalGrade = "N";
    }
}

//method reportEquals - overridden, displays unit info
void Unit_Course::reportGrade() const{
	cout << "Unit_Course report: \n" << "The overall mark is: " << getOverallMark() << "\n" << "The final grade is: "
			<< getFinalGrade() << endl;

}











