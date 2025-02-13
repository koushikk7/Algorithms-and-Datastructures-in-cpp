#include <iostream>
using namespace std;
template <typename Key, typename Info>

class Ring {
    private:
    struct Node {
        Key key;
        Info info;
        Node* next;
        Node* prev;
    };
    Node* head;
    friend class Iterator;
    public:
    class Iterator {
        private:
        Node* iterator;

        friend class Ring;

        public:
        Iterator(); //Constructor of Iterator
        ~Iterator(); //Sets iterator to point to nullptr
        bool pointIteratorToHead(const Ring<Key, Info>& source); //Sets iterator to point to the head of the ring
        bool pointIteratorToRear(Ring<Key, Info>& source); //Sets iterator to point to the last element of the ring
        bool setIteratorToSearchedKey(Ring<Key, Info>& source, const Key& searched_key); //Sets iterator to point to an element containing the given key (to the first occurance of the key, starting from the head)
        bool setIteratorToNthElement(Ring<Key, Info>& source, int which_element); //Sets iterator to point to a given (n-th) element (starting from the head)
        bool insertAfterIterator(Ring<Key, Info>& source, const Key& new_key, const Info& new_info); //Inserts a new element after the element which iterator points to
        bool removeAfterIterator(Ring<Key, Info>& source); //Removes an element after the element which iterator points to
        void copyElementsToRing(Ring<Key, Info>& ring, int len); //Copies chosen number of elements to the end of another ring, starting from an element that the iterator is pointing on
    };

    Ring();
    ~Ring();
    Ring(Ring& source);
    Ring<Key, Info>& operator=(Ring<Key, Info>& source); //Copies a list to a new one
    bool empty();
    int size();
    bool print();
    bool clear();
    void pushFront(const Key& new_key, const Info& new_info);
    bool popFront();
    void pushBack(const Key& new_key, const Info& new_info);
    bool popBack();
    bool insertAfterSearchedKey(const Key& new_key, const Info& new_info, int desired_number_of_occurances, const Key& searched_key); // Inserts an element in the ring after desired number of occurances of given key (starting from the head). If no occurances are found, the element isn't inserted. If the number of found occurances is lower than the desired one, the user is asked if he would like to insert the element after the last occurance of searched key (starting from the head)
    bool removeSearchedKey(int desired_number_of_occurrences, const Key& removed_key); //Removes an element containing the given key after given number of occurrences of the key (starting from the head). If no occurances are found, the element isn't removed. If the number of found occurances is lower than the desired one, the user is asked if he would like to remove the last occurance of searched key (starting from the head)
    bool insertAfterEachOccurrence(const Key& new_key, const Info& new_info, const Key& searched_key); //Inserts new elements after each occurrence of the given key
    bool removeEachOccurrence(const Key& removed_key); //Removes each occurrence of the given key from the ring
    bool insertAfterNthElement(const Key& new_key, const Info& new_info, int after_which_element); //Insert an element in the ring after the given number of elements (starting from the head). If the given number is 0, the new element will become the new head. If the given number of elements is higher than the size of the list, the new element won't be inserted
    bool removeNthElement(int which_element); //Removes an element from the ring after the given number of elements (starting from the head)
    bool adjustInfo(const Info& new_info, int desired_number_of_occurrences, const Key& searched_key); //Searches for an element containing given key and alters info in it at given number of occurances of the key (starting from the head). If no occurances are found, the info isn't altered. If the number of found occurances is lower than the desired one, the user is asked if he would like to alter the info at the last occurance of searched key (starting from the head)
};

template <typename Key, typename Info>
Ring<Key, Info>::Iterator::Iterator() {
    iterator = nullptr;
}

