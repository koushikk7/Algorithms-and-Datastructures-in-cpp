#include "avl_tree_test.h"
#include <sstream>
#include <cassert>
#include <iostream>
#include <chrono>
#include <fstream>
#include <map>

void test_insert() {
    avl_tree<int, std::string> tree;

    tree.insert(1, "one");
    assert(tree.contains(1));
    assert(tree[1] == "one");

    tree.insert(2, "two");
    assert(tree.contains(2));
    assert(tree[2] == "two");

    assert(tree.validate_bst_property());
    assert(tree.is_balanced());
    std::cout << "insert tests passed." << std::endl;

}

void test_remove() {
    avl_tree<int, std::string> tree;

    // Insert some elements
    tree.insert(1, "One");
    tree.insert(2, "Two");
    tree.insert(3, "Three");

    tree.remove(1);
    assert(!tree.contains(1));


    // Validate BST property and balance
    assert(tree.validate_bst_property());
    assert(tree.is_balanced());
    std::cout << "remove tests passed." << std::endl;

}

void test_find() {
    avl_tree<int, std::string> tree;

    // Insert some elements
    tree.insert(1, "One");
    tree.insert(2, "Two");
    tree.insert(3, "Three");

    assert(tree.contains(1));
    assert(!tree.contains(99));  // Assuming 99 was not inserted

    // Additional assertions for contains()
    assert(tree.contains(2));
    assert(tree.contains(3));
    std::cout << "contain tests passed." << std::endl;

}


void test_operator_brackets() {
    avl_tree<int, std::string> tree;

    tree.insert(1, "one");
    assert(tree.contains(1));
    assert(tree[1] == "one");

    tree.insert(2, "two");
    assert(tree.contains(2));
    assert(tree[2] == "two");

    assert(tree[1] == "one");
    try {
        std::string value = tree[99];  // Assuming 99 was not inserted
        assert(false); // Should not reach this point
    } catch (const std::range_error& e) {
        assert(true); // Correctly throws an exception
    }
    std::cout << "operator[] tests passed." << std::endl;

}

void test_maxinfo_selector() {
    avl_tree<int, int> tree;

    // Insert elements with varying 'info' values
    tree.insert(10, 100);
    tree.insert(20, 85);
    tree.insert(5, 90);
    tree.insert(30, 75);
    tree.insert(25, 110);
    tree.insert(15, 95);

    // Use maxinfo_selector to get the top 3 elements with the highest 'info' values
    auto max_elements = avl_tree<int, int>::maxinfo_selector(tree, 3);

    // Validate that max_elements contains the correct nodes
    assert(max_elements.size() == 3);
    // The elements should be in descending order based on 'info' value
    assert(max_elements[0].first == 25 && max_elements[0].second == 110);
    assert(max_elements[1].first == 10 && max_elements[1].second == 100);
    assert(max_elements[2].first == 15 && max_elements[2].second == 95);

    // Further validation to ensure that the tree structure is not broken after the operation
    assert(tree.is_balanced());
    assert(tree.validate_bst_property());

    std::cout << "Maxinfo selector tests passed." << std::endl;
}

void test_count_words() {
    std::string text = "hello world hello AVL tree";
    std::istringstream iss(text);
    auto word_count = avl_tree<std::string, int>::count_words(iss);

    assert(word_count["hello"] == 2);
    assert(word_count["world"] == 1);
    assert(word_count["AVL"] == 1);
    assert(word_count["tree"] == 1);
    assert(word_count.size() == 4);

  std::cout << "count_words tests passed." << std::endl;

}

std::map<std::string, int> count_words_with_map(std::istream& is) {
    std::map<std::string, int> word_count;
    std::string word;
    while (is >> word) {
        ++word_count[word];
    }
    return word_count;
}

int main() {
    try {
        test_insert();
        test_remove();
        test_find();
        test_operator_brackets();
        test_maxinfo_selector();
        test_count_words();

        std::cout << "All AVL tree tests passed successfully." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
    }

    std::cout << "\nCOMPARISION OF ELAPSED TIMES" << std::endl;

    avl_tree<std::string, int> word_count_tree;

    std::ifstream file("beagle_voyage.txt"); // Make sure the text file is in the correct directory
    if (!file) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    // We will measure the elapsed time in milliseconds
    std::chrono::milliseconds elapsed_time(0);

    for (int rep = 0; rep < 5; ++rep) {
        auto start_time = std::chrono::high_resolution_clock::now();

        // Perform the word counting
        word_count_tree = avl_tree<std::string, int>::count_words(file);

        auto end_time = std::chrono::high_resolution_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        std::cout << "Elapsed time with count_words: " << elapsed_time.count() << " ms.\n";
        // Reset the EOF flag and seek to the beginning to read again
        file.clear();
        file.seekg(0, std::ios::beg);
    }

    std::cout << std::endl;

    std::chrono::milliseconds elapsed_time_map(0);

    for (int rep = 0; rep < 5; ++rep) {
        auto start_time_map = std::chrono::high_resolution_clock::now();

        // Perform the word counting with std::map
        auto word_count_map = count_words_with_map(file);

        auto end_time_map = std::chrono::high_resolution_clock::now();
        elapsed_time_map = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_map - start_time_map);

        std::cout << "Elapsed time with std::map: " << elapsed_time_map.count() << " ms.\n";

        // Reset the EOF flag and seek to the beginning to read again
        file.clear();
        file.seekg(0, std::ios::beg);
    }
    std::cout << std::endl;
    return 0;
}

