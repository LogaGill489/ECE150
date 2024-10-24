#include <iostream>
int main();
int main() {
std::cout << "Hello world!" << 
std::endl;
return 0;
}

//problems
//main is undefined
//two sets of << between "Hello world" and "endl"
//standard library is not called to reference endl (i.e. "std::endl")
//return needs to return a value