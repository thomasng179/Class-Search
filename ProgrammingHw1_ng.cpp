/*
 10017331, Thomas Ng
 9/20/22
 Programming Hw1, Probem 1
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "course.h"
#include "student.h"

using namespace std;

Course* setFileArray(int numCourses, Course* temp, Course* course);
void printAll(Course* course, int numCourses);
void showMenu(Course* course, int numCourses);
void listStudentsWhoTakeAll(Course* course, int numCourses);
void listStudentsWhoTakeTwo(Course* course);
int main() {
    int numCourses;
    cout << "Enter the number of courses: " << '\n';
    cin >> numCourses;
    
    //initialize array of classes from file in heap
    Course* temp = new Course[numCourses];
    //create pointer to point to dynamic array in heap
    Course* course = temp;
    //ask for file names and set them in the array
    setFileArray(numCourses, temp, course);

    //printAll(course, numCourses);
    showMenu(course, numCourses);

    delete[] temp;
    system("pause");
    return 0;
}

