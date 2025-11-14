#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Student class demonstrating basic OOP concepts:
 * - Encapsulation (private members)
 * - Constructors (default, parameterized, copy)
 * - Destructor
 * - Getters and Setters
 * - Member functions
 */
class Student {
private:
    string name;
    int id;
    double gpa;
    vector<string> courses;

public:
    // Default constructor
    Student() {
        name = "Unknown";
        id = 0;
        gpa = 0.0;
        cout << "Default constructor called for: " << name << endl;
    }

    // Parameterized constructor
    Student(string studentName, int studentId, double studentGpa) {
        name = studentName;
        id = studentId;
        gpa = studentGpa;
        cout << "Parameterized constructor called for: " << name << endl;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        id = other.id;
        gpa = other.gpa;
        courses = other.courses;
        cout << "Copy constructor called for: " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for: " << name << endl;
    }

    // Getters
    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    double getGpa() const {
        return gpa;
    }

    // Setters
    void setName(string newName) {
        name = newName;
    }

    void setId(int newId) {
        if (newId > 0) {
            id = newId;
        } else {
            cout << "Invalid ID. Must be positive." << endl;
        }
    }

    void setGpa(double newGpa) {
        if (newGpa >= 0.0 && newGpa <= 4.0) {
            gpa = newGpa;
        } else {
            cout << "Invalid GPA. Must be between 0.0 and 4.0." << endl;
        }
    }

    // Member functions
    void addCourse(string courseName) {
        courses.push_back(courseName);
        cout << "Added course: " << courseName << " for " << name << endl;
    }

    void displayInfo() const {
        cout << "\n--- Student Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Courses enrolled: " << courses.size() << endl;
        
        if (!courses.empty()) {
            cout << "Course list:" << endl;
            for (size_t i = 0; i < courses.size(); i++) {
                cout << "  " << (i + 1) << ". " << courses[i] << endl;
            }
        }
        cout << "-------------------------\n" << endl;
    }

    void updateGpa(double newGpa) {
        if (newGpa >= 0.0 && newGpa <= 4.0) {
            double oldGpa = gpa;
            gpa = newGpa;
            cout << name << "'s GPA updated from " << oldGpa 
                 << " to " << gpa << endl;
        } else {
            cout << "Invalid GPA value!" << endl;
        }
    }
};

int main() {
    cout << "=== C++ Class and OOP Demonstration ===" << endl;
    cout << "\n1. Creating students using different constructors:\n" << endl;

    // Using default constructor
    Student student1;
    student1.displayInfo();

    // Using parameterized constructor
    Student student2("Alice Johnson", 12345, 3.8);
    student2.addCourse("Data Structures");
    student2.addCourse("Algorithms");
    student2.addCourse("Operating Systems");
    student2.displayInfo();

    // Using copy constructor
    cout << "\n2. Demonstrating copy constructor:\n" << endl;
    Student student3 = student2;  // Copy constructor
    student3.setName("Bob Smith");
    student3.setId(12346);
    student3.displayInfo();

    // Demonstrating setters with validation
    cout << "\n3. Demonstrating setters and validation:\n" << endl;
    student1.setName("Charlie Brown");
    student1.setId(12347);
    student1.setGpa(3.5);
    student1.addCourse("C++ Programming");
    student1.displayInfo();

    // Invalid input handling
    cout << "\n4. Testing validation:\n" << endl;
    student1.setGpa(5.0);  // Invalid - too high
    student1.setId(-100);  // Invalid - negative

    // Demonstrating GPA update
    cout << "\n5. Updating student GPA:\n" << endl;
    student2.updateGpa(3.9);

    cout << "\n=== Program ending - destructors will be called ===" << endl;
    return 0;
}
