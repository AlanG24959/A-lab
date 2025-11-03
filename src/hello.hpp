#pragma once
#include <string>
#include <map>

class Gradebook {
    struct Student {
        std::string first, last;
        std::map<std::string,double> grades;
    };
    std::map<std::string, Student> students;
public:
    void addStudent(const std::string& f, const std::string& l, const std::string& id);
    bool giveGrade(const std::string& id, const std::string& assignment, double points);
    std::string printReport();
    void listStudents();
};
