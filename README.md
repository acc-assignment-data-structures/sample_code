# Exam review

## Introduction
- Testing framework [GoogleTest for C++](https://google.github.io/googletest/)
- [C++ Developer Roadmap](https://roadmap.sh/cpp)

## Lecture:
- ch4: polymorphism
- ch4: Linkedlist

## Run into error with g++:
- Please use the command to run each file since they use newer version of C++ (eg: c++11, c++13, c++17)
```bash
g++ -std=c++17 ch5_recursion_problem_solving.cpp -o driver
```
## Exam1:
1. OOP (Concept Only)
    Object-oriented programming (OOP) is a programming paradigm that uses "objects" to design software. Objects are instances of classes, which can contain both data in the form of fields (often known as attributes or properties) and code in the form of procedures (often known as methods). OOP focuses on the concepts of encapsulation, inheritance, and polymorphism. Encapsulation allows bundling data and methods that work on that data within one unit, inheritance enables a class to inherit characteristics from another class, and polymorphism allows methods to do different things based on the object it is acting upon. This approach aims to increase the flexibility and maintainability of code by organizing software design around data, or objects, rather than functions and logic.

2. Linked List:
    - Single (InsertAtBeginning (or the Ends), Update, Delete, IsEmpty )
    - Double(InsertAtBeginning (or the Ends), Update, Delete, IsEmpty )
    - Head, Tails concepts

In the context of a linked list, the "head" and "tails" pointers (though typically it's singular "tail") are references used to efficiently manage the list.

    - **Head Pointer**: The head pointer points to the first node in a linked list. It is the primary entry point to the list, allowing access to every other node by traversing from the head through each node's next pointer until the end of the list is reached. In an empty list, the head pointer is typically set to null.

    - **Tail Pointer**: The tail pointer points to the last node in a linked list. Having a tail pointer is particularly useful in singly linked lists when you want to append elements efficiently. Without a tail pointer, appending an element would require traversing the entire list to find the last node. In an empty list, the tail pointer, like the head, is set to null.

Using head and tail pointers simplifies operations such as insertion and deletion at both the beginning and the end of the list, enhancing the performance of these operations.

3. Recursive:
    - Recursive: 
        - Recursive refers to a method or process that solves a problem by breaking it down into smaller, more manageable problems of the same type. In programming, a recursive function is one that calls itself within its own code. This approach is particularly useful for tasks that can be divided into similar subtasks, such as sorting algorithms (e.g., quicksort, mergesort), navigating tree structures (e.g., searching in binary trees), or calculating mathematical sequences (e.g., Fibonacci numbers).

        - A key feature of a recursive function is the presence of a base case, which is a condition that stops the recursion to prevent it from continuing indefinitely. Each recursive call should bring the current problem closer to the base case, eventually terminating the recursion.

    - Basic Recursive concept: In recursion, a function calls itself to solve a problem by breaking it down into smaller, more manageable sub-problems. This process is defined by two essential components: the base case and the recursive case.
        - Base Case: The base case is a condition that stops the recursion from continuing indefinitely. It defines the simplest instance of the problem, which can be solved directly without further recursion. The base case acts as a termination point for the recursive function, ensuring that it eventually ends. When the function encounters a base case, it returns a value without making any more recursive calls.
        - Recursive case: The recursive case is the part of the function that includes the recursive call. It breaks down the problem into smaller instances, moving the problem closer to the base case with each recursive step. The recursive case must eventually lead to the base case to prevent infinite loops and stack overflow errors.

        
4. OOP Fundamental:
    - Polymorphism (Many form):
        - Compile-Time Polymorphism (Method Overloading): This occurs when there are multiple methods in the same scope with the same name but different parameters (number of parameters, types of parameters, or both). The correct method to be executed is determined at compile time based on the method signature. This is also known as method overloading.

        - Runtime Polymorphism (Method Overriding): This is achieved through inheritance and virtual functions (or methods). In this case, a method in a base class is overridden by a method in a derived class. The determination of which method to call is made at runtime based on the type of the object that invokes the method. This allows objects of different classes to be treated as objects of a common superclass, with each object responding to common methods in its own way. This is also known as method overriding.
    - Class and Object: getter and setter, private, public, protected class(concept + code)
    - virtual methods? (Concept + code): A virtual method is a function or method in a base class that can be overridden in derived classes. Declaring a method as virtual allows it to be dynamically dispatched, meaning that the method call is resolved at runtime based on the object's actual type, not its declared type. This capability is crucial for implementing polymorphism, allowing objects of different classes to be treated as objects of a common base class while still behaving according to their actual class.
    - abstract class? (Concept + code): An abstract class is a class that cannot be instantiated on its own and is designed to be subclassed. It often contains one or more abstract methods, which are methods declared in the abstract class but must be implemented by its subclasses. While not directly called "virtual classes," abstract classes serve a similar conceptual purpose by providing a blueprint for other classes.
    - Inheritance: Inheritance is a fundamental concept in Object-Oriented Programming (OOP) that allows a class to inherit properties (attributes/fields) and methods (functions) from another class. The class that inherits the properties and methods is known as the child class, subclass, or derived class, while the class from which the properties and methods are inherited is called the parent class, superclass, or base class. Inheritance enables a hierarchy of classes that can share, extend, and modify behavior and attributes from parent classes to child classes. This mechanism promotes code reusability, making it easier to create and maintain applications by allowing developers to build new classes upon existing classes without having to rewrite code from scratch.There are several types of inheritance in OOP, including:

        - Single Inheritance: A child class inherits from one parent class.
        - Multiple Inheritance: A child class inherits from more than one parent class. (Note: Not all programming languages support multiple inheritance directly, e.g., Java uses interfaces to achieve a similar effect.) (Concept + Code)

        ```cplus
        // In multiple inheritance, a class can inherit from more than one class.
        #include <iostream>
        using namespace std;

        class ClassA {
        public:
            void displayA() { cout << "Class A content.\n"; }
        };

        class ClassB {
        public:
            void displayB() { cout << "Class B content.\n"; }
        };

        class ClassC : public ClassA, public ClassB {
        };

        int main() {
            ClassC objC;
            objC.displayA();
            objC.displayB();
            return 0;
        }

        ```
        - Multilevel Inheritance: A form of inheritance where a class is derived from a child class, making it a grandchild class.
        ```cplus
        // In multilevel inheritance, a class is derived from a class which is also derived from another class.

        #include <iostream>
        using namespace std;

        class ClassA {
        public:
            void displayA() { cout << "Class A content.\n"; }
        };

        class ClassB : public ClassA {
        public:
            void displayB() { cout << "Class B content.\n"; }
        };

        class ClassC : public ClassB {
        public:
            void displayC() { cout << "Class C content.\n"; }
        };

        int main() {
            ClassC objC;
            objC.displayA();
            objC.displayB();
            objC.displayC();
            return 0;
        }

        ```
        - Hierarchical Inheritance: Multiple classes inherit from a single parent class.
        ```cplus
        // In hierarchical inheritance, several classes are derived from a single base class.

        #include <iostream>
        using namespace std;

        class BaseClass {
        public:
            void displayBase() { cout << "Base class content.\n"; }
        };

        class DerivedClass1 : public BaseClass {
        public:
            void displayDerived1() { cout << "Derived Class 1 content.\n"; }
        };

        class DerivedClass2 : public BaseClass {
        public:
            void displayDerived2() { cout << "Derived Class 2 content.\n"; }
        };

        int main() {
            DerivedClass1 obj1;
            DerivedClass2 obj2;
            obj1.displayBase();
            obj1.displayDerived1();
            obj2.displayBase();
            obj2.displayDerived2();
            return 0;
        }

        ```
        - Hybrid Inheritance: A combination of two or more types of inheritance.
        ```cplus
        // Hybrid inheritance is a combination of two or more types of inheritance. 
        #include <iostream>
        using namespace std;

        class ClassA {
        public:
            void displayA() { cout << "Class A content.\n"; }
        };

        class ClassB : public ClassA {
        public:
            void displayB() { cout << "Class B content.\n"; }
        };

        class ClassC : public ClassA {
        public:
            void displayC() { cout << "Class C content.\n"; }
        };

        class ClassD : public ClassB, public ClassC {
        public:
            void displayD() { cout << "Class D content.\n"; }
        };

        int main() {
            ClassD objD;
            objD.displayB(); // From ClassB
            objD.displayC(); // From ClassC
            objD.displayD();
            // Note: objD.displayA() is ambiguous without further specification due to the diamond problem
            return 0;
        }

        ```
        Inheritance allows for the specification of generic types and behaviors in the parent class, which can be inherited or overridden by child classes to provide more specific implementations. This is crucial for implementing polymorphism and encouraging a modular and structured approach to programming.


    - Multiple inheritance? 
    
5. Exception Handling (Concept+ Code):
    - try block
    - catch block
    - thrown statement

6. Sorted List (Concept + Code):
    - Linked List Implementation (Concept + Code) (insert)
    - Array Implementation (Concept + Code) (insert)

7. Stack (CC):
    - ADT Stack
    - Stack Node functions (Push, Pop, Peek, Isempty)