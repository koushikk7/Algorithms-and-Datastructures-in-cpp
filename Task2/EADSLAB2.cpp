#include <iostream>
#include "EADSLAB2.hpp"
using namespace std;

int main() {

    cout << "TESTS ON CLASS RING:" << endl << endl;

    cout << "1. TESTS ON EMPTY LIST:" << endl << endl << endl;

    cout << "creating an empty list (list1):" << endl;
    Ring<int, int> list1;
    cout << "Size of the list after calling constructor: " << list1.size();
    cout << endl << "Is this list empty?: " << list1.empty();

    cout << endl << endl << endl << "2. pushfront, popback, empty, size and clear FUNCTIONS TESTS" << endl << endl << endl;

    cout << "Let's add an element to the empty list (1,11) using pushFront:" << endl;
    list1.pushFront(1, 11);
    cout << "Our list after adding the first element using pushFront:";
    list1.print();
    cout << "Is this list empty now?: " << list1.empty() << endl;;
    cout << "Size of the list after adding first element: " << list1.size() << endl;
    
    cout << endl << "Now let's clear the list add an element to the empty list (1,11) using pushBack:" << endl;
    list1.clear();
    list1.pushBack(1, 11);
    cout << "Our list after adding the first element using pushBack:";
    list1.print();

    cout << endl << "Now let's add 4 more elements to the front and 4 more elements to the back of the list:" << endl;
    list1.pushFront(2, 12);
    list1.pushFront(3, 13);
    list1.pushFront(4, 14);
    list1.pushFront(5, 15);
    list1.pushBack(5, 15);
    list1.pushBack(6, 16);
    list1.pushBack(7, 17);
    list1.pushBack(8, 18);
    cout << "Our list after adding new elements:";
    list1.print();
    cout << "Is this list empty now?: " << list1.empty() << endl;
    cout << "Size of the list after adding 8 elements: " << list1.size() << endl;

    cout << endl << endl << "Now let's remove 1 element from both the front and the back of the list:" << endl;
    list1.popFront();
    list1.popBack();
    cout << "Our list after removing 1 element from the front and the back:";
    list1.print();
    cout << "Is this list empty now?: " << list1.empty() << endl;;
    cout << "Size of the list after removing 2 elements: " << list1.size() << endl;

    cout << endl << endl << "3. COPY CONSTRUCTOR AND OPERATOR= TESTS:" << endl << endl << endl;

    cout << "Now let's create a new list (list2) and initialize it to list1 using copy constructor:" << endl;
    Ring<int, int> list2 = list1;
    cout << "list2 after calling copy constructor and initializing it to list1:";
    list2.print();

    cout << endl << "Now let's clear list2 and copy list1 to list2 again, this time using operator= directly:" << endl;
    list2.clear();
    cout << endl << "Size of list2 after calling clear: " << list2.size();
    cout << endl << "Is list2 empty?: " << list2.empty() << endl << endl;
    list2 = list1;
    cout << "list2 after copying list1 contents to it using operator= :";
    list2.print();

    cout << endl << "4. insertAfterSearchedKey FUNCTION TESTS:" << endl << endl << endl;

    cout << "Let's clear list1 and try to insert an element there using insertAfterSearchedKey function:" << endl;
    list1.clear();
    cout << endl << "Is list1 empty now?: " << list1.empty() << endl;
    cout << "Result of calling insertAfterSearchedKey on list1:";
    list1.insertAfterSearchedKey(9, 19, 2, 4);
    
    cout << endl << "Let's initialize list1 back to list2 now:" << endl;
    list1 = list2;
    cout << "list1 now:";
    list1.print();
    
    cout << "Result of calling insertAfterSearchedKey on list1 and setting desired number of occurrences as 0:";
    list1.insertAfterSearchedKey(5, 15, 0, 4);

    cout << endl << "Result of calling insertAfterSearchedKey on list1, setting searched key as 4, and setting desired number of occurrences as 1:";
    list1.insertAfterSearchedKey(5, 15, 1, 4);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling insertAfterSearchedKey on list1, setting searched key as 5, and setting desired number of occurrences as 2:";
    list1.insertAfterSearchedKey(9, 19, 2, 5);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling insertAfterSearchedKey on list1, setting searched key as 100, and setting desired number of occurrences as 2:";
    list1.insertAfterSearchedKey(10, 20, 2, 100);
    cout << "list1 now:";
    list1.print();

    cout << endl << "5. removeSearchedKey FUNCTION TESTS:" << endl << endl << endl;
    
    cout << "clearing list1 and trying to remove an element there using removeSearchedKey function:" << endl;
    list2 = list1;
    list1.clear();
    cout << endl << "Is list1 empty now?: " << list1.empty() << endl;
    cout << "Result of calling removeSearchedKey on list1:";
    list1.removeSearchedKey(2, 4);
    
    cout << endl << "Let's initialize list1 back to its former self:" << endl;
    list1 = list2;
    cout << "list1 now:";
    list1.print();
    
    cout << "Result of calling removeSearchedKey on list1 and setting desired number of occurrences as 0:";
    list1.removeSearchedKey(0, 4);

    cout << endl << "Result of calling removeSearchedKey on list1, setting removed key as 4, and setting desired number of occurrences as 1:";
    list1.removeSearchedKey(1, 4);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling removeSearchedKey on list1, setting searched key as 5, and setting desired number of occurrences as 2:";
    list1.removeSearchedKey(2, 5);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling removeSearchedKey on list1, setting searched key as 100, and setting desired number of occurrences as 1:";
    list1.removeSearchedKey(1, 100);
    cout << "list1 now:";
    list1.print();
    
    cout << endl << "6. insertAfterEachOccurrence FUNCTION TESTS:" << endl << endl << endl;

    cout << endl << "Result of calling insertAfterEachOccurrence on list1 and setting searched key as 100:";
    list1.insertAfterEachOccurrence(4, 14, 100);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling insertAfterEachOccurrence on list1, setting searched key as 2 and new key as 7:";
    list1.insertAfterEachOccurrence(7, 17, 2);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling insertAfterEachOccurrence on list1, setting searched key as 9 and new key as 7:";
    list1.insertAfterEachOccurrence(7, 17, 9);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling insertAfterEachOccurrence on list1, setting searched key as 7 and new key as 4:";
    list1.insertAfterEachOccurrence(4, 14, 7);
    cout << "list1 now:";
    list1.print();

    cout << endl << "7. removeEachOccurrence FUNCTION TESTS:" << endl << endl << endl;
    
    cout << "For testing purposes, let's add two elements to the front of list1:" << endl;
    list1.pushFront(6, 16);
    list1.pushFront(6, 16);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling removeEachOccurrence on list1, setting searched key as 6 (quite difficult task, as it requires removal change of head twice):";
    list1.removeEachOccurrence(6);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling removeEachOccurrence on list1, setting searched key as 100:";
    list1.removeEachOccurrence(100);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling removeEachOccurrence on list1, setting searched key as 4:";
    list1.removeEachOccurrence(4);
    cout << "list1 now:";
    list1.print();

    cout << endl << "8. insertAfterNthElement FUNCTION TESTS:" << endl << endl << endl;

    cout << endl << "Result of calling insertAfterNthElement on list1, setting new key as 4 and after_which_node as 100:";
    list1.insertAfterNthElement(4, 14, 100);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling insertAfterNthElement on list1, setting new key as 4 and after_which_node as 0:";
    list1.insertAfterNthElement(4, 14, 0);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling insertAfterNthElement on list1, setting new key as 8 and after_which_node as 8:";
    list1.insertAfterNthElement(8, 18, 8);
    cout << "list1 now:";
    list1.print();

    cout << endl << "9. removeNthElement FUNCTION TESTS:" << endl << endl << endl;

    cout << endl << "Result of calling removeNthElement on list1, setting which_node as 100:";
    list1.removeNthElement(100);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling removeNthElement on list1, setting which_node as 0:";
    list1.removeNthElement(0);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling removeNthElement on list1, setting which_node as 6:";
    list1.removeNthElement(6);
    cout << "list1 now:";
    list1.print();

    cout << endl << "10. adjustInfo FUNCTION TESTS:" << endl << endl << endl;

    cout << "Result of calling adjustInfo on list1 and setting desired number of occurrences as 0:";
    list1.adjustInfo(20, 0, 4);

    cout << endl << "Result of calling adjustInfo on list1, setting searched key as 5, and setting desired number of occurrences as 1:";
    list1.adjustInfo(20, 1, 5);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling adjustInfo on list1, setting searched key as 7, and setting desired number of occurrences as 2:";
    list1.adjustInfo(21, 2, 7);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling adjustInfo on list1, setting searched key as 100, and setting desired number of occurrences as 2:";
    list1.adjustInfo(22, 2, 100);
    cout << "list1 now:";
    list1.print();

    cout << "TESTS ON ITERATOR FUNCTIONS:" << endl << endl;

    cout << "First, let's create clear list2, create an iterator object and try to initialize it to head of list2:";
    list2.clear();
    Ring<int, int>::Iterator iterator1;
    iterator1.pointIteratorToHead(list2);
    
    cout << endl << "Now, let's initialize the iterator to head of list1:";

    iterator1.pointIteratorToHead(list1);

    cout << endl << "Now, let's insert an element after the iterator using insertAfterIterator method:";

    iterator1.insertAfterIterator(list1, 20, 200);
    cout << "list1 now:";
    list1.print();

    cout << "Now, let's set the iterator to point to an element containing key 1000:";
    iterator1.setIteratorToSearchedKey(list1, 1000);

    cout << endl << "Now, let's set the iterator to point to the element containing a key 3 and insert a new element after this element:";
    iterator1.setIteratorToSearchedKey(list1, 3);
    iterator1.insertAfterIterator(list1, 21, 210);
    cout << "list1 now:";
    list1.print();

    cout << "Now, let's set the iterator to point to the 7th element of list1 and remove the element after iterator:" << endl;
    iterator1.setIteratorToNthElement(list1, 7);
    iterator1.removeAfterIterator(list1);
    cout << "list1 now:";
    list1.print();

    cout << "Now, let's set the iterator to point to the rear of list1 and remove the element after the iterator:";
    iterator1.pointIteratorToRear(list1);
    iterator1.removeAfterIterator(list1);
    cout << "list1 now:";
    list1.print();
    

    cout << endl << "11. ADDITIONAL TESTS ON FUNCTIONS: insertAfterSearchedKey, removeSearchedKey and adjustInfo (tests of the interactive parts):" << endl << endl << endl;
    
    cout << endl << "Result of calling insertAfterSearchedKey on list1, setting searched key as 7, desired number of occurrences as 100, and new key as 4:";
    list1.insertAfterSearchedKey(4, 14, 100, 7);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling removeSearchedKey on list1, setting searched key as 7 and setting desired number of occurrences as 100:";
    list1.removeSearchedKey(100, 7);
    cout << "list1 now:";
    list1.print();

    cout << endl << "Result of calling adjustInfo on list1, setting searched key as 7 and desired number of occurrences as 100:";
    list1.adjustInfo(23, 100, 7);
    cout << "list1 now:";
    list1.print();

    list1.clear();

    cout << "END OF TESTS" << endl << endl;

    return 0;
}