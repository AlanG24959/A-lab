#include "src/hello.hpp"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
  Gradebook gb;
  int choice;

  do {
    cout << "\n--- CSC122 Gradebook ---\n";
    cout << "1. Add Student\n";
    cout << "2. Give Grade\n";
    cout << "3. List Students\n";
    cout << "4. Print Report\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(choice == 1){
      string f,l,id;
      cout << "First name: "; getline(cin,f);
      cout << "Last name: "; getline(cin,l);
      cout << "Student ID: "; getline(cin,id);
      gb.addStudent(f,l,id);
    }
    else if(choice == 2){
      gb.listStudents();
      string id, assignment; double points;
      cout << "Enter Student ID to give grade: "; getline(cin,id);
      cout << "Assignment name: "; getline(cin,assignment);
      cout << "Points earned: "; cin >> points;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      gb.giveGrade(id,assignment,points);
    }
    else if(choice == 3){ gb.listStudents(); }
    else if(choice == 4){ cout << "\n" << gb.printReport(); }
    else if(choice != 0){ cout << "Invalid choice!\n"; }

  } while(choice != 0);

  cout << "Exiting Gradebook.\n";
}
