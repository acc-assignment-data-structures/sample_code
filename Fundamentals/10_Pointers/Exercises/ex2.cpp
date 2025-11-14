#include <iostream>

class Student {
    int id;
    double gpa;
    std::string name;
public:
    // Constructor
    Student(int id, double gpa, std::string name) : id(id), gpa(gpa), name(name) {}

    // Getter for ID
    int getId() const { return id; }

    // Getter for GPA
    double getGpa() const { return gpa; }

    // Getter for Name
    std::string getName() const { return name; }

    // Setter for GPA
    void setGpa(double newGpa) { 
        if (newGpa >= 0.0 && newGpa <= 4.0) {
            gpa = newGpa; 
        } else {
            std::cerr << "Invalid GPA. Please enter a GPA between 0.0 and 4.0." << std::endl;
        }
    }
};

void printStudentInfo(const Student* studentPtr) {
    // Access members using the structure pointer operator (->)
    std::cout << "Student ID: " << studentPtr->getId() << std::endl;
    std::cout << "Student Name: " << studentPtr->getName() << std::endl;
    std::cout << "Student GPA: " << studentPtr->getGpa() << std::endl;

    // This is equivalent to:
    // std::cout << "Student ID: " << (*studentPtr).id << std::endl;
}

void exercise_expert() {
    std::cout << "\n--- Expert Exercise ---" << std::endl;

    // 1. Create a Student object.
    Student s1 = {101, 3.85, "Alice"};

    // 2. Create a pointer to the Student object.
    Student* studentPtr = &s1;

    // 3. Pass the pointer to a function to print the info.
    std::cout << "Printing info using the -> operator:" << std::endl;
    printStudentInfo(studentPtr);

    // 4. Use the -> operator to directly modify a member.
    studentPtr->setGpa(3.99);

    std::cout << "\nAfter GPA update via pointer:" << std::endl;
    std::cout << "New GPA (s1.gpa): " << s1.getGpa() << std::endl;
}

int main() {
    exercise_expert();
    return 0;
}
