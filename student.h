//
//  student.hpp
//  ProgrammingHw1_ng
//
//  Created by Thomas Ng on 10/5/22.
//
#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Student {
private:
    int studentID;
    std::string name;
    int score;
public:
    void setInfo(std::string fileName, int num);
    int getStudentID();
    std::string getName();
    int getScore();
    friend std::istream& operator>> (std::istream&, Student&);
    friend std::ostream& operator<< (std::ostream&, Student&);
    friend void topScores(int numCourses);
    Student();
};


#endif /* student_hpp */
