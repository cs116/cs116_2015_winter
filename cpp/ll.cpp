// file: ll.cpp
// author: george corser
// codepad: http://codepad.org/TbwNHgTg
// input: none
// processing: shows example of linked list
// output: prints various states of linked list

#include <iostream>
using namespace std;


// ----- global variables -----------------------------------------

struct Node           // define structure of a node
{
  int x;              // declare an integer (just data in the node)
  Node *next;         // declare pointer to next node in list
};

Node *head;           // declare global variable: pointer to first node

// ----- function prototypes ---------------------------------------

void initNode(int n);          // create first node in a linked list (stack)
void addNode (int n);          // add a new head node
void deleteNode();             // delete current head node
void printList(Node * pn);     // print current list starting at "pn"

// ----- main ---------------------------------------------------

int main() 
{
  // these six lines of code create 3 nodes in linked list
  initNode(5);
  cout << "head: " << head << endl;
  addNode(10); 
  cout << "head: " << head << endl;
  addNode(20); 
  cout << "head: " << head << endl;

  printList(head); // print list
  deleteNode();    // delete head node
  printList(head); // print list after prior head deleted

  return 0;
}

// ----- function definitions ------------------------------------

void initNode(int n)  // create first node in linked list (stack)
{
  head = new Node;
  head->x = n;
  head->next = NULL;
}

void addNode(int n)    // add a new head node
{
  Node *NewNode = new Node;
  NewNode->x = n;
  NewNode->next = head;
  head = NewNode;
}

void deleteNode()      // delete current head node
{
  Node * oldhead;      // declare pointer to a Node, called "oldhead"
  oldhead = head;      // assign current value of "head to "oldhead"
  head = head->next;   // re-set value of head to the next pointer
  delete(oldhead);     // release memory currently used by oldhead
}

void printList(Node * pn) // print current list starting at Node "pn"
{
  while (pn)
  {
    cout << pn->x << " " ;
    pn = pn->next;
  }
  cout << endl;
}
