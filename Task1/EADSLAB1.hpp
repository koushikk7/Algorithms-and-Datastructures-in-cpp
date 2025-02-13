//Sai Koushik Neriyanuri (317100)

#pragma once
#ifndef EADSLAB1_HPP
#define EADSLAB1_HPP
#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename Info>
class Sequence {

private:
    struct Node {
        Key key;
        Info info;
        Node* next;

        Node(const Key& k, const Info& i, Node* _next = nullptr){
            key = k;
            info = i;
            next = _next;
        };
    };

    //structure Node is a well-known singly-linked list elements with
    //template types as Key key responsible for storing the key of the node
    //and Info info responsible for storing data of the element
    //it also contains the Node* next pointer which poins to the next element in the singly-linked list

    Node* head;
    //pointer which points to the first element of the singly-linked list

    int Sequence_length;
    //length of the sequence

    void printNode(Node*& curr) const;
    //private method which displays all the information about the particular node which is passed to this method

    void copySequence(const Sequence<Key, Info>& copy);
    //this function is used for copying contents of one sequence into another

public:

    Sequence();
    //constructor of the Sequence class which sets the head pointer to the nullptr

    ~Sequence();
    //destructor of the Sequence class instance which uses the public method clearSequence()
    //which deletes all the elements of singly-linked list and what is more important
    //free the memory taken by the nodes to prevent memory leaking after destruction

    Sequence(const Sequence<Key, Info>&);
    //copy constructor sets its head pointer to nullptr
    //then by usage of 'this' operator to assign the passed Sequence
    //to the newly created one

    //operator overloading

    Sequence<Key, Info>& operator=(const Sequence<Key, Info>&); //copies the contents of the one sequence to another and returns it
    Sequence<Key, Info>& operator+(const Sequence<Key, Info>&); //adds two sequences and returns the newly created sequence
    Sequence<Key, Info>& operator+=(const Sequence<Key, Info>&); //adds another sequence to itself and returns the newly created sequence


    Info operator[](int index);
    //operator [] which traverses the sequence and returns
    //the info of element of passed index where indexes of elements in the sequence
    //are understood as elements of array : a[0], a[1],....

    //simple bool operator
    bool operator==(const Sequence<Key, Info>&) const;
    //operator== returns true if two sequences have exactly the same elements

    bool operator!=(const Sequence<Key, Info>&) const;
    //operator!= returns true when given sequences are different are different

    //these operators are comparing the length of the sequences
    bool operator>(const Sequence<Key, Info>&) const; //returns true if the length of seq1 > seq2
    bool operator>=(const Sequence<Key, Info>&) const;//returns true if the length of  seq1 >= seq2
    bool operator<(const Sequence<Key, Info>&) const; //returns true if the length of  seq1 < seq2
    bool operator<=(const Sequence<Key, Info>&) const;//returns true if the length of seq1 <= seq2


    //method which returns the info of the elements
    //basis on the key and number of occurences
    Info getInfoByKey(const Key& key, int occurence) const;
    
    Info getFirstElemInfo() const; //method returns info of the first element, throws an error if the sequence is empty

    Info getLastElemInfo() const; //even though this method is ineffiecient as there is not tail pointer, I wrote it as an example
                                 //method returns info of the last element, throws an error if the sequence is empty

    //these methods return the key of the element
    //in the same way as the three previous methods
    Key getKeyByInfo(const Info& info, int occurence) const;
    Key getFirstElemKey() const;
    Key getLastElemKey() const;




    //insert methods
    void insertAtBegining(const Key&, const Info&);
    //method which inserts the element at the beginning of the singly-linked list
    //by creating the new Node with the given Key and Info and setting head pointed to this
    //node and setting the next pointer to the previously first element

    void insertAtTheEnd(const Key& k, const Info& i);
    //method which creates the element with the given Key and Info and insert
    //it at the end by setting the pointer 'next' of the last element (obtained by itterating)
    //from null to the newly created element

    void insertAfter(const Key& k, const Info& i, const Key& where, const int& occurance);
    //method which creates the element with the given Key and Info and insert
    //it after the element with a given Key


    //removing methods
    bool clearSequence();
    //method which iterate through the singly-linked list and deletes all of its elements
    //set the head pointer to the nullptr and protect from memory leaking

