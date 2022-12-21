//
//  student.cpp
//  ProgrammingHw1_ng
//
//  Created by Thomas Ng on 10/5/22.
//

#include "course.h"
#include <iostream>
#include <string>
#include <string>
#include <fstream>

using namespace std;

Student::Student() {
    score = 0;
    studentID = 0;
};

//use the setInfo function to set the class array
void Student::setInfo(string fileName, int num) {
    ifstream inFile;
    string trash;
    int trash1;
    inFile.open(fileName);
    inFile >> trash >> trash1;
    for (int j = 0; j < num; j++) {
        inFile >> this[j].studentID >> this[j].name >> this[j].score;
    }

    inFile.close();
}

int Student::getStudentID() {
    return studentID;
}

string Student::getName() {
    return name;
}

int Student::getScore() {
    return score;
}
