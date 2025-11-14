# C++ OOP Quick Reference Guide

## Class Basics

### Class Declaration
```cpp
class ClassName {
private:
    // Private members (accessible only within class)
    int privateVar;
    
protected:
    // Protected members (accessible in derived classes)
    int protectedVar;
    
public:
    // Public members (accessible from anywhere)
    int publicVar;
    
    // Constructor
    ClassName();
    
    // Destructor
    ~ClassName();
    
    // Member functions
    void memberFunction();
};
```

## Constructors

### Default Constructor
```cpp
ClassName() {
    // Initialize members
}
```

### Parameterized Constructor
```cpp
ClassName(int value) {
    member = value;
}
```

### Copy Constructor
```cpp
ClassName(const ClassName& other) {
    member = other.member;
}
```

### Constructor with Initializer List
```cpp
ClassName(int value) : member(value) {
    // More efficient for member initialization
}
```

## Inheritance

### Single Inheritance
```cpp
class Base {
    // Base class members
};

class Derived : public Base {
    // Derived class members
    // Inherits all public and protected members from Base
};
```

### Access Specifiers in Inheritance
- `public` inheritance: public → public, protected → protected
- `protected` inheritance: public → protected, protected → protected
- `private` inheritance: public → private, protected → private

## Polymorphism

### Virtual Functions
```cpp
class Base {
public:
    virtual void function() {
        // Base implementation
    }
    
    virtual ~Base() {
        // Virtual destructor for proper cleanup
    }
};

class Derived : public Base {
public:
    void function() override {
        // Derived implementation
    }
};
```

### Pure Virtual Functions (Abstract Classes)
```cpp
class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0;  // Pure virtual
    virtual ~AbstractClass() {}
};
```

## Static Members

### Static Variables
```cpp
class MyClass {
private:
    static int count;  // Shared by all instances
    
public:
    MyClass() {
        count++;
    }
    
    static int getCount() {  // Static function
        return count;
    }
};

// Initialize static member
int MyClass::count = 0;
```

## Friend Functions

```cpp
class MyClass {
private:
    int privateData;
    
public:
    friend void friendFunction(MyClass& obj);
};

// Friend function can access private members
void friendFunction(MyClass& obj) {
    obj.privateData = 10;  // OK
}
```

## Operator Overloading

### Member Function
```cpp
class Complex {
private:
    double real, imag;
    
public:
    Complex operator+(const Complex& other) {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }
};
```

### Friend Function (for << operator)
```cpp
class MyClass {
    friend ostream& operator<<(ostream& out, const MyClass& obj);
};

ostream& operator<<(ostream& out, const MyClass& obj) {
    out << obj.data;
    return out;
}
```

## Common Operators to Overload

- Arithmetic: `+`, `-`, `*`, `/`, `%`
- Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Assignment: `=`, `+=`, `-=`, etc.
- Stream: `<<`, `>>`
- Increment/Decrement: `++`, `--`
- Subscript: `[]`
- Function call: `()`

## Const Correctness

### Const Member Functions
```cpp
class MyClass {
public:
    int getValue() const {  // Doesn't modify object
        return value;
    }
    
    void setValue(int v) {  // Modifies object
        value = v;
    }
private:
    int value;
};
```

### Const Objects
```cpp
const MyClass obj;
obj.getValue();   // OK - const function
obj.setValue(5);  // ERROR - non-const function
```

## Composition vs Aggregation

### Composition (Strong Ownership)
```cpp
class Engine {
    // Engine implementation
};

class Car {
private:
    Engine engine;  // Car owns Engine
    // Engine is destroyed when Car is destroyed
};
```

### Aggregation (Weak Relationship)
```cpp
class Driver {
private:
    Car* car;  // Driver uses Car but doesn't own it
    // Car survives even if Driver is destroyed
};
```

## Best Practices

1. **Use initializer lists in constructors**
   - More efficient
   - Required for const members and references

2. **Make destructors virtual in base classes**
   - Ensures proper cleanup in inheritance hierarchies

3. **Use const for functions that don't modify objects**
   - Helps catch errors at compile time
   - Allows const objects to call these functions

4. **Follow the Rule of Three/Five**
   - If you define destructor, copy constructor, or copy assignment,
   - Define all three (Rule of Three)
   - In C++11+: also define move constructor and move assignment (Rule of Five)

5. **Prefer composition over inheritance**
   - More flexible
   - Easier to test and maintain

6. **Use access specifiers appropriately**
   - private: implementation details
   - protected: for use by derived classes
   - public: interface for users

7. **Initialize all member variables**
   - Prevents undefined behavior
   - Use default member initializers (C++11+)

## Common Pitfalls

1. **Forgetting virtual destructors**
   - Leads to memory leaks in inheritance

2. **Slicing problem**
   - Assigning derived object to base object value

3. **Not making functions const when they should be**
   - Prevents use with const objects

4. **Circular dependencies in composition**
   - Can cause compilation issues

5. **Overusing inheritance**
   - Leads to complex hierarchies
   - Consider composition instead

## Memory Management

### Stack vs Heap

```cpp
// Stack allocation (automatic cleanup)
MyClass obj;

// Heap allocation (manual cleanup required)
MyClass* ptr = new MyClass();
delete ptr;  // Must delete

// Array allocation
MyClass* arr = new MyClass[10];
delete[] arr;  // Must use delete[]
```

### Smart Pointers (C++11+)
```cpp
#include <memory>

// Unique ownership
std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();

// Shared ownership
std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>();

// Weak reference
std::weak_ptr<MyClass> ptr3 = ptr2;
```

## Additional Resources

- Check individual example files for detailed implementations
- Each example includes extensive comments
- Build and run examples to see concepts in action
- Modify examples to experiment with different approaches