    //removing methods which traverse the sequence
    //and returns true if the elements were deleted
    //or false if the elements do not exist
    bool removeByKey(const Key& k, int occurence);
    bool removeByInfo(const Info& info, int occurence);
    bool removeLastElem();
    bool removeFirstElem();
    bool removeAtPosition(const int&);

    //boolean methods which returns true if, with the specified key or/and info
    //passed, the elements was found in the sequence
    bool findByInfo(const Info&, int occurence) const;
    bool findByKey(const Key& key, int occurence) const; //This method in particular is used in split_by_key function to verify if the given key exists in it's given occurence
    bool findElem(const Key& key, const Info& info, int occurence = 1);

    int findIndexByKey(const Key& key, int occurence) const;
    //this method is used to find index of a given key in the sequence while also considering it's occurence. 
    // returns index of the given key, It is also used in split_by_key function.


    bool isEmpty() const;
    //this method is a very short one, it returns true if head pointer is nullptr or false if it's not
    
    int sequenceLength() const; // returns length of the provided sequence
    //method which iterates through the singly-linked list and adding up the occurances
    //of elements to the variable which is returned by this function
    //this function as the rest of the similar methods uses the isEmpty method
    //to check whether the sequence is empty or not ( if so then return 0)
    
    void printsequencelength() const; //prints the length of the provided sequence

    //printing methods
    void printSequenceData() const; // prints all the data, keys and infos that are in the provided sequence
    void printSequenceKeys() const; 
    void printSequenceInfo() const;

    Sequence<Key, Info> subSeqToEndFrom(int startIndex) const;
    //method which returns the rest of the sequence from the given index

    Sequence<Key, Info> subSeqFromByLength(int startIndex, int length) const;
    //method which returns the part of the sequence called subsequence depending on the
    //startIndex and length parameters
    //this method is used in both split_by_key and split_by_pos functions


    Sequence<Key, Info> subSeqFromBeginTo(int lastIndex) const;
    //method which returns part of the sequence from the beginning to the given index.

};

//Definitions of the declared methods

template<typename Key, typename Info>
Sequence<Key, Info>::Sequence() {
    this->head = nullptr;
    this->Sequence_length = 0;
}

template<typename Key, typename Info>
Sequence<Key, Info>::~Sequence() {
    clearSequence();
}

template<typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence<Key, Info>& copy) {
    this->head = nullptr;
    this->copySequence(copy);
}

template<typename Key, typename Info>
void Sequence<Key, Info>::copySequence(const Sequence<Key, Info>& copy){

    Node* curr;

    if(head != nullptr) clearSequence();

    if(copy.head == nullptr){
        this->head = nullptr;
        this->Sequence_length = 0;
    }
    else {
        curr = copy.head;

        this->head = new Node(curr->key, curr->info); //allocates memory for a new node, copies contents of one sequence and sets it as head of another sequence

        curr = curr->next;

        while(curr != nullptr){
            this->insertAtTheEnd(curr->key, curr->info); //inserts new nodes at the end
            curr = curr->next;
        }
    }
}

template<typename Key, typename Info>
Info Sequence<Key, Info>::operator[](int index){

    if((index < 0) || (index > (sequenceLength() - 1) ) ){
        throw std::invalid_argument("ERROR : operator[] : invalid index value.");
    };
    if(isEmpty()){
        throw std::out_of_range("ERROR : operator[] : sequence is empty.");
    }

    Node* curr = head;
    int n = 0;

    while(curr){
        if(n == index) return curr->info;
        ++n;
        curr = curr->next;
    }
    throw std::out_of_range("ERROR : operator[] : element of given index does not exists");
}

template<typename Key, typename Info>
Sequence<Key, Info>& Sequence<Key, Info>::operator=(const Sequence<Key, Info>& elem) {

    if (this == &elem) return *this;
    if (elem.isEmpty()) return *this;
    this->clearSequence();
    this->head = nullptr;
    this->Sequence_length = 0;

    Node* curr = elem.head;
    while (curr) {
        this->insertAtTheEnd(curr->key, curr->info);
        curr = curr->next;
    }
    return *this;
}

