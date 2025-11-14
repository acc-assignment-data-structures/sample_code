#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/**
 * Inheritance and Polymorphism Example
 * 
 * Base class: Shape
 * Derived classes: Circle, Rectangle, Triangle
 * Demonstrates: inheritance, virtual functions, function overriding
 */

// Base class
class Shape {
protected:
    string name;
    string color;

public:
    // Constructor
    Shape(string shapeName, string shapeColor) {
        name = shapeName;
        color = shapeColor;
    }

    // Virtual destructor (important for polymorphism)
    virtual ~Shape() {
        cout << "Shape destructor called for: " << name << endl;
    }

    // Virtual functions (can be overridden)
    virtual double calculateArea() const {
        return 0.0;
    }

    virtual double calculatePerimeter() const {
        return 0.0;
    }

    virtual void displayInfo() const {
        cout << "Shape: " << name << endl;
        cout << "Color: " << color << endl;
    }

    // Getters
    string getName() const {
        return name;
    }

    string getColor() const {
        return color;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(string shapeColor, double r) 
        : Shape("Circle", shapeColor), radius(r) {
    }

    ~Circle() {
        cout << "Circle destructor called" << endl;
    }

    // Override virtual functions
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * 3.14159 * radius;
    }

    void displayInfo() const override {
        Shape::displayInfo();  // Call base class function
        cout << "Radius: " << radius << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Circumference: " << calculatePerimeter() << endl;
        cout << "------------------------" << endl;
    }

    double getRadius() const {
        return radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(string shapeColor, double w, double h)
        : Shape("Rectangle", shapeColor), width(w), height(h) {
    }

    ~Rectangle() {
        cout << "Rectangle destructor called" << endl;
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
        cout << "------------------------" << endl;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(string shapeColor, double s1, double s2, double s3)
        : Shape("Triangle", shapeColor), side1(s1), side2(s2), side3(s3) {
    }

    ~Triangle() {
        cout << "Triangle destructor called" << endl;
    }

    double calculateArea() const override {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Side 1: " << side1 << endl;
        cout << "Side 2: " << side2 << endl;
        cout << "Side 3: " << side3 << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
        cout << "------------------------" << endl;
    }
};

// Function demonstrating polymorphism
void printShapeDetails(const Shape* shape) {
    cout << "\n=== Polymorphic function call ===" << endl;
    shape->displayInfo();
}

int main() {
    cout << "=== Inheritance and Polymorphism Demo ===" << endl;

    // Creating objects of different derived classes
    cout << "\n1. Creating shape objects:\n" << endl;

    Circle circle("Red", 5.0);
    Rectangle rectangle("Blue", 4.0, 6.0);
    Triangle triangle("Green", 3.0, 4.0, 5.0);

    // Display information for each shape
    cout << "\n2. Displaying shape information:\n" << endl;
    
    circle.displayInfo();
    rectangle.displayInfo();
    triangle.displayInfo();

    // Demonstrating polymorphism with pointers
    cout << "\n3. Demonstrating polymorphism:\n" << endl;

    Shape* shapePtr;

    shapePtr = &circle;
    printShapeDetails(shapePtr);

    shapePtr = &rectangle;
    printShapeDetails(shapePtr);

    shapePtr = &triangle;
    printShapeDetails(shapePtr);

    // Using array of pointers for polymorphism
    cout << "\n4. Using array of base class pointers:\n" << endl;

    Shape* shapes[3];
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    shapes[2] = &triangle;

    double totalArea = 0.0;
    for (int i = 0; i < 3; i++) {
        cout << "Shape " << (i + 1) << ": " << shapes[i]->getName() 
             << " - Area: " << shapes[i]->calculateArea() << endl;
        totalArea += shapes[i]->calculateArea();
    }

    cout << "\nTotal area of all shapes: " << totalArea << endl;

    cout << "\n=== Program ending ===" << endl;
    return 0;
}
