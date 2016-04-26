// filename: cintest.cpp
// see video: https://www.youtube.com/watch?v=__o1jE0JSiE
#include <iostream>
#include <string>
using namespace std;

int main()
{

  // initialize variables
  string playerName = "", favoriteFood = "";
  int age = 0;

  // get user input
  cout << "What is your name? ";
  //cin >> playerName;
  getline(cin, playerName);

  cout << "What is your age? ";
  cin >> age;
  cin.ignore(); // default: ignore one character
  // cin.ignore(5, '\n'); // ignore 5 chars or up to newline

  cout << "What is your favorite food? ";
  // cin >> favoriteFood;
  getline(cin, favoriteFood);

  cout << "Welcome to the game, " << playerName << ". "
  << "We hear that you like to eat " << favoriteFood
  << " and that you are " << age << " years old. " << endl;

  cin.get(); // make sure no chars left in input stream
  // system(pause);

  return 0;
}
