# C++ Class and Object-Oriented Programming Examples

A comprehensive collection of C++ code examples demonstrating fundamental and advanced OOP concepts.

## Table of Contents

1. [Overview](#overview)
2. [Files Included](#files-included)
3. [Concepts Covered](#concepts-covered)
4. [Compilation Instructions](#compilation-instructions)
5. [Running the Examples](#running-the-examples)
6. [Example Outputs](#example-outputs)

## Overview

This repository contains four comprehensive C++ programs that demonstrate various Object-Oriented Programming concepts. Each file is self-contained and can be compiled and run independently.

## Files Included

### 1. student.cpp
**Basic OOP Fundamentals**

Demonstrates:
- Class definition and structure
- Encapsulation (private, public access modifiers)
- Constructors (default, parameterized, copy)
- Destructor
- Getter and setter methods
- Member functions
- Input validation

Key Learning Points:
- How to create and use classes
- Importance of encapsulation
- Constructor overloading
- Proper resource management with destructors

### 2. inheritance_polymorphism.cpp
**Inheritance and Polymorphism**

Demonstrates:
- Base and derived classes
- Protected members
- Virtual functions
- Function overriding
- Polymorphism with pointers
- Virtual destructors
- Abstract behavior

Classes:
- Shape (base class)
- Circle (derived)
- Rectangle (derived)
- Triangle (derived)

Key Learning Points:
- How inheritance promotes code reuse
- Runtime polymorphism
- Virtual function tables
- Proper use of virtual destructors

### 3. advanced_oop.cpp
**Advanced OOP Features**

Demonstrates:
- Static members and methods
- Friend functions
- Operator overloading (+, ==, >, +=, <<)
- Const member functions
- Class-level vs instance-level members

Key Learning Points:
- When to use static members
- How operator overloading works
- Friend function access privileges
- Difference between const and non-const methods

### 4. composition_aggregation.cpp
**Object Relationships**

Demonstrates:
- Composition (strong "has-a" relationship)
- Aggregation (weak "has-a" relationship)
- Object ownership concepts
- Complex object hierarchies

Classes and Relationships:
- Car **has-a** Engine (composition)
- Car **has-a** Tires (composition)
- Driver **uses-a** Car (aggregation)
- ParkingLot **contains** Cars (aggregation)

Key Learning Points:
- Difference between composition and aggregation
- Object lifetime management
- When objects should own vs reference other objects

## Compilation Instructions

### Using g++ compiler:

```bash
# Compile individual files
g++ -std=c++11 -o student student.cpp
g++ -std=c++11 -o inheritance inheritance_polymorphism.cpp
g++ -std=c++11 -o advanced advanced_oop.cpp
g++ -std=c++11 -o composition composition_aggregation.cpp

# Compile with warnings (recommended)
g++ -std=c++11 -Wall -Wextra -o student student.cpp
```

### Using clang++ compiler:

```bash
clang++ -std=c++11 -o student student.cpp
clang++ -std=c++11 -o inheritance inheritance_polymorphism.cpp
clang++ -std=c++11 -o advanced advanced_oop.cpp
clang++ -std=c++11 -o composition composition_aggregation.cpp
```

### Compile all at once:

```bash
# Create a script to compile all
for file in student inheritance_polymorphism advanced_oop composition_aggregation; do
    g++ -std=c++11 -Wall -o ${file} ${file}.cpp
done
```

## Running the Examples

After compilation, run the executables:

```bash
./student
./inheritance
./advanced
./composition
```

## Example Outputs

### Student Example Output:
```
=== C++ Class and OOP Demonstration ===

1. Creating students using different constructors:

Default constructor called for: Unknown

--- Student Information ---
Name: Unknown
ID: 0
GPA: 0
Courses enrolled: 0
-------------------------

Parameterized constructor called for: Alice Johnson
Added course: Data Structures for Alice Johnson
Added course: Algorithms for Alice Johnson
...
```

### Inheritance Example Output:
```
=== Inheritance and Polymorphism Demo ===

1. Creating shape objects:

2. Displaying shape information:

Shape: Circle
Color: Red
Radius: 5
Area: 78.5398
Circumference: 31.4159
------------------------
...
```

### Advanced OOP Example Output:
```
=== Advanced OOP Features Demo ===

=== Bank Statistics ===
Total Accounts: 0
Total Bank Balance: $0
=======================

1. Creating bank accounts:

Account created: John Doe
Account created: Jane Smith
...
```

## Concepts Covered

### Basic Concepts
- Classes and Objects
- Encapsulation
- Constructors and Destructors
- Member Functions
- Access Specifiers (public, private, protected)

### Intermediate Concepts
- Inheritance (Single, Hierarchical)
- Polymorphism (Runtime)
- Virtual Functions
- Function Overriding
- Abstract Classes

### Advanced Concepts
- Static Members
- Friend Functions
- Operator Overloading
- Const Correctness
- Composition vs Aggregation
- Object Relationships

## Best Practices Demonstrated

1. **RAII (Resource Acquisition Is Initialization)**
   - Resources allocated in constructor
   - Resources freed in destructor

2. **Const Correctness**
   - Member functions that don't modify state are marked const
   - Const parameters and return values where appropriate

3. **Encapsulation**
   - Private data members
   - Public interface methods
   - Input validation in setters

4. **Virtual Destructors**
   - Used in base classes to ensure proper cleanup
   - Prevents memory leaks in inheritance hierarchies

5. **Initialization Lists**
   - Used in constructors for efficient initialization
   - Required for const members and references

## Learning Path

**Recommended Order:**
1. Start with `student.cpp` - Learn basic class concepts
2. Move to `inheritance_polymorphism.cpp` - Understand inheritance
3. Study `advanced_oop.cpp` - Master advanced features
4. Finally `composition_aggregation.cpp` - Learn object relationships

## Additional Notes

- All examples include extensive comments explaining the code
- Each program is self-contained and demonstrates specific concepts
- Output messages help trace program execution and object lifecycles
- Examples follow modern C++ best practices

## Educational Use

These examples are designed for teaching and learning C++ OOP concepts. They can be used as:
- Classroom demonstrations
- Self-study materials
- Reference implementations
- Starting points for exercises

## Requirements

- C++11 or later compiler
- Standard C++ library
- No external dependencies

## Author Notes

These examples progressively build understanding of OOP in C++. Each concept is demonstrated with practical, real-world analogies:
- Student management system
- Geometric shapes
- Banking system
- Vehicle and parking management

The code emphasizes clarity and educational value over production optimization.

## License

These examples are provided for educational purposes.