template<typename Key, typename Info>
Sequence<Key, Info>& Sequence<Key, Info>::operator+(const Sequence<Key, Info>& elem) {

    Sequence<Key, Info>& newSequence(*this);
    if (elem.isEmpty()) return newSequence;

    Node* curr = elem.head;

    while (curr) {
        newSequence.insertAtTheEnd(curr->key, curr->info);
        curr = curr->next;
    }
    //std::cout << "newSequence size : "<< newSequence.sequenceLength() << std::endl;
    //newSequence.printSequenceKeys();
    return newSequence;
}

template<typename Key, typename Info>
Sequence<Key, Info>& Sequence<Key, Info>::operator+=(const Sequence<Key, Info>& elem) {

    *this = *this + elem;
    return *this;
}


//============two the same function implementaions with an opposite boolean values
template<typename Key, typename Info>
bool Sequence<Key, Info>::operator==(const Sequence<Key, Info>& elem) const{

    if(this->Sequence_length != elem.Sequence_length) return false;

    Node* currRight = elem.head;
    Node* currLeft = this->head;

    while(currRight && currLeft){

        if(currLeft->info != currRight->info) return false;
        if(currLeft->key != currRight->key) return true;
        currRight = currRight->next;
        currLeft = currLeft->next;
    }
    return true;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::operator!=(const Sequence<Key, Info>& elem) const{

    if(this->Sequence_length != elem.Sequence_length) return true;

    Node* currRight = elem.head;
    Node* currLeft = this->head;

    while(currRight && currLeft){

        if(currLeft->info != currRight->info) return true;
        if(currLeft->key != currRight->key) return true;
        currRight = currRight->next;
        currLeft = currLeft->next;
    }
    return false;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::operator>(const Sequence<Key, Info>& elem) const{
    if(this->sequenceLength() > elem.sequenceLength()){
        return true;
    }{
        return false;
    }
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::operator>=(const Sequence<Key, Info>& elem) const{
    if(this->sequenceLength() >= elem.sequenceLength()){
        return true;
    }{
        return false;
    }
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::operator<(const Sequence<Key, Info>& elem) const{
    if(this->sequenceLength() < elem.sequenceLength()){
        return true;
    }{
        return false;
    }
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::operator<=(const Sequence<Key, Info>& elem) const{
    if(this->sequenceLength() <= elem.sequenceLength()){
        return true;
    }{
        return false;
    }
}

template<typename Key, typename Info>
Key Sequence<Key, Info>::getKeyByInfo(const Info& info, int occurence) const{

    if (isEmpty()){
        throw std::out_of_range("ERROR : getInfo : Sequence is empty cannot retrive any data.");
    };
    if(occurence <= 0){
        throw std::invalid_argument("ERROR : getInfo : invalid occurence value.");
    };

    Node* curr = head;
    int n = 0;

    while(curr){
        if(curr->info == info) ++n;
        if(n == occurence) return curr->key;
        curr = curr->next;
    };
    throw std::runtime_error("ERROR : getKey : element of given info does not exists");
}

template<typename Key, typename Info>
Info Sequence<Key, Info>::getInfoByKey(const Key& key, int occurence) const{

    if (isEmpty()){
        throw std::out_of_range("ERROR : getInfo : Sequence is empty cannot retrive any data.");
    };
    if(occurence <= 0){
        throw std::invalid_argument("ERROR : getInfo : invalid occurence value.");
    };

    Node* curr = head;
    int n = 0;

    while(curr){
        if(curr->key == key) ++n;
        if(n == occurence) return curr->info;
        curr = curr->next;
    };

    throw std::runtime_error("ERROR : getInfoByKey : element of given key does not exists");
}

template<typename Key, typename Info>
Info Sequence<Key, Info>::getFirstElemInfo() const{

    if (isEmpty()){
        throw std::out_of_range("ERROR : getInfo : Sequence is empty cannot retrive any data.");
    };

    return head->info;
}

template<typename Key, typename Info>
Info Sequence<Key, Info>::getLastElemInfo() const{

    if (isEmpty()){
        throw std::out_of_range("ERROR : getInfo : Sequence is empty cannot retrive any data.");
    };

    if(head->next == nullptr){
        return head->info;
    }

    Node* curr = head;

    while(curr->next){
        curr = curr->next;
    };
    return curr->info;
}

template<typename Key, typename Info>
Key Sequence<Key, Info>::getFirstElemKey() const{
    if (isEmpty()){
        throw std::out_of_range("ERROR : getInfo : Sequence is empty cannot retrive any data.");
    };

    return head->key;
}

template<typename Key, typename Info>
Key Sequence<Key, Info>::getLastElemKey() const{

    if (isEmpty()){
        throw std::out_of_range("ERROR : getInfo : Sequence is empty cannot retrive any data.");
    };

    if(head->next == nullptr){
        return head->key;
    }

    Node* curr = head;

    while(curr->next){
        curr = curr->next;
    };
    return curr->key;
}





template<typename Key, typename Info>
void Sequence<Key, Info>::insertAtBegining(const Key& k, const Info& i) {

    Node* newNode = new Node(k, i, head);
    head = newNode;
    ++Sequence_length;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::insertAtTheEnd(const Key& k, const Info& i) {

    Node* newNode = new Node(k, i);
    Node* curr = head;

    if (isEmpty()) {
        head = newNode;
        ++Sequence_length;
    }
    else {
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        ++Sequence_length;
    }
}

template<typename Key, typename Info>
void Sequence<Key, Info>::insertAfter(const Key& k, const Info& i, const Key& where, const int& occurance) {

    if (isEmpty()) {
        throw std::out_of_range("Sequence is empty. Cannot execute insertAfter function.");
    };

    if(occurance <= 0){
        throw std::invalid_argument("ERROR : insertAfter : invalid occurence value");
    };

    Node* curr = head;
    int n = 0;

    while (where != curr->key) {
        curr = curr->next;
        if (!curr){
            throw std::out_of_range("ERROR : insertAfter : cannot insert element after non-existing element.");
        };
        if (where == curr->key) ++n;
        if (n >= occurance) break;
    }

    Node* newNode = new Node(i, k, curr->next);
    curr->next = newNode;
    ++Sequence_length;
}


template<typename Key, typename Info>
bool Sequence<Key, Info>::removeByKey(const Key& givenKey, int occurence) {

    if (isEmpty()) {
        throw std::out_of_range("Sequence is empty. Cannot execute removeBYKey function.");
    }

    if (occurence <= 0){
        throw std::invalid_argument("insertAfter - invalid occurence value.");
    };

    Node* curr = head;
    Node* prev = head;
    int n = 0;

    while (curr) {
        if (curr->key == givenKey) {

            ++n;

            if (curr == head) {
                head = curr->next;
                delete curr;
                --Sequence_length;
                prev = head;
                curr = head;
            }
            else {
                prev->next = curr->next;
                delete curr;
                --Sequence_length;
                curr = prev->next;
            }

            if(n == occurence) return true;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return false;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::removeByInfo(const Info& givenInfo, int occurence){
    if (isEmpty()) {
        throw std::out_of_range("Sequence is empty. Cannot execute removeBYKey function.");
    }

    if (occurence <= 0){
        throw std::invalid_argument("insertAfter - invalid occurence value.");
    };

    Node* curr = head;
    Node* prev = head;
    int n = 0;

    while (curr) {
        if (curr->info == givenInfo) {

            ++n;

            if (curr == head) {
                //head points to t he next element
                head = curr->next;
                //free memory of the curr element
                delete curr;
                //decreasing the sequence length
                --Sequence_length;
                //prev element points now at head
                prev = head;
                //current element points at head
                curr = head;
            }
            else {
                prev->next = curr->next;
                delete curr;
                --Sequence_length;
                curr = prev->next;
            }

            //when n equals to the given number of occurence then true is returned
            if(n == occurence) return true;
        }
        else {
            //when the analysing node do not have info equals to the given one
            //then the next element is searching
            prev = curr;
            curr = curr->next;
        }
    }
    //false when no element was found with given info
    return false;

}

template<typename Key, typename Info>
bool Sequence<Key, Info>::removeFirstElem() {

    if (isEmpty()) {
        throw std::out_of_range("Sequence is empty. Cannot execute removeFirstElem function.");
    };

    Node* curr = head;
    head = head->next;
    delete curr;
    --Sequence_length;
    return true;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::removeLastElem() {


    if (isEmpty()) {
        std::cout << "Sequence is empty. Cannot remove last element." << std::endl;
        return false;
    };

    if (head->next == nullptr) {
        head = nullptr;
        return true;
    };
    Node* curr = head;
    Node* prev = head;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
    --Sequence_length;
    return true;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::removeAtPosition(const int& position) {

    if ((position > sequenceLength() - 1) || (position < 0)) {
        throw std::invalid_argument("removeAtPosition - invalid position value.");
    };
    if (position == 0) {
        return removeFirstElem();
    };

    //wywalic wyjątek lengtht - 1
    if (position == (sequenceLength() - 1)) {
        return removeLastElem();
    };

    int n = 0;
    Node* curr = head;
    Node* prev = head;

    while ((n != position) && (prev = curr)) {
        prev = curr;
        curr = curr->next;
        n++;
    };
    prev->next = curr->next;
    delete curr;
    --Sequence_length;
    return true;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::findByInfo(const Info& info, int occurence) const {

    if(isEmpty()){
        throw std::out_of_range("ERROR : find(const Info& info, int occurence) : Sequence is empty. Cannot find elemnt of given info");
    };

    if(occurence <= 0){
        throw std::invalid_argument("ERROR : find(const Info& info, int occurence) : invalid arguments.");
    }

    Node* curr = head;
    int n = 0;

    while(curr){
        if(curr->info == info) ++n;
        if(n == occurence) return true;
        curr = curr->next;
    };

    return false;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::findByKey(const Key& key, int occurence) const {

    if(isEmpty()){
        throw std::out_of_range("ERROR : find(const Info& info, int occurence) : Sequence is empty. Cannot find elemnt of given info");
    };

    if(occurence <= 0){
        throw std::invalid_argument("ERROR : find(const Info& info, int occurence) : invalid arguments.");
    }

    Node* curr = head;
    int n = 0;

    while(curr){
        if(curr->key == key) ++n; 
        if(n == occurence) return true;
        curr = curr->next;
    };
    return false;
}

template<typename Key, typename Info>
int Sequence<Key, Info>::findIndexByKey(const Key& key, int occurence) const {

    if(findByKey(key, occurence) == 0){
        cerr << "findIndexByKey - could not find given key in the sequence" << endl;
        return -1;
    }

    Node* curr = head;
    int index = 0;
    while(curr){
        if(curr->key == key) ++index;
        if(index+1 == occurence) return index;
        curr = curr->next;
    };
    
    
}


template<typename Key, typename Info>
bool Sequence<Key, Info>::findElem(const Key& key, const Info& info, int occurence){
    if(isEmpty()){
        throw std::out_of_range("ERROR : find(const Info& info, int occurence) : Sequence is empty. Cannot find elemnt of given info");
    };

    if(occurence <= 0){
        throw std::invalid_argument("ERROR : find(const Info& info, int occurence) : invalid arguments.");
    }

    Node* curr = head;
    int n = 0;

    while(curr){
        if((curr->key == key) && (curr->info == info)) ++n;
        if(n == occurence) return true;
        curr = curr->next;
    };
    return false;
}




template<typename Key, typename Info>
void Sequence<Key, Info>::printSequenceData() const {

    if (isEmpty()) {
        std::cerr << "Sequence is empty. Printing sequence data impossible." << std::endl;
        return;
    }
    else {

        Node* curr = head;
        while (curr) {
            this->printNode(curr);
            curr = curr->next;
        }
        return;
    }
}

template<typename Key, typename Info>
void Sequence<Key, Info>::printSequenceKeys() const {

    if (isEmpty()) {
        std::cerr << "Sequence is empty. Printing sequence keys impossible" << std::endl;
        return;
    }
    else {
        Node* curr = head;
        while (curr) {
            std::cout << " " << curr->key << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

template<typename Key, typename Info>
void Sequence<Key, Info>::printSequenceInfo() const {
    if (isEmpty()) {
        std::cerr << "Sequence is empty. Printing sequence info impossible" << std::endl;
        return;
    }
    else {
        Node* curr = head;
        while (curr) {
            std::cout << " " << curr->info << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::clearSequence() {

    if (isEmpty()) {
        return true;
    }
    else {
        Node* curr = head;
        Node* toBeDeleted;

        while (curr) {
            toBeDeleted = curr;
            curr = curr->next;
            delete toBeDeleted;
            --Sequence_length;
        }
        head = nullptr;
    }
    return true;
}


template<typename Key, typename Info>
bool Sequence<Key, Info>::isEmpty() const {
    return (head == nullptr);
}

template<typename Key, typename Info>
int Sequence<Key, Info>::sequenceLength() const {

    int length = 0;

    if (isEmpty()) {
        return 0;
    }
    else {
        Node* curr = head;
        while (curr) {
            ++length;
            curr = curr->next;
        }
        return length;
    }
}

template<typename Key, typename Info>
void Sequence<Key, Info>::printsequencelength() const {
    int x = sequenceLength();
    cout <<"Length of the given sequence is "<< x <<endl;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::printNode(Node*& curr) const {

    if (!curr) {
        throw std::invalid_argument("printNode(Node* &curr) : given node is null");
    }
    else {
        std::cout << "key: " << curr->key;
        std::cout << " info: " << curr->info << std::endl;
    }
}


template<typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::subSeqFromByLength(int startIndex, int length) const{

    int seqlen = sequenceLength()-1;

    if(isEmpty()){
        throw std::out_of_range("Sequence is empty. Cannot execute subSeqFromByLength() method");
    };

    if(startIndex < 0){
        throw std::invalid_argument("subSeqFromByLength - invalid startIndex value.");
    };

    if(length < 0){
        throw std::out_of_range("subSeqFromByLength - invalid length value.");
    };

    Sequence<Key, Info> newSequence;

    Node* curr = head;
    int n = 0;

    while (curr) {
        if(n == startIndex) break;
        ++n;
        curr = curr->next;
    };

    n = 1;
    while (curr) {
        newSequence.insertAtTheEnd(curr->key, curr->info);
        if(n == length) break;
        ++n;
        curr = curr->next;
    };
    return newSequence;
}

template<typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::subSeqToEndFrom(int startIndex) const{

    if(isEmpty()){
        throw std::out_of_range("Sequence is empty. Cannot execute subSeqToEndFrom()");
    };

    if((startIndex < 0) || (startIndex > (sequenceLength() - 1))){
        throw std::invalid_argument("subSeqToEndFrom - invalid startIndex value.");
    };

    Sequence<Key, Info> newSequence;
    Node* curr = head;
    int n = 0;

    while (curr) {
        if(n == startIndex) break;
        ++n;
        curr = curr->next;
    };

    while (curr) {
        newSequence.insertAtTheEnd(curr->key, curr->info);
        curr = curr->next;
    };
    return newSequence;
}

template<typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::subSeqFromBeginTo(int lastIndex) const{

    if(isEmpty()){
        throw std::out_of_range("Sequence is empty. Cannot execute subSeqFromBeginTo()");
    };

    if((lastIndex < 0) || (lastIndex > (sequenceLength() - 1))){
        throw std::out_of_range("subSeqFromBeginTo - invalid lastIndex value.");
    };

    Sequence<Key, Info> newSequence;
    Node* curr = head;
    int n = 0;

    //while loop where into the newSequence
    //are inserted elements from the beginning to the element
    //with the lastIndex

    while (curr) {
        newSequence.insertAtTheEnd(curr->key, curr->info);
        if(n == lastIndex) return newSequence;
        ++n;
        curr = curr->next;
    };
    return newSequence;
}

template <typename Key, typename Info>
void split_by_pos (const Sequence <Key, Info>& seq, int start_pos, int len1, int len2, int count, Sequence <Key, Info>& seq1, Sequence <Key, Info>& seq2){

int pos = start_pos;

if((pos > seq.sequenceLength() - 1)){
    cerr << "split_by_pos - starting position is greater than sequence length" << endl;
    return;
}

while(count){
                   seq1+=seq.subSeqFromByLength(pos, len1);
                   pos=pos+len1;

                   if((pos > seq.sequenceLength() - 1)){
                    return;
                   }

                   seq2+=seq.subSeqFromByLength(pos, len2);
                   pos=pos+len2;

                   if((pos > seq.sequenceLength() - 1)){
                    return;
                   }

                   count--;
}

}



template <typename Key, typename Info>
void split_by_key (const Sequence <Key, Info>& seq, Key& start_key, int start_occ, int len1, int len2, int count, Sequence <Key, Info>& seq1, Sequence <Key, Info>& seq2){ 
  
int startindex = seq.findIndexByKey(start_key, start_occ);

split_by_pos(seq, startindex, len1, len2, count, seq1, seq2);

return;
}


#endif 


