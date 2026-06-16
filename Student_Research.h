/*
 * Student_Research.h
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this defines the derived class Student_Research which inherits from Student
 *          contains a Research object (composition) and overrides reportGrade()
 *
 * Assumptions: the enrolment type is always 'R' for research students
 */

#ifndef STUDENT_RESEARCH_H_
#define STUDENT_RESEARCH_H_

#include "Student.h"
#include "Research.h"
#include <string>
using namespace std;

class Student_Research : public Student {
private:
    Research research;

public:
    Student_Research(); //default constructor
    //parameterized constructor
    Student_Research(string fName, string lName, long id,
                     double pMark, double dMark);

    const Research& getResearch() const;

    void setResearch(Research r);

    void reportGrade() const override;

    //method isCoursework
    bool isCoursework() const override {
    	return false;
    }
};

#endif /* STUDENT_RESEARCH_H_ */
