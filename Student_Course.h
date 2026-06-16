/*
 * Student_Course.h
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this defines the derived class Student_Course which inherits from the Student.
 *          also contains a Unit_Course object (a composition) and aslo overrides reportGrade().
 *
 * Assumptions:the enrolment type is always 'C' for coursework students.
 */

#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include "Student.h"
#include "Unit_Course.h"
#include <string>
using namespace std;

class Student_Course : public Student {
private:
    Unit_Course unit;
public:
    Student_Course(); //dafault constructor
    //parameterized constructor
    Student_Course(string fName, string lName, long id,
                   string uID, int level, double a1, double a2, double a3, double a4, double exam);

    const Unit_Course& getUnit() const;

    //METHOD REPORTGRADE
    void reportGrade() const override;

    //Method isCoursework
    bool isCoursework() const override {
    	return true;
    }
};

#endif
