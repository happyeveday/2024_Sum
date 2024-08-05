// By Yang

#include <iostream>
#include <vector>
#include <memory>
#include "Course.h"
#include "User.h"
#include "Show.h"

int main()
{
    std::vector<Course> courses;
    std::unique_ptr<User> user;

    while (true)
    {
        showMenu();
        int choice;
        std::cin >> choice;

        if (choice == 4)
        {
            break;
        }

        std::string password, id;
        switch (choice)
        {
        case 1: // Admin
            user = std::make_unique<Admin>();
            std::cout << "Enter password: ";
            std::cin >> password;
            if (user->login(password))
            {
                while (true)
                {
                    adminMenu();
                    int adminChoice;
                    std::cin >> adminChoice;
                    if (adminChoice == 5)
                        break;

                    switch (adminChoice)
                    {
                    case 1: // Show all courses
                        for (const auto &course : courses)
                        {
                            course.display();
                        }
                        break;
                    case 2:
                    { // Add course
                        int id, credits, hours;
                        std::string name, time, location, teacher;
                        std::cout << "Enter course id, name, time, location, credits, hours, teacher: ";
                        std::cin >> id >> name >> time >> location >> credits >> hours >> teacher;
                        static_cast<Admin *>(user.get())->addCourse(courses, Course(id, name, time, location, credits, hours, teacher));
                        break;
                    }
                    case 3:
                    { // Remove course
                        int id;
                        std::cout << "Enter course id to remove: ";
                        std::cin >> id;
                        static_cast<Admin *>(user.get())->removeCourse(courses, id);
                        break;
                    }
                    case 4:
                    { // Modify course
                        int id, credits, hours;
                        std::string name, time, location, teacher;
                        std::cout << "Enter course id to modify: ";
                        std::cin >> id;
                        std::cout << "Enter new course name, time, location, credits, hours, teacher: ";
                        std::cin >> name >> time >> location >> credits >> hours >> teacher;
                        static_cast<Admin *>(user.get())->modifyCourse(courses, id, Course(id, name, time, location, credits, hours, teacher));
                        break;
                    }
                    }
                }
            }
            else
            {
                std::cout << "Invalid password!" << std::endl;
            }
            break;
        case 2: // Teacher
            user = std::make_unique<Teacher>();
            std::cout << "Enter password: ";
            std::cin >> password;
            if (user->login(password))
            {
                while (true)
                {
                    teacherMenu();
                    int teacherChoice;
                    std::cin >> teacherChoice;
                    if (teacherChoice == 4)
                        break;

                    switch (teacherChoice)
                    {
                    case 1: // Show my courses
                        for (const auto &course : courses)
                        {
                            if (course.getTeacher() == "teacher123")
                            { // Simplified check
                                course.display();
                            }
                        }
                        break;
                    case 2:
                    { // Add student to course
                        int courseId;
                        std::string studentId;
                        std::cout << "Enter course id and student id: ";
                        std::cin >> courseId >> studentId;
                        for (auto &course : courses)
                        {
                            if (course.getId() == courseId)
                            {
                                static_cast<Teacher *>(user.get())->addStudentToCourse(course, studentId);
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    { // Remove student from course
                        int courseId;
                        std::string studentId;
                        std::cout << "Enter course id and student id: ";
                        std::cin >> courseId >> studentId;
                        for (auto &course : courses)
                        {
                            if (course.getId() == courseId)
                            {
                                static_cast<Teacher *>(user.get())->removeStudentFromCourse(course, studentId);
                                break;
                            }
                        }
                        break;
                    }
                    }
                }
            }
            else
            {
                std::cout << "Invalid password!" << std::endl;
            }
            break;
        case 3: // Student
            std::cout << "Enter student id: ";
            std::cin >> id;
            user = std::make_unique<Student>(id);
            std::cout << "Enter password: ";
            std::cin >> password;
            if (user->login(password))
            {
                while (true)
                {
                    studentMenu();
                    int studentChoice;
                    std::cin >> studentChoice;
                    if (studentChoice == 4)
                        break;

                    switch (studentChoice)
                    {
                    case 1: // Show all courses
                        for (const auto &course : courses)
                        {
                            course.display();
                        }
                        break;
                    case 2:
                    { // Enroll in course
                        int courseId;
                        std::cout << "Enter course id to enroll: ";
                        std::cin >> courseId;
                        static_cast<Student *>(user.get())->enrollCourse(courses, courseId);
                        break;
                    }
                    case 3:
                    { // Drop course
                        int courseId;
                        std::cout << "Enter course id to drop: ";
                        std::cin >> courseId;
                        static_cast<Student *>(user.get())->dropCourse(courseId);
                        break;
                    }
                    case 4:
                    { // Show enrolled courses
                        static_cast<Student *>(user.get())->displayEnrolledCourses();
                        break;
                    }
                    }
                }
            }
            else
            {
                std::cout << "Invalid password!" << std::endl;
            }
            break;
        }
    }

    return 0;
}
