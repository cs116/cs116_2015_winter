#include <iostream>
using namespace std;
void initNode(int n);
void addNode (int n);

struct Node {
  int x;
  Node *next;
};

Node *head = new Node;

int main() {

  Node *pn;

  initNode(5);
  cout << "head: " << head << endl;
  addNode(10); 
  cout << "head: " << head << endl;
  addNode(20); 
  cout << "head: " << head << endl;

  pn = head;
  while (pn)
  {
    cout << pn->x << " " ;
    pn = pn->next;
  }

  cout << endl;

  return 0;
}

void initNode(int n)
{
  head->x = n;
  head->next = NULL;
}

void addNode(int n)
{
  struct Node *NewNode = new Node;
  NewNode->x = n;
  NewNode->next = head;
  head = NewNode;
}
