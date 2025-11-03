#include "hello.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

void Gradebook::addStudent(const string& f, const string& l, const string& id) {
   if(students.count(id)) { cout << "Error: Student ID " << id << " already exists.\n"; return; }
   students[id] = {f,l,{}};
   cout << "Student " << f << " " << l << " added with ID " << id << ".\n";
}

bool Gradebook::giveGrade(const string& id, const string& assignment, double points) {
   if(!students.count(id)){ cout << "Error: Student ID " << id << " not found.\n"; return false; }
   if(points < 0){ cout << "Error: Grade cannot be negative.\n"; return false; }
   students[id].grades[assignment] = points;
   cout << "Grade recorded: " << assignment << " = " << points << " for " << students[id].first << " " << students[id].last << ".\n";
   return true;
}

void Gradebook::listStudents() {
   if(students.empty()){ cout << "No students in the gradebook.\n"; return; }
   for(auto& s: students){ cout << "ID: " << s.first << ", Name: " << s.second.first << " " << s.second.last << "\n"; }
}

string Gradebook::printReport() {
   stringstream ss;
   if(students.empty()){ ss << "No students in the gradebook.\n"; return ss.str(); }
   for(auto& s: students){
      ss << "ID: " << s.first << ", Name: " << s.second.first << " " << s.second.last << "\n";
      if(s.second.grades.empty()) { ss << "  No grades yet.\n"; }
      else { for(auto& g: s.second.grades){ ss << "  " << g.first << ": " << g.second << "\n"; } }
      ss << "\n";
   }
   return ss.str();
}
