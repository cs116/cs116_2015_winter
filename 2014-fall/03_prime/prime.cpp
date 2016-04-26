#include <iostream>
int main()
{
    int number,count=0;
    number = 23147;
    for(int a=1;a<=number;a++)
    {
        if(number%a==0) count++;
    }
    if(count==2)
        cout << number << " is prime \n";
    else
        cout << number <<" is not prime \n";
    return 0;
}