#include <iostream>

// Base class 1
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing shape" << std::endl;
    }
};

// Base class 2
class Color {
public:
    virtual void applyColor() {
        std::cout << "Applying color" << std::endl;
    }
};

// Derived class inheriting virtually from Shape and Color
class Square : public virtual Shape, public virtual Color {
public:
    void display() {
        std::cout << "Square display" << std::endl;
    }
};

int main() {
    Square square;

    // Accessing members from Shape
    square.draw();

    // Accessing members from Color
    square.applyColor();

    // Accessing members from Square
    square.display();

    return 0;
}
