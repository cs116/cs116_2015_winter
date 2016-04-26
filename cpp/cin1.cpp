// filename: cin1.cpp
#include <iostream> // cout, cin
#include <string>
#include <fstream>
using namespace std; // avoid std::cout

int main()
{

  // declare and open input file
  ifstream inFile;
  inFile.open("in.data");

  // declare variables
  string player = "", food = "";
  int age = -1;

  // get user input
  //cout << "Player name: ";
  // cin >> player;
  getline(inFile, player);

  //cout << "Age: ";
  inFile >> age;
  inFile.ignore();

  //cout << "Food : ";
  // cin >> food;
  getline(inFile, food);

  // print output
  cout << player << " " << age << " " << food << endl;

  return 0;
}
