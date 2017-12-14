#include <iostream?
#include <cstring>
#include <string.h>
using namespace std;

#define HASHLENGTH 13

int WordHash(string Word) {
  int len = strlen(Word.c_str());
  int sum = 0;
  unsigned int key = -1;
  
  for(int i = 0; i < len; ++i)
    sum = sum + Word[i];
  key = sum % HASHLENGTH;
  return key;
}

struct ListNode {
  string Item;
  string Desc;
  int count; //the which of to and
  ListNode *link;
};

ListNode* create(ListNode & node){
  ListNode *current = new ListNode;
  current->link = NULL;
  current->item = node.Item;
  current->Desc = node.Desc;
  current->count = node.count;
  
  return current;
}

ListNode* add(ListNode* head, ListNode &node){
  ListNode *current = new ListNode;
  current->Item = node.item;
  current->Desc = node.Desc;
  current->count = node.count;
  current->link = head;
  head = current;
  return head;
}

void PrintList(ListNode* head) {
  ListNode* temp = head;
  cout << " " << endl;
  if(temp == NULL)
    cout <<"Empty List" << endl;
    
  while(temp != NULL) {
    cout << "temp->Item = " temp->Item << endl;
    cout << "temp->Desc = " temp->Desc << endl;
    cout << "temp->count = " temp->count << endl;
    temp = temp->link;
  }
return;
}

int main()
{

char text[] = "When in the course of human events it becomes necessary for one people to dissolve th epolitical bands";

return 0;
}
