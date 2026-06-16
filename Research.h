/*
 * Research.h
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this defines derived class Research which inherits from Unit
 *          contains proposalMark, dissertationMark, overallMark, finalGrade,
 *          and methods to calculate them
 *
 * Assumptions: proposal is worth 40%, dissertation is worth 60% of overall mark
 *              both marks are out of 100
 */

#ifndef RESEARCH_H_
#define RESEARCH_H_

#include "Unit.h"
#include <string>
using namespace std;

class Research : public Unit {

private:
	double proposalMark;      //proposal mark out of 100 (worth 40%)
	double dissertationMark;  //dissertation mark out of 100 (worth 60%)
	double overallMark;       //calculated overall mark
	string finalGrade;        //final grade (HD,D,C,P,N)

public:
	Research(); //default constructor

	Research(double pMark, double dMark); //parameterized constructor

//Accessors
	double getProposalMark() const;
	double getDissertationMark() const;
	double getOverallMark() const;
	string getFinalGrade() const;

//Mutators
	void setProposalMark(double pMark);
	void setDissertationMark(double dMark);
	void setOverallMark(double totalMark);
	void setFinalGrade(string grade);

//Method calcOverallMark
	void calcOverallMark(); //overall = (proposal * 0.4) + (dissertation * 0.6)

//Method calcFinalGrade
	void calcFinalGrade();  //determines HD/D/C/P/N from overall mark

	//Method reportGrade
	void reportGrade() const override;

};

#endif /* RESEARCH_H_ */
