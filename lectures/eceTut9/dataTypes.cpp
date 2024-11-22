#include <iostream>

/*
public is the publicly accessable parts of a class
private are the inner workings (i.e, kitchen at a restaurant)


*/

class Tuple
{
public:
    int x, y; // what everyone has access to
    Tuple()
    {
        x = 0;
        y = 0;
        std::cout << "default construct" << std::endl;
    }
    /*Tuple(int a, int b)
    {
        x = a;
        y = b;
        std::cout << "initializing construct" << std::endl;
    }*/
    // or
    Tuple(int a, int b) : x{a}, y{b}
    {
        std::cout << "initializing construct sig" << std::endl;
    }

    Tuple(const Tuple& other) {
        (*this).x = other.x;
        this->y = other.y;
    }

    void print();

    Tuple operator+ (const Tuple &t) {
        Tuple result(x + t.x, y + t.y);
        return result;
    }

    Tuple operator+ (int i) {
        Tuple result(x + i, y + i);
        return result;
    }

    Tuple operator=(const Tuple &t) {
        x = t.x;
        y = t.y;
        return *this; //allows for class chaining (i.e. var1 = var2 = var3)
    }

private:
};

void Tuple::print() //function inside the class
{
    std::cout << x << ", " << y << std::endl;
}

int main()
{
    Tuple var1{};     // calls default
    Tuple var2{1, 5}; // calls initial
    //var2.print();

    Tuple var3{var2};
    //var3.print();

    (var2 + var3).print();
    (var2 + 5).print();

    var2 = var3; //operator+ overloads this, making var2 = var3 in a much better way than bytecopying

    return 0;
}