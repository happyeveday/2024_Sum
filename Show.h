// By Yang

#ifndef SHOW_H
#define SHOW_H

#include <iostream>
#include <vector>
#include <memory>
#include "Course.h"
#include "User.h"

void showMenu()
{
    std::cout << "Select Identity: " << std::endl;
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. Teacher" << std::endl;
    std::cout << "3. Student" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void adminMenu()
{
    std::cout << "Admin Menu: " << std::endl;
    std::cout << "1. Show All Courses" << std::endl;
    std::cout << "2. Add Course" << std::endl;
    std::cout << "3. Remove Course" << std::endl;
    std::cout << "4. Modify Course" << std::endl;
    std::cout << "5. Logout" << std::endl;
}

void teacherMenu()
{
    std::cout << "Teacher Menu: " << std::endl;
    std::cout << "1. Show My Courses" << std::endl;
    std::cout << "2. Add Student to Course" << std::endl;
    std::cout << "3. Remove Student from Course" << std::endl;
    std::cout << "4. Logout" << std::endl;
}

void studentMenu()
{
    std::cout << "Student Menu: " << std::endl;
    std::cout << "1. Show All Courses" << std::endl;
    std::cout << "2. Enroll in Course" << std::endl;
    std::cout << "3. Drop Course" << std::endl;
    std::cout << "4. Show My Enrolled Courses" << std::endl;
    std::cout << "5. Logout" << std::endl;
}

#endif
