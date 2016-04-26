// extract to string
#include <iostream>
#include <string>

main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  // need cin.ignore()
  // see: http://stackoverflow.com/questions/18786575/using-getline-in-c
  std::cin.ignore();
  std::getline (std::cin,name);
  std::cout << "Hello, " << name << "!\n";

  return 0;
}
