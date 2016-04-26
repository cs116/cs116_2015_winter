#include <iostream> // for endl
#include <fstream>  // for ifstream
using namespace std;  // to save typing ::
int main() 
{
    ifstream inData;
    inData.open("1.data");
    string fname = "a", lname = "b", gender = "c";
    int males = 0, females = 0;
    while (inData >> fname >> lname >> gender)
    {
        cout << fname << " " << lname << endl;
        if (gender == "m") males ++;
        else females++;
    }
    
    cout << "m:" << males << " "<< "f:" << females << endl << endl;
    
    while (males>0)
    {
        cout << "*" ;
        males--;
    }
    cout << endl;
    
    for (int i = 0; i < females; i++) cout << "*";
    cout << endl;
    
    return 0;
}