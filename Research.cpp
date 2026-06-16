/*
 * Research.cpp
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this implements Research methods including constructors with validation,
 *          getters/setters, calcOverallMark(), calcFinalGrade(), and reportGrade()
 *
 * Assumptions: marks are validated between 0-100, invalid marks set to 0
 */

#include "Research.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Research::Research() : Unit('R') {
    proposalMark = 0;
    dissertationMark = 0;
    overallMark = 0;
    finalGrade = "";
}

//Parameterizsed constructor
Research::Research(double pMark, double dMark) : Unit('R') {
    if (pMark >= 0 && pMark <= 100) {
        proposalMark = pMark;
    } else {
        proposalMark = 0;
    }

    if (dMark >= 0 && dMark <= 100) {
        dissertationMark = dMark;
    } else {
        dissertationMark = 0;
    }

	overallMark = 0; //will be calc later on
	finalGrade = ""; //will be calc later oon
}

//Accessor
double Research::getProposalMark() const {
	return proposalMark;
}

double Research::getDissertationMark() const {
	return dissertationMark;
}

double Research::getOverallMark() const {
	return overallMark;
}

string Research::getFinalGrade() const {
	return finalGrade;
}

//Mutator
void Research::setProposalMark(double pMark) {
	proposalMark = pMark;
}

void Research::setDissertationMark(double dMark) {
	dissertationMark = dMark;
}

void Research::setOverallMark(double totalMark) {
	overallMark = totalMark;
}

void Research::setFinalGrade(string grade) {
	finalGrade = grade;
}

//Method calcOverallMark - calculates overall mark: proposal 40%, dissertation 60%
void Research::calcOverallMark() {
		overallMark = (proposalMark*0.4) + (dissertationMark*0.6);
}

//Method calcFinalGrade - determines final grade from overall mark using thresholds
void Research::calcFinalGrade() {
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

//Method reportGrade overridden, displays research student info
void Research::reportGrade() const {
    cout << "R " << getProposalMark() << " " << getDissertationMark()
         << " " << getOverallMark() << " " << getFinalGrade() << endl;
}







