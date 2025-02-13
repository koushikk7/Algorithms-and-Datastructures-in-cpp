# EADS Lab Assignments

This repository contains three tasks completed as part of my **Algorithms and Data Structures (EADS)** course during my **6th semester** at WUT. These tasks showcase my proficiency in implementing **data structures** and **algorithmic solutions** in C++.

## Project Structure
```
EADS-Tasks/
│-- task1/  # Implementation of Singly-Linked List
│   ├── sequence.h
│   ├── sequence.cpp
│   ├── sequence_test.cpp
│
│-- task2/  # Implementation of Doubly-Linked Ring
│   ├── ring.h
│   ├── ring.cpp
│   ├── ring_test.cpp
│
│-- task3/  # AVL Tree and Word Counter
│   ├── avl_tree.h
│   ├── avl_tree.cpp
│   ├── avl_tree_test.cpp
│   ├── word_counter.cpp
│
│-- README.md  # This file
```

## Task 1: Singly-Linked List (task1/)
Implemented a **templated singly-linked list** with various functionalities such as:
- Insertions, deletions, and sequence manipulation
- Overloaded operators for list comparisons and arithmetic operations
- Methods for retrieving and modifying elements based on keys and indexes
- Splitting the sequence by position and key

## Task 2: Doubly-Linked Ring (task2/)
Implemented a **templated circular doubly-linked list** with the following features:
- Insertions and deletions at different positions
- Searching and modifying elements based on keys
- Iterators for efficient traversal and modifications
- Handling edge cases for insertions and deletions

## Task 3: AVL Tree & Word Counter (task3/)
Developed an **AVL tree** with additional functionalities such as:
- Self-balancing binary search tree with insert, delete, and search operations
- `maxinfo_selector()` function to return elements with the highest values
- `count_words()` function to process text streams and count word occurrences efficiently
- Performance comparison of `count_words()` using AVL trees vs. `std::map`

## Why This Repository?
This repository serves as a showcase of my **algorithmic problem-solving skills** and **data structure implementations**. It demonstrates my ability to work with **efficient, modular, and reusable code** in C++.

## How to Run
To compile and run tests for each task:
```bash
# Compile using g++
g++ -o task1_test task1/sequence.cpp task1/sequence_test.cpp -std=c++17
./task1_test

g++ -o task2_test task2/ring.cpp task2/ring_test.cpp -std=c++17
./task2_test

g++ -o task3_test task3/avl_tree.cpp task3/avl_tree_test.cpp task3/word_counter.cpp -std=c++17
./task3_test
```
