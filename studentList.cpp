//Program Created by Jermaine Lara
//10/19/17
//Program adds, deletes and prints names of students, their ID's and GPA's

#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

struct Student {
  char firstName[10];
  char lastName[10];
  int studentId;
  float gpa;
};

void addStudent(vector<Student *> & students);
void printStudents(vector<Student *> & students);
void deleteStudent(vector<Student *> & students);

int main() {
  //Vector Pointer
  vector<Student *> students;
  char command[81];
  //Main Loop
  do {
    cout << "Enter Command (ADD, PRINT, DELETE or QUIT)" << endl;
    cin >> command;
    if (strcmp(command, "ADD") == 0) {
      addStudent(students);
    }
    else if (strcmp(command, "PRINT") == 0) {
      printStudents(students);
    }
    else if (strcmp(command, "DELETE") == 0) {
      deleteStudent(students);
    }
    else if (strcmp(command, "QUIT") != 0) {
      cout << "Invalid Command" << endl;
    }
  } while(strcmp(command, "QUIT") != 0);
}

//ADD Method prompts user for student info and adds it
void addStudent(vector<Student *> & students) {
  Student *student = new Student;
  cout << "Enter First Name" << endl;
  cin >> student->firstName;
  cout << "Enter Last Name" << endl;
  cin >> student->lastName;
  cout << "Enter Student ID" << endl;
  cin >> student->studentId;
  cout << "Enter Student GPA" << endl;
  cin >> student->gpa;
  students.push_back(student);
}

//PRINT method couts all students' information
void printStudents(vector<Student *> & students) {
  //Iterator reference: http://www.cplusplus.com/reference/vector/vector/begin/
  //Float Precision reference: https://stackoverflow.com/questions/14677448/how-to-cout-a-float-number-with-n-decimal-places
  for (vector<Student *>::iterator it = students.begin() ; it != students.end(); ++it) {
    cout << (*it)->firstName << " " << (*it)->lastName << ", " << (*it)->studentId
	 << ", " << fixed << setprecision(2) << (*it)->gpa << endl;
  }
}

//DELETE method deletes a student's information from the list
void deleteStudent(vector<Student *> & students) {
  cout << "Enter the student ID number to delete them from the list" << endl;
  int studentId;
  cin >> studentId;
  //Similar to the other Iterator loop but instead deletes instead of prints
  for (vector<Student *>::iterator it = students.begin() ; it != students.end(); ++it) {
    if (studentId == (*it)->studentId) {
      delete *it;
      students.erase(it);
      break;
    }
  }
}
  
  

