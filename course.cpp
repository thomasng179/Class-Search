#include "course.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

//open file and input the file data into array in heap. then have course point to it
Course* setFileArray(int numCourses, Course* temp, Course* course) {
    string fileName;
    ifstream inFile;
    for (int i = 0; i < numCourses; i++) {
        cout << "Enter file name " << i + 1 << ": " << '\n';
        cin >> fileName;
        inFile.open(fileName);
        inFile >> temp[i].course >> temp[i].numStudents;
        inFile.close();
        Student* tempStudentArray = new Student[temp[i].numStudents];
        tempStudentArray->setInfo(fileName, temp[i].numStudents);

        temp[i].student = tempStudentArray;
        course = temp;
    }

    return course;
}

//print all the courses
void printAll(Course* course, int numCourses) {
    for (int i = 0; i < numCourses; i++) {
        cout << "Course : " << course[i].course << '\n' << "---------------------------" << '\n';
        for (int j = 0; j < course[i].numStudents; j++) {
            cout << course[i].student[j].getStudentID() << setw(15) << course[i].student[j].getName() << setw(15) << course[i].student[j].getScore() << endl;
        }
    }
}

//list all the students who are taking all the courses by looping through all of them
void listStudentsWhoTakeAll(Course* course, int numCourses) {
    int count = 0;
    int studentID[20], studentScore[20], studentScore2[20], studentScore3[20];
    string name[20];

    //loop through all the classes and store them in an array to print later
    for (int j = 0; j < course[0].numStudents; j++) {
        for (int k = 0; k < course[1].numStudents; k++) {
            for (int i = 0; i < course[2].numStudents; i++) {
                if (course[0].student[j].getStudentID() == course[1].student[k].getStudentID() && course[0].student[j].getStudentID() == course[2].student[i].getStudentID()) {
                    studentID[count] = course[0].student[j].getStudentID();
                    studentScore[count] = course[0].student[j].getScore();
                    studentScore2[count] = course[1].student[k].getScore();
                    studentScore3[count] = course[2].student[i].getScore();
                    name[count] = course[0].student[j].getName();
                    count++;
                }
            }
        }
    }

    cout << "There are " << count << " students who take all 3 courses" << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << studentID[i] << setw(10) << name[i] << " " << course[0].course << "(" << studentScore[i] << ") " << course[1].course << "(" << studentScore2[i] << ") " << course[2].course << "(" << studentScore3[i] << ")" << '\n';
    }
} 

//list all the students who are taking at least 2 classes by looping through them to find the same student ID
void listStudentsWhoTakeTwo(Course* course) {
    int count = 0;
    int studentID[20], studentScore[20], studentScore2[20];
    string name[20];
    
    //first class loop
    for (int j = 0; j < course[0].numStudents; j++) {
        for (int k = 0; k < course[1].numStudents; k++) {
            for (int i = 0; i < course[2].numStudents; i++) {
                if (course[0].student[j].getStudentID() == course[2].student[i].getStudentID()) {
                    break;
                } else if (course[0].student[j].getStudentID() == course[1].student[k].getStudentID() && i == course[2].numStudents - 1) {
                    studentID[count] = course[0].student[j].getStudentID();
                    studentScore[count] = course[0].student[j].getScore();
                    studentScore2[count] = course[1].student[k].getScore();
                    name[count] = course[0].student[j].getName();
                    count++;
                }
            }
        }
    }

    cout << "There are " << count << " students who take " << course[0].course << " and " << course[1].course << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << studentID[i] << setw(10) << name[i] << " " << course[0].course << "(" << studentScore[i] << ") " << course[1].course << "(" << studentScore2[i] << ")" << '\n';
    }
    
    //second class loop
    count = 0;
    for (int j = 0; j < course[0].numStudents; j++) {
        for (int i = 0; i < course[2].numStudents; i++) {
            for (int k = 0; k < course[1].numStudents; k++) {
                if (course[0].student[j].getStudentID() == course[1].student[k].getStudentID()) {
                    break;
                }
                else if (course[0].student[j].getStudentID() == course[2].student[i].getStudentID() && k == course[1].numStudents - 1) {
                    studentID[count] = course[0].student[j].getStudentID();
                    studentScore[count] = course[0].student[j].getScore();
                    studentScore2[count] = course[2].student[i].getScore();
                    name[count] = course[0].student[j].getName();
                    count++;
                }
            }
        }
    }

    cout << "There are " << count << " students who take " << course[0].course << " and " << course[2].course << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << studentID[i] << setw(10) << name[i] << " " << course[0].course << "(" << studentScore[i] << ") " << course[2].course << "(" << studentScore2[i] << ")" << '\n';
    }

    //third class loop
    count = 0;
    for (int j = 0; j < course[1].numStudents; j++) {
        for (int k = 0; k < course[2].numStudents; k++) {
            for (int i = 0; i < course[0].numStudents; i++) {
                if (course[1].student[j].getStudentID() == course[0].student[i].getStudentID()) {
                    break;
                }
                else if (course[1].student[j].getStudentID() == course[2].student[k].getStudentID() && i == course[0].numStudents - 1) {
                    studentID[count] = course[1].student[j].getStudentID();
                    studentScore[count] = course[1].student[j].getScore();
                    studentScore2[count] = course[2].student[k].getScore();
                    name[count] = course[1].student[j].getName();
                    count++;
                }
            }
        }
    }

    cout << "There are " << count << " students who take " << course[1].course << " and " << course[2].course << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << studentID[i] << setw(10) << name[i] << " " << course[1].course << "(" << studentScore[i] << ") " << course[2].course << "(" << studentScore2[i] << ")" << '\n';
    }
}

