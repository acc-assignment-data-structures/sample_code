
**IF YOU SHOW UP AND TRY TO ANSWER ALL MY QUESTIONS, I WILL GIVE YOU AT LEAST 40% SCORE**

# FRIENDS
## CODE
- LOGIC ONLY
## QUESTION
- Understand how to use friend (review and learn use case)

# QUEUE - PRIORITY QUEUE
## CODE
- ch13_queue.cpp (code + logic)
- ch13_priority_queue (logic)

## QUESTIONS
- What are some popular use cases for queue and priority queues?

# OVERLOAD OPERATOR
## CODE
- ch13_overload_operator.cpp (logic)
- ch13_overload_operator_array.cpp (code + logic)

## QUESTION
- What is an overload operator:  Overloaded operators allow you to define custom behavior for operators (such as +, -, *, /, etc.) when they're applied to instances of your custom classes. 

# GRAPH:

## CODE
- ch16_graph.cpp (code + logic)
## QUESTION
- What are some popular use cases for Graph data structure?

# TREE:
## CODE:
- ch16_tree.cpp (code+logic)
- ch16_binary_tree_array.cpp (code+logic)
- ch16_binary_search_tree.cpp (logic)
- ch16_AVL_tree (logic)

## QUESTIONS:
### Introduction
Tree data structures are fundamental in computer science, used for hierarchically organizing data. There are several types of tree data structures, each with its unique properties and use cases. Here are some of the most commonly used types:

1. **Binary Tree**: A tree where each node has at most two children, referred to as the left child and the right child.

2. **Binary Search Tree (BST)**: A binary tree where for each node, all elements in the left subtree are less than the node, and all elements in the right subtree are greater. This property enables efficient searching, insertion, and deletion operations.

3. **AVL Tree**: A self-balancing binary search tree where the height of the two child subtrees of any node differs by no more than one. If at any time they differ by more than one, rebalancing is done to restore this property.

4. **Red-Black Tree**: Another type of self-balancing binary search tree where each node contains an extra bit for denoting the color of the node, either red or black. It enforces balancing constraints that ensure the tree remains balanced, leading to good worst-case guarantees for insertion, deletion, and lookup operations.

5. **Heap**: Although not a tree in the traditional sense of a hierarchical data structure, heaps are often implemented as binary trees. They are used to implement priority queues, with the heap property ensuring that the parent node is either greater than or equal to (in a max heap) or less than or equal to (in a min-heap) its child nodes.

### Tree Elements

The elements of a tree in data structures are metaphors borrowed from natural trees, helping to conceptualize the hierarchical organization of data. Here's an overview of the primary elements:

1. **Node**: A tree node is a fundamental part of a tree structure. It represents an individual element or a point in the tree. Each tree node can store data (such as values or information) and has pointers or references to other nodes. These pointers define the relationship between nodes in the tree. Specifically, in a tree structure:

- **Root Node**: The top node in a tree. It is the only node without a parent.
- **Parent Node**: A node that has one or more child nodes.
- **Child Node**: A node that has a parent node to which it is connected.
- **Siblings**: Nodes that share the same parent.

2. **Root**: The **root** is the topmost element of a tree, serving as the origin from which all other elements branch out. There is exactly one root per tree, and it is the only element without a parent. The root serves as the entry point to access any other element within the tree. Nodes in a tree structure are connected in a way that they start from the root node and branch out. The connection between nodes is typically represented by pointers (in languages like C or C++) or references (in languages like Java or Python).

3. **Leaves (Leaf Nodes)**; Leaf nodes are the nodes in a tree that do not have any children. They are the end points of the tree, where the structure terminates. Leaves are important because they represent the simplest form of nodes in the tree, containing data but not leading to any further nodes. In a metaphorical sense, just as leaves on a real tree are at the ends of branches, leaf nodes in a data structure tree are at the ends of the branches of the tree. 

4. **Branch**: A **branch** is not usually defined as a standalone element in data structures but rather as the connections between nodes. In a more abstract sense, a branch can refer to a part of the tree that extends from one node to its children. It symbolizes the relationship and hierarchy between different parts of the tree.

5. **Edge**: An **edge** is a connection between two nodes in the tree. It represents the parent-child relationship. The number of edges in a tree is always one less than the number of nodes because every node, except the root, is connected by exactly one incoming edge from its parent.
### Properties and Importance

- **Hierarchical Structure**: Trees are hierarchical data structures. The tree starts with a root node and expands into more nodes, branching out into leaves.
- **Path**: In a tree, there is exactly one unique path from the root node to any node in the tree, including to any leaf node.
- **Depth and Height**: The depth of a node is the number of edges from the root node to the node. The height of a tree is the maximum depth among all leaf nodes. Leaf nodes have a depth that can vary depending on their position in the tree and a height of 0.

