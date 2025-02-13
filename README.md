# EADS Assignments

This repository contains three tasks completed as part of my **Algorithms and Data Structures (EADS)** course during my **6th semester (winter 2023)** at WUT. These tasks showcase my proficiency in implementing **data structures** and **algorithmic solutions** in C++.

## Project Structure
```
Algorithms-and-Datastructures-in-cpp/
│-- Task1/  # Implementation of Singly-Linked List
│   ├── EADSLAB1.h
│   ├── EADSLAB1.cpp
│   ├── EADSLAB1DOCUMENTATION.pdf
│
│-- Task2/  # Implementation of Doubly-Linked Ring
│   ├── EADSLAB2.hpp
│   ├── EADSLAB2.cpp
│   ├── EADSLAB1DOCUMENTATION.pdf
│
│-- Task3/  # AVL Tree and Word Counter
│   ├── avl_tree.h
│   ├── avl_tree_test.h
│   ├── avl_tree_test.cpp
│   ├──EADSLAB3DOCUMENTATION
│
│-- README.md  # This file
```

## Task 1: Singly-Linked List (Task1/)
Implemented a **templated singly-linked list** with various functionalities such as:
- Insertions, deletions, and sequence manipulation
- Overloaded operators for list comparisons and arithmetic operations
- Methods for retrieving and modifying elements based on keys and indexes
- Splitting the sequence by position and key

## Task 2: Doubly-Linked Ring (Task2/)
Implemented a **templated circular doubly-linked list** with the following features:
- Insertions and deletions at different positions
- Searching and modifying elements based on keys
- Iterators for efficient traversal and modifications
- Handling edge cases for insertions and deletions

## Task 3: AVL Tree & Word Counter (Task3/)
Developed an **AVL tree** with additional functionalities such as:
- Self-balancing binary search tree with insert, delete, and search operations
- `maxinfo_selector()` function to return elements with the highest values
- `count_words()` function to process text streams and count word occurrences efficiently
- Performance comparison of `count_words()` using AVL trees vs. `std::map`