template <typename Key, typename Info>
Ring<Key, Info>::Iterator::~Iterator() {
    iterator = nullptr;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::pointIteratorToHead(const Ring<Key, Info>& source) {
    if(source.head == nullptr) {
        cout << endl << "The ring is empty, so iterator wasn't initialized" << endl;
        return false;
    }
    iterator = source.head;
    cout << endl << "The iterator is initialized to head" << endl;
    return true;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::pointIteratorToRear(Ring<Key, Info>& source) {
    if(source.empty()) {
        cout << endl << "The ring is empty, so iterator wasn't initialized" << endl;
        return false;
    }
    iterator = source.head -> prev;
    cout << endl << "The iterator is initialized to rear" << endl;
    return true;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::setIteratorToSearchedKey(Ring<Key, Info>& source, const Key& searched_key) {
    if(source.empty()) {
        cout << endl << "The ring is empty, so iterator wasn't initialized" << endl;
        return false;
    }
    Node* current_node = source.head;
    do {
        if(current_node -> key == searched_key) {
            iterator = current_node;
            cout << endl << "The iterator is initialized to the element containing the given key" << endl;
            return true;
        }
        current_node = current_node -> next;
    } while(current_node != source.head);
    cout << endl << "The given key wasn't found, so the iterator wasn't initialized" << endl;
    return false;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::setIteratorToNthElement(Ring<Key, Info>& source, int which_element) {
    if(which_element > source.size()) {
        cout << endl << "The list is too short - it doesn't contain an element on desired position. The iterator won't be initialized" << endl;
        return false;
    }
    if(which_element < 0) {
        cout << endl << "which_element < 0, so this call makes no sense. The iterator won't be initialized";
    }
    Node* current_node = source.head;
    int node_number = 1;
    do {
        if(node_number == which_element) {
            iterator = current_node;
            cout << endl << "The iterator is initialized to element " << node_number << ", as desired" << endl;
            return true;
        }
        current_node = current_node -> next;
        node_number++;
    } while(current_node != source.head);
}

template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::insertAfterIterator(Ring<Key, Info>& source, const Key& new_key, const Info& new_info) {
    if(iterator == nullptr) {
        cout << endl << "The iterator = nullptr, so the element can't be inserted" << endl;
        return false;
    }
    Node* new_node = new Node;
    new_node -> key = new_key;
    new_node -> info = new_info;
    new_node -> next = iterator -> next;
    new_node -> prev = iterator;
    iterator -> next -> prev = new_node;
    iterator -> next = new_node;
    cout << endl << "The element was inserted after the iterator" << endl;
    return true;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::Iterator::removeAfterIterator(Ring<Key, Info>& source) {
    if(iterator == nullptr) {
        cout << endl << "The iterator = nullptr, so the element can't be removed" << endl;
        return false;
    }
    if(iterator -> next == source.head) {
        source.popFront();
        cout << endl << "The element after iterator was removed" << endl;
        return true;
    }
    Node* to_delete = iterator -> next;
    iterator -> next = to_delete -> next;
    to_delete -> next -> prev = iterator;
    delete to_delete;
    cout << endl << "The element after iterator was removed" << endl;
    return true;
}


template <typename Key, typename Info>
void Ring<Key, Info>::Iterator::copyElementsToRing(Ring<Key, Info>& ring, int len) {
    if(iterator == nullptr) {
        return;
    }
    Node* current_node = iterator;
    int counter = 0;
    while(counter < len) {
        ring.pushBack(current_node -> key, current_node -> info);
        current_node = current_node -> next;
        counter++;
    }
    iterator = current_node;
}

template <typename Key, typename Info>
Ring<Key, Info>::Ring() {
    head = nullptr;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::empty() {
    return head == nullptr;
}

template <typename Key, typename Info>
int Ring<Key, Info>::size() {
    if(empty()) {
        return 0;
    }
    Node* current_node = head;
    int size = 0;
    do {
        size++;
        current_node = current_node -> next;
    } while(current_node != head);
    return size;
}

template <typename Key, typename Info>
void Ring<Key, Info>::pushFront(const Key& new_key, const Info& new_info) {
    pushBack(new_key, new_info);
    head = head -> prev;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::popFront() {
    if(empty() || size() == 1) {
        popBack();
    }
    Node* to_delete = head;
    to_delete -> prev -> next = to_delete -> next;
    to_delete -> next -> prev = to_delete -> prev;
    head = head -> next;
    delete to_delete;
    return true;
}

template <typename Key, typename Info>
void Ring<Key, Info>::pushBack(const Key& new_key, const Info& new_info) {
    Node* new_node = new Node;
    new_node -> key = new_key;
    new_node -> info = new_info;
    if(empty()) {
        head = new_node;
        new_node -> next = new_node;
        new_node -> prev = new_node;
        return;
    }
    new_node -> next = head;
    new_node -> prev = head -> prev;
    head -> prev -> next = new_node;
    head -> prev = new_node;
    return;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::popBack() {
    if(empty()) {
        return false;
    }
    if(size() == 1) {
        Node* to_delete = head;
        head = nullptr;
        delete to_delete;
        return true;
    }
    Node* to_delete = head -> prev;
    to_delete -> prev -> next = head;
    head -> prev = to_delete -> prev;
    delete to_delete;
    return true;
}
    
template <typename Key, typename Info>
bool Ring<Key, Info>::clear() {
    if(empty()) {
        return false;
    }
    while(!empty()) {
        popBack();
    }
    return true;
}

template <typename Key, typename Info>
Ring<Key, Info>::~Ring() {
    clear();
}

template <typename Key, typename Info>
Ring<Key, Info>& Ring<Key, Info>::operator=(Ring<Key, Info>& source) {
    if(this == &source) {
        return *this;  
    }
    clear();
    if(source.empty()) {
        return *this;
    }
    int number_of_repetitions_left = source.size();
    Node* current_node = source.head;
    while(number_of_repetitions_left != 0) {
        pushBack(current_node -> key, current_node -> info);
        current_node = current_node -> next;
        number_of_repetitions_left--; 
    }
    return *this;
}

template<typename Key, typename Info>
Ring<Key, Info>::Ring(Ring& source) {
    head = nullptr;
    *this = source;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::print() {
    if(empty()) {
        return false;
    }
    cout << endl << endl;
    Node* current_node = head;
    int counter = 1;
    do {
        cout << counter << ". key: " << current_node -> key << " | info: " << current_node -> info << endl;
        current_node = current_node -> next;
        counter++;
    } while(current_node != head);
    cout << endl;
    return true;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::insertAfterSearchedKey(const Key& new_key, const Info& new_info, int desired_number_of_occurances, const Key& searched_key) {
    if(desired_number_of_occurances <= 0) {
        cout << endl << "The requested number of occurances of searched key is <= 0, therefore this call makes no sense. The element won't be inserted" << endl;
        return false;
    }
    if(empty()) {
        cout << endl << "The list is empty, therefore no such element can be found. The element won't be inserted" << endl;
        return false;
    }
    Node* current_node = head;
    int number_of_occurances = 0;
    Node* last_occurance = nullptr;
    do {
        if(current_node -> key == searched_key) {
            number_of_occurances++;
            if(number_of_occurances == desired_number_of_occurances) {
                Node* new_node = new Node;
                new_node -> key = new_key;
                new_node -> info = new_info;
                new_node -> next = current_node -> next;
                new_node -> prev = current_node;
                current_node -> next -> prev = new_node;
                current_node -> next = new_node;
                cout << endl << "New element was inserted after " << number_of_occurances << " occurance of searched key, as desired" << endl;
                return true;
            }
            last_occurance = current_node;
        }
        current_node = current_node -> next;
    } while(current_node != head);
    if(number_of_occurances == 0) {
        cout << endl << "No occurances of given key were found on this list. The element won't be inserted" << endl;
        return false;
    }
    cout << endl << "The number of occurances of searched key on the list was lower than the requested one. Do you wish to insert the element after the last - " << number_of_occurances << " - occurance?" << endl;
    int choice;
    do {
        cout << endl  << "1 - Yes" << endl << "2 - No, don't insert the element at all" << endl;
        cin >> choice;        
    } while(choice < 1 || choice > 2);

    if(choice == 1) {
        Node* new_node = new Node;
        new_node -> key = new_key;
        new_node -> info = new_info;
        new_node -> next = last_occurance -> next;
        new_node -> prev = last_occurance;
        last_occurance -> next -> prev = new_node;
        last_occurance -> next = new_node;
        cout << endl << "New element was inserted after " << number_of_occurances << " occurance of searched key, as ordered" << endl;
        return true;
    }
    cout << "The element won't be inserted, as ordered" << endl;
    return false;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::removeSearchedKey(int desired_number_of_occurrences, const Key& removed_key) {
    if(desired_number_of_occurrences <= 0) {
        cout << endl << "The requested number of occurances of searched key is <= 0, therefore this call makes no sense. The element won't be removed" << endl;
        return false;
    }
    if(empty()) {
        cout << endl << "The list is empty, therefore no such element can be found. The element won't be removed" << endl;
        return false;
    }
    Node* current_node = head;
    int number_of_occurances = 0;
    Node* last_occurance = nullptr;
    do {
        if(current_node -> key == removed_key) {
            number_of_occurances++;
            if(number_of_occurances == desired_number_of_occurrences) {
                if(current_node == head) {
                    popFront();
                    current_node = nullptr;
                }
                else {
                    current_node -> prev -> next = current_node -> next;
                    current_node -> next -> prev = current_node -> prev;
                    delete current_node;
                }
                cout << endl << "the element was removed on " << number_of_occurances << " occurance of searched key, as desired" << endl;
                return true;
            }
            last_occurance = current_node;
        }
        current_node = current_node -> next;
    } while(current_node != head);
    if(number_of_occurances == 0) {
        cout << endl << "No occurances of given key were found on this list. The element won't be removed" << endl;
        return false;
    }
    cout << endl << "The number of occurances of searched key on the list was lower than the requested one. Do you wish to remove the last - " << number_of_occurances << " - occurance?" << endl;
    int choice;
    do {
        cout << endl  << "1 - Yes" << endl << "2 - No, don't remove the last occurance" << endl;
        cin >> choice;        
    } while(choice < 1 || choice > 2);

    if(choice == 1) {
       if(last_occurance == head) {
            popFront();
            current_node = nullptr;
        }
        else {
            last_occurance -> prev -> next = last_occurance -> next;
            last_occurance -> next -> prev = last_occurance -> prev;
            delete last_occurance;
        }
        cout << endl << "the element was removed on " << number_of_occurances << " occurance of searched key, as desired" << endl;
        return true;
    }
    cout << "The last occurance won't be removed, as ordered" << endl;
    return false;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::insertAfterEachOccurrence(const Key& new_key, const Info& new_info, const Key& searched_key) {
    if(empty()) {
        cout << endl << "The list is empty, therefore no such element can be found. The element won't be inserted" << endl;
        return false;
    }
    Node* current_node = head;
    int number_of_insertions = 0;
    do {
        if(current_node -> key == searched_key) {
            Node* new_node = new Node;
            new_node -> key = new_key;
            new_node -> info = new_info;
            new_node -> next = current_node -> next;
            new_node -> prev = current_node;
            current_node -> next -> prev = new_node;
            current_node -> next = new_node;
            number_of_insertions++;
        }
        current_node = current_node -> next;
    } while(current_node != head);
    if(number_of_insertions == 0) {
        cout << endl << "No occurances of given key were found, so no elements will be inserted" << endl;
        return false;
    }
    cout << endl << number_of_insertions << " new elements were inserted" << endl;
    return true;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::removeEachOccurrence(const Key& removed_key) {
    if(empty()) {
        cout << endl << "The list is empty, therefore no such element can be found. No element will be removed" << endl;
        return false;
    }
    int number_of_removals = 0;
    while(head -> key == removed_key) {
        popFront();
        number_of_removals++;
        if(empty()) {
            cout << endl << number_of_removals << " elements were removed" << endl;
            return true;
        }
    }
    Node* current_node = head -> next;
    while(current_node != head) {
        if(current_node -> key == removed_key) {
            Node* to_delete = current_node;
            to_delete -> prev -> next = to_delete -> next;
            to_delete -> next -> prev = to_delete -> prev;
            current_node = current_node -> next;
            delete to_delete;
            number_of_removals++;
        }
        else {
            current_node = current_node -> next;
        }
    }
    if(number_of_removals == 0) {
        cout << endl << "No occurances of given key were found, so no elements were removed" << endl;
        return false;
    }
    cout << endl << number_of_removals << " elements were removed" << endl;
    return true;
}

template <typename Key, typename Info>
bool Ring<Key, Info>::insertAfterNthElement(const Key& new_key, const Info& new_info, int after_which_element) {
    if(after_which_element > size()) {
        cout << endl << "The list is too short - it doesn't contain an element on desired position. The node won't be inserted" << endl;
        return false;
    }
    if(after_which_element < 0) {
        cout << endl << "after_which_element < 0, so this call makes no sense. This node won't be inserted";
    }
    if(after_which_element == 0) {
        pushFront(new_key, new_info);
        cout << endl << "The node was inserted at the front of the list, as desired" << endl;
        return true;
    }
    Node* current_node = head;
    int node_number = 1;
    do {
        if(node_number == after_which_element) {
            Node* new_node = new Node;
            new_node -> key = new_key;
            new_node -> info = new_info;
            new_node -> next = current_node -> next;
            new_node -> prev = current_node;
            current_node -> next -> prev = new_node;
            current_node -> next = new_node;
            cout << endl << "The node was inserted after node " << node_number << ", as desired" << endl;
            return true;
        }
        current_node = current_node -> next;
        node_number++;
    } while(current_node != head);
}

template <typename Key, typename Info>
bool Ring<Key, Info>::removeNthElement(int which_element) {
     if(which_element > size()) {
        cout << endl << "The list is too short - it doesn't contain an element on desired position. The element won't be removed" << endl;
        return false;
    }
    if(which_element <= 0) {
        cout << endl << "after_which_element <= 0, so this call makes no sense. This node won't be inserted" << endl;
    }
    if(which_element == 1) {
        popFront();
        cout << endl << "The first element of the list was removed, as desired" << endl;
        return true;
    }
    Node* current_node = head -> next;
    int node_number = 2;
    while(current_node != head) {
        if(node_number == which_element) {
            current_node -> prev -> next = current_node -> next;
            current_node -> next -> prev = current_node -> prev;
            delete current_node;
            cout << endl << "Node " << node_number << " was removed, as desired" << endl;
            return true;
        }
        current_node = current_node -> next;
        node_number++;
    }
}

template <typename Key, typename Info>
bool Ring<Key, Info>::adjustInfo(const Info& new_info, int desired_number_of_occurrences, const Key& searched_key) {
    if(desired_number_of_occurrences <= 0) {
        cout << endl << "The requested number of occurances of searched key is <= 0, therefore this call makes no sense. The info won't be altered" << endl;
        return false;
    }
    if(empty()) {
        cout << endl << "The list is empty, therefore no such element can be found. The info won't be altered" << endl;
        return false;
    }
    Node* current_node = head;
    int number_of_occurances = 0;
    Node* last_occurance = nullptr;
    do {
        if(current_node -> key == searched_key) {
            number_of_occurances++;
            if(number_of_occurances == desired_number_of_occurrences) {
                current_node -> info = new_info;
                cout << endl << "The info was altered at " << number_of_occurances << " occurance of searched key, as desired" << endl;
                return true;
            }
            last_occurance = current_node;
        }
        current_node = current_node -> next;
    } while(current_node != head);
    if(number_of_occurances == 0) {
        cout << endl << "No occurances of given key were found on this list. The info won't be altered" << endl;
        return false;
    }
    cout << endl << "The number of occurances of searched key on the list was lower than the requested one. Do you wish to alter the info at the last - " << number_of_occurances << " - occurance?" << endl;
    int choice;
    do {
        cout << endl  << "1 - Yes" << endl << "2 - No, don't alter the info at all" << endl;
        cin >> choice;        
    } while(choice < 1 || choice > 2);

    if(choice == 1) {
        last_occurance -> info = new_info;
        cout << endl << "The info was altered at " << number_of_occurances << " occurance of searched key, as ordered" << endl;
        return true;
    }
    cout << "The info won't be altered, as ordered" << endl;
    return false;
}
