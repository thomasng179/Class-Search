#pragma once
#include "student.h"
#include <string>

struct Course {
    std::string course;
    int numStudents;
    Student* student;
};