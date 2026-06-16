/*
 * Unit_Course.h
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this defines derived class Unit_Course which inherits from Unit
 *          contains unitID, level, 4 assignments (vector), final exam,
 *          overallMark, finalGrade, and methods to calculate them
 *
 * Assumptions: assignments are out of 100, equally weighted (15% each)
 *              final exam is out of 100 (40% of overall mark)
 */

#ifndef UNIT_COURSE_H_
#define UNIT_COURSE_H_

#include "Unit.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Unit_Course : public Unit { //derived class defination
private:
	string unitID;
	int unitLevel;
	vector<double> assignmentMarks;
	double finalExam;
	double overallMark; //calc
	string finalGrade; //calc


public:
//default constructor
	Unit_Course();

//Parameterizsed constructor
	Unit_Course(string uID, int unitLvl, double a1, double a2, double a3,
			double a4, double fExam);

//Accesors
	string getUnitID() const;
	int getUnitLevel() const;
	double getAssignmentMarks(int index) const; //get specific assignment mark
	double getFinalExam() const;
	double getOverallMark() const;
	string getFinalGrade() const;

//Mutators
	void setUnitID(string uID);
	void setUnitLevel(int unitLvl);
	void setAssignment(int index, double mark); //sets mark at that index
	void setFinalExam(double fExam);
	void setOverallMark(double Totalmark);
	void setFinalGrade(string fGrade);

//Methods
void calcOverallMark(); //calculates weighted average (60% assignments, 40% exam)
void calcFinalGrade();  //determines HD/D/C/P/N from overall mark
void reportGrade() const override; //displays unit info

};

#endif /* UNIT_COURSE_H_ */
