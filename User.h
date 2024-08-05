// By Yang
// Then:Use txt to build a message system
// Then Then:Use MySQL to memory everyone's data

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Course.h"

// Base User
class User
{
public:
    virtual bool login(const std::string &password) = 0;
    virtual ~User() {}
};

// User:Admin
class Admin : public User
{
public:
    // Then: Use Hash or ASCII to Encryption
    bool login(const std::string &password) override
    {
        return password == "root123";
    }

    void addCourse(std::vector<Course> &courses, const Course &course)
    {
        courses.push_back(course);
    }

    void removeCourse(std::vector<Course> &courses, int id)
    {
        courses.erase(std::remove_if(courses.begin(), courses.end(), [id](const Course &c)
                                     { return c.getId() == id; }),
                      courses.end());
    }

    void modifyCourse(std::vector<Course> &courses, int id, const Course &newCourse)
    {
        for (auto &course : courses)
        {
            if (course.getId() == id)
            {
                course = newCourse;
                break;
            }
        }
    }
};

// User:Teacher
class Teacher : public User
{
public:
    // Then: Use Hash or ASCII to Encryption
    bool login(const std::string &password) override
    {
        return password == "teacher123";
    }

    void addStudentToCourse(Course &course, const std::string &studentId)
    {
        course.getStudents().push_back(studentId);
    }

    void removeStudentFromCourse(Course &course, const std::string &studentId)
    {
        auto &students = course.getStudents();
        students.erase(std::remove(students.begin(), students.end(), studentId), students.end());
    }
};

// User:Student
class Student : public User
{
public:
    Student(const std::string &id) : id(id) {}

    // Then:Use Hash or ASCII to Encryption
    bool login(const std::string &password) override
    {
        return password == id;
    }

    void enrollCourse(std::vector<Course> &courses, int courseId)
    {
        for (auto &course : courses)
        {
            if (course.getId() == courseId)
            {
                course.getStudents().push_back(id);
                enrolledCourses.push_back(course);
                break;
            }
        }
    }

    void dropCourse(int courseId)
    {
        enrolledCourses.erase(std::remove_if(enrolledCourses.begin(), enrolledCourses.end(), [courseId](const Course &c)
                                             { return c.getId() == courseId; }),
                              enrolledCourses.end());
    }

    void displayEnrolledCourses() const
    {
        for (const auto &course : enrolledCourses)
        {
            course.display();
        }
    }

private:
    std::string id;
    std::vector<Course> enrolledCourses;
};

#endif