### Applications

Both nodes and leaves are crucial for understanding and working with trees in computer science. They play key roles in various applications, including:

- **File Systems**: Representing directories (nodes) and files (leaves).
- **Decision Trees**: In machine learning, where decisions (nodes) lead to outcomes (leaves).
- **DOM (Document Object Model)**: In web development, where HTML elements are nodes, and text nodes are leaves.
- **Parsing Expressions**: In compilers, where operators and operands form nodes in an expression tree, and operands are often leaf nodes.

Understanding these basic concepts is essential for navigating more complex data structures and algorithms, such as binary trees, AVL trees, and B-trees, where the arrangement and operations on nodes and leaves determine the efficiency of data storage, retrieval, and manipulation.

### Tree Traversal
[Tree Traversal](https://www.youtube.com/watch?v=9RHO6jU--GU)

#### Bread-First Traversals: (LOGIC)
**Level-order Traversal**:
   - Visit nodes level by level from top to bottom.
   - This method is useful for printing the tree in level order or solving problems that require visiting nodes in a level-wise manner.

#### Depth-First Traversals: (CODE + LOGIC)

1. **In-order Traversal**:
   - Visit the left subtree.
   - Visit the root node.
   - Visit the right subtree.
   - This traversal method is commonly used because, for binary search trees, it retrieves data in sorted order.

2. **Pre-order Traversal**:
   - Visit the root node.
   - Visit the left subtree.
   - Visit the right subtree.
   - This method is useful for creating a copy of the tree or prefix notation expressions.

3. **Post-order Traversal**:
   - Visit the left subtree.
   - Visit the right subtree.
   - Visit the root node.
   - Useful for deleting the tree (since you delete children before the parent) or for postfix notation expressions.

### AVL Tree Balance Factor
The balance factor of a node in an AVL (Adelson-Velsky and Landis) tree is calculated as the height of its left subtree minus the height of its right subtree. This balancing factor is used to maintain the AVL tree's balance property, ensuring that the difference in heights of the left and right subtrees of any node is no more than 1. The balance factor can be -1, 0, or +1 for a balanced AVL tree, indicating that the right subtree is taller, both subtrees are of equal height, or the left subtree is taller, respectively.

#### Formula:
Here's the formula for calculating the balance factor BF of a node:

      BF(node)=Height(LeftSubtree)−Height(RightSubtree)

#### Calculating Heights:
To apply this formula, you first need a way to calculate the height of a subtree. The height of a subtree is the length of the longest path from the root of the subtree to a leaf node. A leaf node (a node with no children) has a height of 0, and a null pointer (indicating no subtree) has a height of -1 by convention to simplify calculations.

![AVL Trees Simply Rotation](https://www.youtube.com/watch?v=zP2xbKerIds&list=PLhXWHUoid1m3zVo6FxctHykQr81reE9hX)

### Structure of Graph & Tree family
```
/**
 * .
`-- Graph/
    `-- Tree/
        `-- Binary Tree/ (balance, complete, B(n)<=1)
            `-- Binary Search Tree/ (left data < right data)
               |-- Traversal/
               |   |-- Bread First Traversal
               |   `-- Depth First Traversal/
               |       |-- In-order Traversal: Left - Root - Right (LEFT, DATA, RIGHT)
               |       |-- Pre-order Traversal: Root - Left - Right (DATA, LEFT, RIGHT)
               |       `-- Post-order Traversal: Left - Right - Root (LEFT, RIGHT, DATA)
               `-- AVL Tree/ (left data < right data + self rotation)
                  |-- Traversal/
                  |   |-- Bread First Traversal
                  |   `-- Depth First Traversal
                  `-- Tree Rotations/ (B(n)>1)
                     |-- Left Heavy/
                     |  |-- Right Rotation (-2,-1)
                     |  `-- Left-Right Rotation
                     `-- Right Heavy/
                        |-- Left Rotation
                        `-- Right-Left Rotation
*/
```
# HEAP

# CODE:
- ch17_heap_array.cpp (logic)

# QUESTIONS:
- Heap? 
- Max Heap, Min Heap
- Heap Sort?
- https://www.codingdrills.com/tutorial/heap-data-structure/introduction-to-heap-data-structure
- https://www.youtube.com/watch?v=Dvq-YKeuO9Y 


# HASHING & DICTIONARY
## CODE:
- ch18_hashing.cpp
- ch18_hashingtable.cpp (code + logic)

## What is Hashing?

Hashing is a process used to transform a given input into a fixed-size string of bytes, known as the hash value, digest, or hash code. This string typically represents the input data uniquely and is used in various applications like data retrieval, integrity verification, and cryptography.

## Map vs. Unordermap

In C++, both `std::map` and `std::unordered_map` are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order. However, there are fundamental differences in their internal workings, performance characteristics, and the order in which elements are stored.

### `std::map`
- **Internal Structure**: `std::map` is typically implemented as a balanced binary tree (like a Red-Black Tree). 
- **Ordering**: It stores elements in a sorted order based on the key. The sorting criteria can be specified by a comparison function (less than by default).
- **Search Time**: Lookup operations (find, insert, delete) have logarithmic complexity (`O(log n)`).
- **Usage Scenario**: Use `std::map` when you need ordered data, or you frequently perform operations that require the container to be sorted.

### `std::unordered_map`
- **Internal Structure**: `std::unordered_map` is implemented using a hash table.
- **Ordering**: It does not store elements in any specific order. The order depends on the hash function and may change when rehashing occurs.
- **Search Time**: Provides average constant-time complexity (`O(1)`) for search operations, although this can degrade to linear (`O(n)`) in the worst case if there are many hash collisions.
- **Usage Scenario**: Use `std::unordered_map` when you need faster access and insertion and the order of elements is not important.

## Hash Table vs Dictionary:
 
The terms "hash table" and "dictionary" are often used interchangeably in the context of data structures, but they can have distinct meanings depending on the programming language or the specific implementation context. Here's a breakdown of how they are generally understood and used:

### Hash Table

- **Definition**: A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.
- **Key Characteristics**:
    - Uses a hash function to determine where to store each key-value pair.
    - Handles collisions through various methods like chaining (where each bucket is a linked list of entries that hash to the same index) or open addressing (where a collision triggers a search for another bucket according to a predefined sequence).
    - Efficiency: Ideally offers \(O(1)\) average time complexity for insert, delete, and search operations, although this can degrade to \(O(n)\) in the worst case (e.g., when all keys hash to the same index).
- **Use Cases**: Used internally by many programming languages for their dictionary or map implementations. Directly used in low-level programming or when specific customizations are needed.

### Dictionary

- **Definition**: A dictionary is an abstract data type that represents a collection of keys and values, with each key being unique within the collection. In many languages, dictionaries are implemented using hash tables, but this is not universally true.
- **Key Characteristics**:
    - Provides a high-level interface to add, remove, and access elements by keys.
    - The implementation may vary: while many languages use hash tables, others might use trees or other data structures to ensure order or provide different performance guarantees.
    - Efficiency: The performance of a dictionary depends on its underlying implementation but often aims for \(O(1)\) average time complexity for standard operations.
- **Use Cases**: Dictionaries are used in a wide range of applications, from storing simple configurations to complex data processing. They are a fundamental data structure in many high-level programming languages like Python (`dict`), JavaScript (objects as associative arrays), and C# (`Dictionary`).

## Collision Handling
- Double hashing uses a second hash function to determine the step size after a collision.
- Quadratic probing reduces clustering by using a quadratic function to calculate the probe sequence.
- Linear probing resolves collisions by moving sequentially through the hash table until an empty slot is found.

## Questions and Considerations:

- **Dictionary Mechanism**:
  - A variant of hashing that puts a key into a hash function to create a memory location.
- **Understanding Hash Functions**:
  - What they are and how they can achieve O(1) time complexity.
- **Collision Detection and Handling**:
  - Strategies for dealing with hash collisions, including pseudocode examples.
- **Use of Prime Numbers in Hashing**:
  - Why prime numbers are often used in the design of hash functions.

# Sort Algorithms
## CODE
- sort_implementation.cpp (logic)
- Only do merge sort and linear sort
## QUESTION
- Solve the Sort by hand.

# Search Algorithms
## CODE
- sort_implementation.cpp (Code + logic)
## QUESTION
- Solve the Search by hand.

## Binary Search 

- **Precondition**:
  - The array or vector must be sorted.

- **Logic**:
  ```python
  def binary_search(array, value):
      if not array:
          return -1

      left, right = 0, len(array) - 1

      while left <= right:
          midpoint = left + (right - left) // 2
          if array[midpoint] == value:
              return midpoint
          elif array[midpoint] < value:
              left = midpoint + 1
          else:
              right = midpoint - 1

      return -1
  ```

## Linear Search (Code + Logic)

- **Time Complexity**: O(n)
- **Example of nested loops**:
  ```cpp
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
              // Operation with time complexity of O(n^3)
          }
      }
  }
  ```

## Tree Search

- **Depth First Search**:(Code + Logic): 
  - **In-order Traversal**: Traverses left subtree, root, then right subtree. 
  - **Pre-order Traversal**: Traverses root, left subtree, then right subtree.
  - **Post-order Traversal**: Traverses left subtree, right subtree, then root.
