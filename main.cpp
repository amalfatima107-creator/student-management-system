/*
 * main.cpp
 *
 * Title: ICT167 Assignment 2 - Student Management System
 * Author: Amal Fatima Bhatti
 * Student ID: 35733697
 * Date: 4 April 2026
 *
 * Purpose: this is the client program that loads students from CSV file, provides a menu
 *          with 7 options: quit, remove student, display all, coursework average
 *          analysis, find by ID, sort by ID (insertion sort), export to CSV
 *
 * Assumptions: CSV format: C or R followed by appropriate fields
 *              input file name is "student.csv" in the same directory
 *              student IDs are unique positive long integers
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Student.h"
#include "Student_Course.h"
#include "Student_Research.h"

using namespace std;


void StudentInfo() {
	cout << "ICT167: Principles of Computer Science" << endl;
	cout << "Assignment 2" << endl;
	cout << "Name: Amal Fatima" << endl;
	cout << "Student number: 35733697" << endl;
	cout << "Mode: External" << endl;
	cout << "Tutor: Sameena Javaid" << endl;
	cout << "Tutorial day/time: 4th April, Saturday" << endl;

}

string toLowercase(string text) { //for all uppercase values
    string result = text;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result[i] = text[i] + 32;
        }
        else {
            result[i] = text[i];
        }
    }
    return result;
}

string capFirstChar(string name) {
    if (name.empty()) return name;
    name = toLowercase(name);  // make all lowercase first
    name[0] = toupper(name[0]); // capitalize first letter
    return name;
}

//function to load students from CSV
vector<Student*> loadStudents(string filename) {
    vector<Student*> students;
    ifstream file(filename);

    if (!file.is_open()) { //check for file opening error and display message
        cout << "Error: Could not open file! " << filename << endl;
        return students;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, ','); //reads until a comma

        if (type == "C" || type == "c") {
            //parse coursework student
            string firstName, lastName, unitID; //grouped all by type
            long id;
            int level;
            double a1, a2, a3, a4, exam;

            getline(ss, firstName, ',');
            getline(ss, lastName, ',');
            firstName = capFirstChar(firstName);
            lastName = capFirstChar(lastName);
            ss >> id; //leaving comma behind
            ss.ignore(); // skip comma, move to next
            getline(ss, unitID, ',');
            ss >> level;
            ss.ignore();
            ss >> a1;
            ss.ignore();
            ss >> a2;
            ss.ignore();
            ss >> a3;
            ss.ignore();
            ss >> a4;
            ss.ignore();
            ss >> exam;

            //creates Student_Course object with all data just read above
            Student_Course* sPtr = new Student_Course(firstName, lastName, id,
                                unitID, level, a1, a2, a3, a4, exam);

            //check for duplicate ID
            bool duplicate = false;
            for (Student* existing : students) {
                if (existing->getStudentID() == id) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                cout << "Warning: Duplicate ID " << id << " for " << firstName << " " << lastName << ". Skipping." << endl;
                delete sPtr; // free memory
            } else {
                students.push_back(sPtr); //adds the pointer to the vector
            }
        }
        else if (type == "R" || type == "r") { //if student is in the research category
            //parses research student
            string firstName, lastName;  //declared all var for research fields
            long id;
            double proposal, dissertation;

            getline(ss, firstName, ','); //reads first name & last name
            getline(ss, lastName, ',');
            firstName = capFirstChar(firstName);
            lastName = capFirstChar(lastName);
            ss >> id; //reads the id & skips comma
            ss.ignore();
            ss >> proposal; //reads the proposal & dissertation
            ss.ignore();
            ss >> dissertation;

            //creates a new Student_Research object with all data just read above
            Student_Research* sPtr = new Student_Research(firstName, lastName, id,
                                                        proposal, dissertation);

            //check for duplicate ID
            bool duplicate = false;
            for (Student* existing : students) {
                if (existing->getStudentID() == id) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                cout << "Warning: Duplicate ID " << id << " for " << firstName << " " << lastName << ". Skipping." << endl;
                delete sPtr; // free memory
            } else {
                students.push_back(sPtr); //adds the pointer to the vector
            }
        }//closing if else
        else {
            cout << "\nWarning: Invalid type '" << type << "' on line: " << line << endl;
        } //handles invalid type with a warning
    } //closing while loop

    file.close(); //closes file and returns the vector of the students
    return students;
}

int main() { //here the main starts
	StudentInfo();

    vector<Student*> students = loadStudents("student.csv"); //students vector reading&storing the csv file we created

    //separating coursework and research
    vector<Student*> coursework;
    vector<Student*> research;

    for (Student* s : students) { // for each pointer s in vector students check for coursework students
        if (s->isCoursework()) {
            coursework.push_back(s);
        } else {
            research.push_back(s);
        }
    }

    //combining with coursework first, then research
    students.clear();
    students.insert(students.end(), coursework.begin(), coursework.end());
    students.insert(students.end(), research.begin(), research.end());

    int choice;
    do {
    	cout <<"\nMENU OPTIONS" << endl;
    	cout << "1. Quit" << endl;
    	cout << "2. Remove student by ID" << endl;
    	cout << "3. Display all students" << endl;
    	cout << "4. Coursework average analysis" << endl;
    	cout << "5. Find student by ID" << endl;
    	cout << "6. Sort by ID" << endl;
    	cout << "7. Export to CSV"  << endl;
    	cout << "Please select an option:";
    	cin >> choice;

    	if (cin.fail()) { //checks in user typed out of range input
    		cin.clear(); //clears input
    		cin.ignore(1000, '\n'); //discard upto 1000 chars or until newline
    		cout << "Invalid input. Please enter a number." << endl;
    		continue; //skips rest of loop & starts next iteration
    	}

    	switch (choice) {
    	case 1: //user exits program
    		cout << "\nExiting program. Goodbye!" << endl;
    		break;
    	case 2: {    //removes student by id (variables declared)
    	    long id;
    	    cout << "\nEnter student ID to remove: ";
    	    cin >> id;

    	    if (cin.fail()) { //checks in user typed out of range input
    	        cin.clear(); //clears users input
    	        cin.ignore(1000, '\n');
    	        cout << "Invalid input." << endl;
    	        break; //exits the switch case & goes back to menu
    	    }

    	    bool found = false; //creatiing a flag to know if we found student, initially set at false
    	    for (size_t i = 0; i < students.size(); i++) { //loop through the vector using size_t for vector indexes
    	        if (students[i]->getStudentID() == id) { //check if current id matches the one user entered.
    	            found = true; //if found, found is set to true from false.

    	            //show student and ask for confirmation
    	            cout << "Are you sure you want to remove this student: ";
    	            students[i]->reportGrade(); //follows pointer to the actual student obj
    	            cout << "(y/n): ";
    	            char confirm;  //char var confirm to store the user answer
    	            cin >> confirm; //waits for user to tyoe a letter (y/n) & store in confirm

    	            if (confirm == 'y' || confirm == 'Y') {
    	                delete students[i];               //free memory by getting rid of data at index i
    	                students.erase(students.begin() + i);  //remove from vector by moving iterator forward by i positions from 0
    	                cout << "Student has been removed." << endl;
    	            } else {
    	                cout << "Removal has been cancelled." << endl;
    	            }
    	            break;
    	        }
    	    }

    	    if (!found) {
    	        cout << "\nStudent with ID " << id << " not found." << endl;
    	    }
    	    break;
    	}
    	case 3:
    	    //display all students to test
	        cout << endl;
    	    for (Student* sPtr : students) { //loop thro each student & call reportGrade method
    	        cout << "Student: ";
    	        sPtr->reportGrade();
    	        cout << endl;
    	    }
    	    break;


    	case 4: { //coursework students above, avg and below.
    	    double totalOverallMark = 0;
    	    int courseCount = 0;  // initialize to 0

    	    //add all coursework overall marks
    	    for (Student* s : students) { //loop thro every student popinter
    	        if (s->isCoursework()) { //check if student is C
    	            Student_Course* sc = dynamic_cast<Student_Course*>(s); //convert student ptr to student_course ptr (to access C methods)
    	            totalOverallMark += sc->getUnit().getOverallMark(); //gets overall mark frm unit_course object, adding all one by one to total
    	            courseCount++; //also counts how many C students
    	        }
    	    }

    	    if (courseCount == 0) {
    	        cout << "No coursework students found." << endl;
    	        break;
    	    }

    	    double Avg = totalOverallMark / courseCount; //counts avg by div-ing total marks by no of C students

    	    int aboveAvg = 0; //set counters to 0
    	    int belowAvg = 0;
    	    for (Student* s : students) { //loop through all students agian
    	        if (s->isCoursework()) { //if students are student_course objects or C students
    	            Student_Course* sc = dynamic_cast<Student_Course*>(s); //convert student ptr to student_course ptr (to access C methods)
    	            if (sc->getUnit().getOverallMark() >= Avg) //if mark is more than or = to avg.
    	                aboveAvg++; //increase aboveAvg counter
    	            else //otherwise mask < avg
    	                belowAvg++; //increase belowAvg counter
    	        }
    	    }

    	    //display all results
    	    cout << "\nCoursework Student's Mark Analysis:" << endl;
    	    cout << "Total students: " << courseCount << endl;
    	    cout << "Average overall mark: " << Avg << endl;
    	    cout << "Above or equal to average: " << aboveAvg << endl;
    	    cout << "Below average: " << belowAvg << endl;
    	    break;
    	}

    	case 5: { //finding student by ID
    	    long id;
    	    cout << "Enter student ID to find: ";
    	    cin >> id;

    	    bool found = false; //initializing flag to false
    	    for (Student* sPtr : students) { //points and loops thro all student objects
    	        if (sPtr->getStudentID() == id) { //each ptr gets studentID and matches it to user entered ID
    	            cout << "Student found: "; //if matched, student has been found
    	            sPtr->reportGrade(); // ptr uses reportGrade to display student's info
    	            cout << endl;
    	            found = true; //flag is set to true
    	            break; //exits loop
    	        }
    	    }

    	    if (!found) { //but if flag is still false, display message
    	        cout << "Student with ID " << id << " not found." << endl;
    	    }
    	    break;
    	}

    	case 6: {
    	    // insertion sort by student ID
    	    for (size_t i = 1; i < students.size(); i++) { //starts loop from 2nd index to last
    	        Student* key = students[i]; //saves current objectin key
    	        long keyID = key->getStudentID(); //saves the current obj's ID for comparison

    	        size_t j = i;  //starts j at current position
    	        while (j > 0 && students[j-1]->getStudentID() > keyID) { //while theres stuent to the left & their ID is bigger than keyID
    	            students[j] = students[j-1]; //moves the bigger student 1 position to the right
    	            j--; //moves the left to check next student
    	        }
    	        students[j] = key; //places the key student in its correct sorted position
    	    }

    	    cout << "\nStudents are sorted by ID (ascending order).\n" << endl;

    	    //displays the sorted list
    	    for (Student* sPtr : students) {
    	        cout << "Student: ";
    	        sPtr->reportGrade();
    	        cout << endl;
    	    }
    	    break;
    	}

    	case 7: {
    	    ofstream outFile("sorted_students.csv");
    	    //first we create an output file stream & open sprted stdents csv for writing

    	    for (Student* sPtr : students) {
    	        if (sPtr->isCoursework()) {
    	            Student_Course* sc = dynamic_cast<Student_Course*>(sPtr);
    	            outFile << "C," << sc->getFirstName() << "," << sc->getLastName() << "," //write csv for the C studentd
    	                    << sc->getStudentID() << "," << sc->getUnit().getUnitID() << ","
    	                    << sc->getUnit().getOverallMark() << "," << sc->getUnit().getFinalGrade() << endl;
    	        } else {
    	            Student_Research* sr = dynamic_cast<Student_Research*>(sPtr);
    	            outFile << "R," << sr->getFirstName() << "," << sr->getLastName() << "," //write csv for R students
    	                    << sr->getStudentID() << "," << sr->getResearch().getOverallMark() << ","
    	                    << sr->getResearch().getFinalGrade() << endl;
    	        }
    	    }

    	    outFile.close(); //close file anf tell the user thatits done!
    	    cout << "\nStudents exported to sorted_students.csv" << endl;
    	    break;
    	}

    	default:
    	    cout << "Option not implemented yet." << endl;
    	    break;
    	}
    } while (choice != 1); //until choice is 1

    // Clean up memory
    for (Student* sPtr : students) { //loop thro all students and deletes them to free memory
        delete sPtr;
    }

    return 0;
}


