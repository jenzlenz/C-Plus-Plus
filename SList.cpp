/*
Program Name:SList.cpp
Author: Jennifer Dooley
Date: Dec 5, 2017
Synopsis:  Create a template that implements a singly-linked list called SList. 
Provide a default constructor, begin( )  and end( )  functions 
(thus you must create the appropriate nested iterator), insert( ) , erase( )  and a destructor.
*/

#include <iostream>
#include <stdlib.h>
#include <iterator>
using namespace std;

//template<class T>
class SList
{
public:

//default constructor
SList() {
cout << "Default constructor" << endl;
};

//parameterized constructor
SList(int theData, SList* theNextLink):data(theData), nextLink(theNextLink){
     cout << "Parameterized constructor" << endl;
};
      
//destructor
~SList() {cout << "Linked List has been destroyed." << endl;
};

//member functions

void insert(SList* head, int theData);
void erase(SList* head, int removeThis);
SList* getLink() const {return nextLink;}
int getData() const {return data;}
void setData(int theData) {data = theData;}
void setLink(SList* pointer) {nextLink = pointer;}

private:
int data;
SList *nextLink;
};

typedef SList* SListPtr;

class ListIterator {
public:
ListIterator begin() {return ListIterator();};
ListIterator end() {return ListIterator();};
//constructor
//ListIterator() : current(NULL) {};
};

int main() 
{
SList* head;
head = new SList(1, NULL); //first node
head->insert(head, 2); // add node at head
head->insert(head, 3); //add another node at head
SList *iterator;
for(iterator = head; iterator != NULL; iterator = iterator->getLink()){
   cout << (iterator->getData()) << endl;
}

head->erase(head, 1);
cout << "After erase..." << endl;
for(iterator = head; iterator != NULL; iterator = iterator->getLink()){
   cout << (iterator->getData()) << endl;
}

delete head;

return 0; 
}

//member functions
void SList::insert(SList* putItHere, int theData){
	SList* temp;
	temp = new SList(theData, putItHere->getLink());
	putItHere->setLink(temp);
};

void SList::erase(SList* head, int removeThis){
    SList* temp = head;
    SList* removeMe;
    SList* previous;

    while(temp != NULL){
		previous = temp;

		if(removeThis == getData()){
            removeMe = head->getLink();             //save present link 
            head = head->getLink();                 //move to next node
            previous = head;         	            //assign prev link to next link
		    delete removeMe;				        //remove present link from heap
		    break;
             }
        temp = temp->getLink();          	        //updated - move to next node
        }//end of while loop

};
