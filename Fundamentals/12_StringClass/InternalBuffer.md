# std::striing vs string literals

It's important to differentiate std::string from string literals (e.g., "Hello"). String literals are sequences of characters stored in read-only memory and are immutable.


When you write:

```C++
std::string s = "Hello";
```

You are creating a mutable std::string object and initializing it with the immutable string literal "Hello". The std::string object's internal buffer can be changed, while the original literal remains untouched.

-----

## 💾 The Internal Buffer

The key to understanding why `std::string` is mutable lies in its **internal memory management**.

A `std::string` object is essentially a smart wrapper around a dynamically allocated array of characters (its "buffer").

  * When you declare `std::string s = "hello";`, the `std::string` object allocates memory on the **heap** to hold the characters 'h', 'e', 'l', 'l', 'o', and the null terminator ('\\0').
  * The `std::string` object itself (which holds the pointer to the buffer, its size, and capacity) lives on the **stack**.

Since the buffer is on the heap and managed by the `std::string` class, the class methods (`+=`, `insert()`, `erase()`, etc.) are designed to safely **modify this buffer in place**.

## 🔄 Reallocation and Capacity

Mutability often involves changing the **size** of the string, which can trigger a process called **reallocation**.

1.  **Initial State:** A string has a specific **size** (number of characters) and **capacity** (total allocated space, which is usually $\ge$ size).
2.  **Growth:** When you use an operation like `s += " World"` and the string's current capacity is too small, the `std::string` object performs the following steps:
      * It allocates a **larger** block of memory (e.g., usually doubling the current capacity).
      * It copies the existing characters from the old block to the new block.
      * It copies the new characters (" World") into the new block.
      * It **deallocates** the old, smaller memory block.
      * It updates its internal pointer to point to the new, larger memory block.

This process allows the string to grow dynamically, maintaining the appearance of a single, mutable sequence, even though the underlying memory location might change.

-----

## 🆚 Mutability vs. Immutability in Action

The difference between C++ (`std::string`) and Python (`str`) strings becomes clear when we look at **concatenation**:

| Concept | C++ (`std::string` - Mutable) | Python (`str` - Immutable) |
| :--- | :--- | :--- |
| **Operation** | `s += " World"` | `s = s + " World"` |
| **Memory Change** | **May modify the existing buffer.** If capacity is sufficient, no new allocation is needed. If capacity is exceeded, it reallocates and updates the existing `s` object. | **Always creates a new object.** The old `s` object remains unchanged, and the variable `s` is reassigned to point to the new, longer string object. |
| **Identity** | The **address** of the `std::string` object on the stack remains the same. The internal buffer address *might* change during reallocation, but the *object* is the same. | The `s` variable now points to a completely **different** memory location (a new string object). |

## ❗ Mutability and `const`

The concept of mutability is directly tied to the C++ keyword **`const`**.

  * A standard `std::string` object is **mutable** because its contents can be changed.
  * If you declare it as `const`, you make the **object itself** immutable, preventing any changes to its contents:

<!-- end list -->

```cpp
const std::string s = "fixed";

// This would result in a compilation error:
// s += " text";
```