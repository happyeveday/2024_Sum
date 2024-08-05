// By Yang

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>

class Course
{
public:
    // Init Course Data
    Course(int id, std::string name, std::string time, std::string location, int credits, int hours, std::string teacher)
        : id(id), name(name), time(time), location(location), credits(credits), hours(hours), teacher(teacher) {}

    // Show the Data
    void display() const
    {
        std::cout << "ID: " << id << ", Name: " << name << ", Time: " << time
                  << ", Location: " << location << ", Credits: " << credits
                  << ", Hours: " << hours << ", Teacher: " << teacher << std::endl;
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getTime() const { return time; }
    std::string getLocation() const { return location; }
    int getCredits() const { return credits; }
    int getHours() const { return hours; }
    std::string getTeacher() const { return teacher; }
    // A course can have many student
    std::vector<std::string> &getStudents() { return students; }

private:
    int id;
    std::string name;
    std::string time;
    std::string location;
    int credits;
    int hours;
    std::string teacher;
    std::vector<std::string> students;
};

#endif
