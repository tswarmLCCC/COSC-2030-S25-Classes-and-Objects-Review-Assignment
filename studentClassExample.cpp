#include <iostream>
#include <vector>

struct Student {
  int id;
  std::string name;
  std::vector<int> grades;
};

class StudentRecord {
public:
  void addStudent(int id, std::string name, std::vector<int> grades) {
    Student student = {id, name, grades};
    students.push_back(student);
  }

  void printStudentRecord() {
    for (auto student : students) {
      std::cout << "ID: " << student.id << std::endl;
      std::cout << "Name: " << student.name << std::endl;
      std::cout << "Grades: ";
      for (auto grade : student.grades) {
        std::cout << grade << " ";
      }
      std::cout << std::endl << std::endl;
    }
  }

private:
  std::vector<Student> students;
};

int main() {
  StudentRecord record;
  record.addStudent(1, "John", {90, 80, 70});
  record.addStudent(2, "Jane", {85, 95, 75});
  record.addStudent(3, "Bob", {80, 85, 90});

  record.printStudentRecord();

  return 0;
}