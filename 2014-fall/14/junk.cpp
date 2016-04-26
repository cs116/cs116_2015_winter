#include <iostream>
using namespace std;

int g1 = 0;
int bar = 0;

int foo (int &bar, int x); // prototype (declaration)

int main()
{
  int i = 10;
  int j = 0;
  j = foo(i,i+1);
  cout << i << endl;
  cout << j << endl;
  cout << bar << endl;
}

int foo (int &bar, int x) // definition
{
   bar = 5;
   return bar*x;
}

