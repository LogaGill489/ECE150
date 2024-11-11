// classes in c++!
/*
 - declared as "class {name};"
 - stores different types of variables related to a single thing
 - this is the first and arguably most important object in object-orientated programming


namespaces
- we can put our own classes and functions into a namespace
- namespaces can hold functions and classes, aswell as simply variables

summary:
- in this lecture, we learned how to declare namespaces and classes.  Classes hold variables
  while namespaces can hold objects, variables, functions, etc.
*/

#include <iostream>
using namespace std;

namespace ca_waterloo
{
    class nameClass;
    class nameClass
    {
    public:
        double a, b, c;
    };
}

class Body;

class Body
{
public: // global across the file
    // member variables
    double position_[3]; // km
    double velocity_[3]; // km/h
    double mass_;        // kg
};

main()
{
    Body earth{{1.496e8, 0.0, 0.0}, {0.0, 107e3, 0.0}, 5.972e24};
    Body mars{{0, 249.2e6, 0}, {86.8e3, 0, 0}, 6.39e23};

    cout << "Position: " << earth.position_[0] << endl;
    cout << "Velocity: " << earth.velocity_[1] << endl;
    cout << "Mass: " << earth.mass_;

    Body tmp{earth};
    tmp = mars;      // fully replaces tmp with mars
    tmp.mass_ = 0.0; // adjusts tmp's mass to 0

    cout << endl
         << tmp.velocity_[1];

    // namespace
    ca_waterloo::nameClass myObject;
    myObject.a = 3.3;
}