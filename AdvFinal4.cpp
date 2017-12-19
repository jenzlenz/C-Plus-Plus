#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

#define HLENGTH 13		//length fo Hash Vector

int WordHash(string Word){
	int len = strlen(Word.c_str());
	int Sum = 0;
	unsigned int key = -1;
	for(int i = 0; i < len; ++i)
		Sum = Sum + Word[i];
	key = Sum % HLENGTH;
	return key;
}

struct ListNode{
	string Item;	//item name
	ListNode *link; //LinkList pointer
};


ListNode*  create(ListNode & node){
	ListNode *current = new ListNode;	//create 1st node
	current->link = NULL;			    //set link pointer to NULL
	current->Item = node.Item;
	return current;
}

ListNode*  add(ListNode * head, ListNode &node){
	ListNode *current = new ListNode;   //create new node
	current->Item = node.Item;
	current->link = head;			    //add as a first node
	head = current;			            // update head address to be current
	return head;						// return new head address
} 
		
void PrintList(ListNode * head){
    ListNode * temp = head;				//copy head address to temp
    cout << "  " << endl;
	if(temp == NULL) 
	   cout << "Empty List " << endl;
	while(temp != NULL) {
		cout << "word = " << temp->Item << endl;
		temp = temp->link;				//move to next node
	}
}

int find(ListNode * head, string Word){
     ListNode * temp = head;
     int NodeId = 0;		//init NodeId
     int wordCount = 0;
	 while(temp != NULL) {
    	if(temp->Item == Word){
    		wordCount++;
		}
		NodeId++;
		temp = temp->link;			//move to next node
	}
	cout << Word << " occurs " << wordCount << " times." << endl << endl << endl;
	return NodeId;

} 

int main()
{	
	string Word;
	ListNode node;
    struct ListNode* HashTable[HLENGTH] = {NULL};		
    int key;
    char text[] = "when in the course of human events it becomes necessary for one people "  
    "to dissolve the political bands which have connected them with another and to assume " 
    "among the powers of the earth the separate and equal station to which the Laws of "
    "Nature and of Natures God entitle them a decent respect to the opinions of mankind "
    "requires that they should declare the causes which impel them to the separation. "
    "We hold these truths to be self-evident that all men are created equal that they "
    "are endowed by their Creator with certain unalienable Rights that among these are "
    "Life Liberty and the pursuit of Happiness. That to secure these rights Governments "
    "are instituted among Men, deriving their just powers from the consent of the "
    "governed # ";
    char *token = std::strtok(text, " "); //get words from the char array
    while (token != NULL) {
        std::cout << token << '\n';
        token = std::strtok(NULL, " ");
	    node.Item = token;
	    if(node.Item[0] == '#')break;
	
		key =  WordHash(node.Item);
		if(HashTable[key] == NULL){
			HashTable[key] = create(node);
		} else {
		    HashTable[key] = add(HashTable[key], node);
		}
	}
	    

	//print List
	for(int i = 0; i < HLENGTH; ++i){
	cout << " ---------- " << i << "-------------" << endl;
	PrintList(HashTable[i]);
	}
	cout << endl;

	//find a Word
        while(1){
		cout << endl << "Enter Word to Find:  #(quit)" << endl;
		cin >> Word;
		if(Word[0] == '#')break;
		key = WordHash(Word);
        cout << Word << " should be found in HashTable # " << key << endl;
		int NodeId = find(HashTable[key], Word);
        //cout << "NodeId = " << NodeId << endl;
        if(NodeId != 0){
			cout << "Print all words in HashTable " << endl;
			PrintList(HashTable[key]);
		}
		else
			cout << "Word not Found " << endl;
	}

	return 0;
}
