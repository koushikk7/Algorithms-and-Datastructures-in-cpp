//Sai Koushik Neriyanuri (317100)

#include <iostream>
#include "EADSLAB1.hpp"
#define TEST_STAGE 1

int main(){

    Sequence<int, char> seq1;
    Sequence<int, char> seq2;

if(TEST_STAGE == 1){ 
   

    //tests on empty list

    //length of an empty sequence, should return 0
    seq1.printsequencelength();

    //checking whether it's empty or not, must return true
    if(seq1.isEmpty()){
        cout<<"isEmpty() - The given sequience is empty\n";
    };

    //printing contents of empty an sequence, throws an error 
    seq1.printSequenceData();

    //removing an element from an empty list, throws an error
    seq1.removeFirstElem();

    //forming a sub sequence from an empty list, throws an error
     seq1.subSeqFromBeginTo(10);

    //index operator [] usually returns the info of the element with the passed index, 
    //but on an empty list, throws an error
    seq1.operator[](7);

    //equating two empty lists returns true
    if(seq1.operator==(seq2)){
        cout << "seq 1 and seq 2 are the same\n";
    };

    //clearing an empty sequence 
    seq1.clearSequence();
}

if(TEST_STAGE == 2){

    //inserting elements
    
    seq1.insertAtBegining(1, 'a');
    seq1.insertAtBegining(2, 'b');
    seq1.insertAtBegining(3, 'c');
    seq1.insertAtTheEnd(4, 'd');
    seq1.insertAtTheEnd(4, 'i');
    seq1.insertAtTheEnd(6, 'e');
    seq1.insertAfter('f',5, 4, 1);
    seq1.insertAfter('g',7, 4, 1);

     //printing data int the sequence
    cout <<"SEQUENCE 1\n"; seq1.printSequenceData();

    cout << endl;

    //testing get functions

    char y = seq1.getInfoByKey(4, 2);
    cout << "first element info = "<< y <<endl;
    cout << endl;

    char x = seq1.getFirstElemInfo();
    cout << "first element info = "<< x <<endl;
    cout << endl;

    cout << endl;


   
    //copying data from seq1 to seq2 using = operator
    seq2.operator=(seq1);

    //printing seq2 data

    cout <<"SEQUENCE 2\n"; seq2.printSequenceData();
    cout << endl;

    //making a subsequence from seq 2

    Sequence<int, char> seq3;

    seq3 = seq2.subSeqToEndFrom(3);
    cout <<"SEQUENCE 3\n"; seq3.printSequenceData();
    cout << endl;
    
    

    //equating seq1 and 2, returns true

    seq1.operator==(seq2);
    if(seq1.operator==(seq2)){
        cout << "seq 1 and seq 2 are the same\n";
    };
    cout << endl;

    //equating seq2 and 3, returns false

    if(!(seq3.operator==(seq2))){
        cout<<"seq2 and 3 aren't equal\n";
    };
    cout << endl;

    //clearing sequences
    seq1.clearSequence();
    seq2.clearSequence();
    seq3.clearSequence();

    cout << endl;
}


if(TEST_STAGE == 3) {

    Sequence<int, int> mainseq;
    Sequence<int, int> splitseq1;
    Sequence<int, int> splitseq2;

   //tesing insert methods
    mainseq.insertAtBegining(10,10);
    mainseq.insertAtBegining(9,9);
    mainseq.insertAtBegining(8,8);
    mainseq.insertAtBegining(7,7);
    mainseq.insertAtBegining(6,6);
    mainseq.insertAtBegining(5,5);
    mainseq.insertAtBegining(4,4);
    mainseq.insertAtBegining(3,3);
    mainseq.insertAtBegining(2,2);
    mainseq.insertAtBegining(1,1);
    mainseq.insertAtBegining(0,0);

   cout <<"MAIN SEQUENCE LENGTH:\n"; mainseq.printsequencelength();  cout << endl;

   cout <<"MAIN SEQUENCE\n"; mainseq.printSequenceData(); cout << endl;

//testing split_by_pos external funciton
    split_by_pos (mainseq, 1, 2, 4, 3, splitseq1, splitseq2);

    cout <<"SPLIT SEQUENCE 1\n"; splitseq1.printSequenceData(); cout << endl;

    cout <<"SPLIT SEQUENCE 2\n"; splitseq2.printSequenceData(); cout << endl;

}


if(TEST_STAGE == 4){

    Sequence<int, string> mainseq2;
    Sequence<int, string> splitseq3;
    Sequence<int, string> splitseq4;

   
    mainseq2.insertAtBegining(14,"ooo");
    mainseq2.insertAtBegining(13,"n");
    mainseq2.insertAtBegining(12,"m");
    mainseq2.insertAtBegining(11,"l");
    mainseq2.insertAtBegining(10,"k");
    mainseq2.insertAtBegining(9,"j");
    mainseq2.insertAtBegining(8,"i");
    mainseq2.insertAtBegining(7,"h");
    mainseq2.insertAtBegining(6,"g");
    mainseq2.insertAtBegining(5,"f");
    mainseq2.insertAtBegining(4,"e");
    mainseq2.insertAtBegining(3,"d");
    mainseq2.insertAtBegining(2,"c");
    mainseq2.insertAtBegining(2,"b");
    mainseq2.insertAtBegining(2,"a");

    cout <<"MAIN SEQUENCE 2\n"; mainseq2.printSequenceData(); 

    cout<<endl;

//testing split_by_key external funciton

    int x = 2;

    split_by_key(mainseq2, x, 3, 2, 3, 4, splitseq3, splitseq4);

    cout <<"SPLIT SEQUENCE 3\n"; splitseq3.printSequenceData();

        cout << endl;

   cout <<"SPLIT SEQUENCE 4\n"; splitseq4.printSequenceData();  cout << endl;

}


cout <<"END OF TESTS\n";

return 0;

}