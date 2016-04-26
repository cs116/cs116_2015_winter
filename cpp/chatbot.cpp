// filename:chatbot.cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{

  string response = "" ;
  cout << "Hey" << endl;
  while(getline (cin, response))
  {
     if (response == "quit") break;
     cout << response << endl;
  }


  string name = "", food = "";
  int age = 0;

  // cin >> name >> age >> food;
  cout << "Name: " ;
  getline (cin, name);
  //  cin >> name;

  cout << "Age: " ;
  cin >> age;
  cin.ignore();

  cout << "Food: " ;
  // cin >> food;
  getline(cin,food);

  cout << name << " " << age << " " << food << endl << endl;

  return 0;
}
