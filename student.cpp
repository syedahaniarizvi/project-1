#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    int studentID;
    string name;
    int age;
    string grade;

public:
    // Constructor
    Student(int id, string n, int a, string g) : studentID(id), name(n), age(a), grade(g) {}

    // Accessor functions
    int getID() const { return studentID; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGrade() const { return grade; }

    // Mutator functions
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGrade(string g) { grade = g; }

    // Display function
    void display() const {
        cout << setw(6) << studentID << " | " << setw(20) << name << " | " << setw(3) 
             << age << " | " << setw(5) << grade << endl;
    }
};

// Function prototypes
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void searchStudent(const vector<Student>& students);
void updateStudent(vector<Student>& students);

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void addStudent(vector<Student>& students) {
    int id, age;
    string name, grade;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore(); // Clear input buffer
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore(); // Clear input buffer
    cout << "Enter Grade: ";
    getline(cin, grade);

    students.emplace_back(id, name, age, grade);
    cout << "Student added successfully!\n";
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available to display.\n";
        return;
    }

    cout << "\nStudent Details:\n";
    cout << "ID    | Name                | Age | Grade\n";
    cout << "---------------------------------------------\n";

    for (const auto& student : students) {
        student.display();
    }
}

void searchStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to search.\n";
        return;
    }

    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    for (const auto& student : students) {
        if (student.getID() == id) {
            cout << "\nStudent Found!\n";
            student.display();
            return;
        }
    }

    cout << "Student with ID " << id << " not found.\n";
}

void updateStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to update.\n";
        return;
    }

    int id, age;
    string name, grade;
    cout << "Enter Student ID to update: ";
    cin >> id;
    cin.ignore(); // Clear input buffer

    for (auto& student : students) {
        if (student.getID() == id) {
            cout << "Student Found! Enter new details.\n";
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cin.ignore(); // Clear input buffer
            cout << "Enter Grade: ";
            getline(cin, grade);

            student.setName(name);
            student.setAge(age);
            student.setGrade(grade);

            cout << "Student details updated successfully!\n";
            return;
        }
    }

    cout << "Student with ID " << id << " not found.\n";
}
