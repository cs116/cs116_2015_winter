#include <fstream>
#include <iostream>
using namespace std;
int main()
{
  ifstream zippy;
  zippy.open("numbers.txt");
  int n1, n2, n3;
  //cout << "Enter three numbers: " << endl;
  zippy >> n1 >> n2 >> n3;
  cout << n1 << " " << n2 << " " << n3 << endl;
  return 0;
}
