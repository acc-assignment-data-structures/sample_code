## 💻 C++ Exam Review: Pointers, Memory, Files, and Strings

### **I. Pointers and Address Management**

  * **Concept:** Understanding how to declare a pointer, assign the address of a variable to it, and dereference it to access the value.

**Review Question 1:**
Given an integer variable `score` initialized to 100, write the following C++ code:

1.  A declaration for an **integer pointer** named `ptrScore`.
2.  A statement to store the **memory address** of `score` into `ptrScore`.
3.  A statement that **changes the value of `score` to 95** using only the pointer variable `ptrScore`.

**Answer:**

```cpp
int score = 100;
int *ptrScore;
ptrScore = &score;
*ptrScore = 95;
```

-----

### **II. Pointers and Array Traversal**

  * **Concept:** Using pointer arithmetic to access elements within an array.

**Review Question 2:**
An integer array is declared and initialized as `int data[5] = {10, 20, 30, 40, 50};`. A pointer is set to the start of the array: `int *dataPtr = data;`.
Write a C++ statement that prints the value of the **fourth element** (which is 40) using only the pointer `dataPtr` and pointer arithmetic.

**Answer:**

```cpp
// Since arrays are zero-indexed, the fourth element is at index 3.
// We add 3 to the base address and then dereference.
cout << *(dataPtr + 3);
```

-----

### **III. Dynamic Memory Allocation (`new` and `delete`)**

  * **Concept:** Allocating memory for a single variable and releasing it.

**Review Question 3:**
Write the C++ code required to **dynamically allocate** memory to hold a **float** value. Store the address of this new memory in a pointer variable named `fPtr`. Then, store the value $\pi$ (use **3.14159**) in the dynamically allocated memory. Finally, write the statement to **deallocate** this memory.

**Answer:**

```cpp
float *fPtr = new float;
*fPtr = 3.14159;
// ... (rest of the program execution)
delete fPtr;
```

-----

### **IV. Dynamic Array Allocation and Deallocation**

  * **Concept:** Allocating an array in dynamic memory and correctly freeing it.

**Review Question 4:**
Write C++ code to dynamically allocate an array capable of storing **50 `char` characters**. Store the base address in a pointer named `charArrPtr`. Write the necessary statement to **free** this dynamically allocated array memory.

**Answer:**

```cpp
char *charArrPtr = new char[50];
// ... (program uses the array)
delete [] charArrPtr;
```

-----

### **V. File Input/Output (I/O) - Writing**

  * **Concept:** Opening a file, writing data to it, and closing it.

**Review Question 5:**
Given an array of temperatures `int hourlyTemps[4] = {85, 88, 92, 90};`, write a complete C++ program snippet (including necessary declarations and includes) that uses a **loop** to **write all four values** to a text file named **"temps.dat"**, each on a **new line**. Be sure to open and close the file.

**Answer:**

```cpp
#include <fstream>
// ...

int hourlyTemps[4] = {85, 88, 92, 90};
std::ofstream outFile;

outFile.open("temps.dat");

for (int i = 0; i < 4; i++) {
    outFile << hourlyTemps[i] << std::endl;
}

outFile.close();
```

-----

### **VI. File Input/Output (I/O) - Reading and Processing**

  * **Concept:** Reading a file until the end, performing an operation (like finding the smallest value), and managing file state.

**Review Question 6:**
Write a C++ program snippet to read integers from a file named **"numbers.txt"** until the end of the file is reached. Your code should **find and print the smallest number** that was read from the file.

**Answer:**

```cpp
#include <fstream>
#include <limits> // For numeric_limits

// ...
int num;
int smallest = std::numeric_limits<int>::max(); // Initialize to largest possible int
std::ifstream inFile;

inFile.open("numbers.txt");

if (inFile) {
    while (inFile >> num) {
        if (num < smallest) {
            smallest = num;
        }
    }
    
    // Only print if at least one number was read
    if (smallest != std::numeric_limits<int>::max()) {
        std::cout << "The smallest number is: " << smallest << std::endl;
    } else {
        std::cout << "File is empty or could not be read." << std::endl;
    }
    
    inFile.close();
} else {
    std::cout << "Error: Could not open file." << std::endl;
}
```

-----

### **VII. C-Style Strings (Character Arrays)**

  * **Concept:** Storing and manipulating text in character arrays using `strcpy`.

**Review Question 7:**
Given the declaration `char city[30];`, write the C++ code (including any necessary includes) to store the phrase **"New York City"** into the `city` array.

**Answer:**

```cpp
#include <cstring>
// ...

char city[30];
strcpy(city, "New York City");
```

-----

### **VIII. C++ `string` Class**

  * **Concept:** Storing and manipulating text using the `string` class.

**Review Question 8:**
Given the declaration `std::string address;`, write the C++ code to assign the value **"123 Main St"** to the `address` variable.

**Answer:**

```cpp
std::string address;
address = "123 Main St";
```

-----

### **IX. C++ `string` Input and Comparison**

  * **Concept:** Reading an entire line of input that may contain spaces, and comparing strings.

**Review Question 9:**
Write a C++ program snippet that prompts the user to enter their **favorite color**. It should store the entire line of input in a `std::string` variable called `color`. Then, use an **`if` statement** to check if the color entered is exactly **"Deep Blue"** (case-sensitive) and print "That's my favorite too\!" if it is.

**Answer:**

```cpp
#include <iostream>
#include <string>

// ...
std::string color;
std::cout << "Enter your favorite color: ";
// Use getline to capture the full line, including spaces
std::getline(std::cin, color); 

if (color == "Deep Blue") {
    std::cout << "That's my favorite too!" << std::endl;
}
```

Would you like to focus on specific topics from this review (Pointers, Files, Strings, etc.) or go over any of the answers in more detail?
