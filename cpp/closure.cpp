// http://stackoverflow.com/questions/12635184/do-we-have-closures-in-c

#include <iostream>

class add_offset {
private:
    int offset;
public:
    add_offset(int _offset) : offset(_offset) {}
    int operator () (int x) { return x + offset; }
};

class summer
{
private:
    int sum;
public:
    summer() : sum(0) {}
    int operator () (int x) { return sum += x; }
};

int main(){

// make a closure
add_offset my_add_3_closure(3);

// use closure
int x = 4;
int y = my_add_3_closure(x);
std::cout << y << std::endl;

// make a closure
summer adder;

// use closure
adder(3);
adder(4);
std::cout << adder(0) << std::endl;

return 0;
}