//sort all the students in the classes and print out the top 3 scores from each one
void topScores(Course* course, int numCourses) {
    Student temp;
    int k = 0, j = 0, l = 0;

    //sort the array from least to greatest
    for (int i = 0; i < course[0].numStudents; i++) {
        for (int j = 0; j < course[0].numStudents; j++) {
            if (course[0].student[i].getScore() < course[0].student[j].getScore()) {
                temp = course[0].student[i];
                course[0].student[i] = course[0].student[j];
                course[0].student[j] = temp;
            }
        }
    }

    for (int i = 0; i < course[1].numStudents; i++) {
        for (int j = 0; j < course[1].numStudents; j++) {
            if (course[1].student[i].getScore() < course[1].student[j].getScore()) {
                temp = course[1].student[i];
                course[1].student[i] = course[1].student[j];
                course[1].student[j] = temp;
            }
        }
    }

    for (int i = 0; i < course[2].numStudents; i++) {
        for (int j = 0; j < course[2].numStudents; j++) {
            if (course[2].student[i].getScore() < course[2].student[j].getScore()) {
                temp = course[2].student[i];
                course[2].student[i] = course[2].student[j];
                course[2].student[j] = temp;
            }
        }
    }
    
    //print out the arrays from greatest to least and use while loop to print out the same scores
    cout << "{ " << course[0].course << " Top Three Scores }" << endl;
    int iter = 0;
    int i = course[0].numStudents - 1;
    while (iter < 3) {
        if (course[0].student[i].getScore() == course[0].student[i - 1].getScore()) {
            cout << k + 1 << ". " << course[0].student[i].getScore() << endl;
            while (course[0].student[i].getScore() == course[0].student[i - 1].getScore()) {
                cout << course[0].student[i].getStudentID() << setw(10) << course[0].student[i].getName() << endl;
                i--;
            }
            cout << course[0].student[i].getStudentID() << setw(10) << course[0].student[i].getName() << endl;
            i--;
            k++;
            iter++;
        } else {
            cout << k + 1 << ". " << course[0].student[i].getScore() << endl;
            cout << course[0].student[i].getStudentID() << setw(10) << course[0].student[i].getName() << endl;
            k++;
            i--;
            iter++;
        }
    }
    cout << endl;

    //same as above
    cout << "{ " << course[1].course << " Top Three Scores }" << endl;
    iter = 0;
    i = course[1].numStudents - 1;
    while (iter < 3) {
        if (course[1].student[i].getScore() == course[1].student[i - 1].getScore()) {
            cout << j + 1 << ". " << course[1].student[i].getScore() << endl;
            while (course[1].student[i].getScore() == course[1].student[i - 1].getScore()) {
                cout << course[1].student[i].getStudentID() << setw(10) << course[1].student[i].getName() << endl;
                i--;
            }
            cout << course[1].student[i].getStudentID() << setw(10) << course[1].student[i].getName() << endl;
            i--;
            j++;
            iter++;
        } else {
            cout << j + 1 << ". " << course[1].student[i].getScore() << endl;
            cout << course[1].student[i].getStudentID() << setw(10) << course[1].student[i].getName() << endl;
            j++;
            i--;
            iter++;
        }
    }
    cout << endl;

    //same as above
    cout << "{ " << course[2].course << " Top Three Scores }" << endl;
    iter = 0;
    i = course[2].numStudents - 1;
    while (iter < 3) {
        if (course[2].student[i].getScore() == course[2].student[i - 1].getScore()) {
            cout << l + 1 << ". " << course[2].student[i].getScore() << endl;
            while (course[2].student[i].getScore() == course[2].student[i - 1].getScore()) {
                cout << course[2].student[i].getStudentID() << setw(10) << course[2].student[i].getName() << endl;
                i--;
            }
            cout << course[2].student[i].getStudentID() << setw(10) << course[2].student[i].getName() << endl;
            i--;
            l++;
            iter++;
        } else {
            cout << l + 1 << ". " << course[2].student[i].getScore() << endl;
            cout << course[2].student[i].getStudentID() << setw(10) << course[2].student[i].getName() << endl;
            l++;
            i--;
            iter++;
        }
    }
}

//print out the menu by using a do while loop and using switch statements to select the options
void showMenu(Course* course, int numCourses) {
    int input = 6;
    do {
        cout << "1. Show all course lists" << endl;
        cout << "2. List of students who take all courses" << endl;
        cout << "3. List of students who take two courses" << endl;
        cout << "4. Print out top three scores for each course" << endl;
        cout << "0. Exit" << endl;
        cout << "---> select : ";
        cin >> input;
        
        switch (input) {
        case 1:
            printAll(course, numCourses);
            break;
        case 2:
            listStudentsWhoTakeAll(course, numCourses);
            break;
        case 3:
            listStudentsWhoTakeTwo(course);
            break;
        case 4:
            topScores(course, numCourses);
            break;
        }
    } while (input != 0);
}

istream& operator>> (istream& input, Student& student) {
    input >> student.studentID >> student.name >> student.score;
    return input;
}

ostream& operator<< (ostream& output, Student& student) {
    output << student.studentID << student.name << student.score;
    return output;
}

