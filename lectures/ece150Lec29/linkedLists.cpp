/*
public and private class stuff.
Specifically, encapsulation and constructors
Also operator overloading



*/

#include <iostream>

class Rational
{
    // private if it is not labelled
public:
    // Anything the user can access
    // - This is information useful to everyone
    // so it will come first

    Rational(); // constructor
    Rational(int new_numer, int new_denom);

    int numer() const; // members
    int denom() const;

private:
    // Anything that is only accessible in
    // constructors, member functions, destructors
    // and friends appears here
    // - This is information useful only to authors
    // of this class

    int numer_;
    int denom_;

    void normalize();
};

void Rational::normalize()
{
    if (numer_ < 0)
        numer_ *= -1;
    if (denom_ < 0)
        denom_ *= -1;
}

Rational::Rational(int new_numer, int new_denom) : numer_{new_numer},
                                                   denom_{new_denom}
{
    if (denom_ == 0)
    {
        throw std::domain_error{
            "The denominator must be non-zero"};
    }

    normalize();
}

std::ostream &operator<<( std::ostream &out, Rational const &p ) {
out << p.numer() << "/" << p.denom() << std::endl;
return out;
}



// sets the default values of numer_ and denom_ to 0 and 1 respectively
Rational::Rational() : numer_{0},
                       denom_{1} {}

int Rational::numer() const
{
    return numer_;
}

int Rational::denom() const
{
    return denom_;
}

int main()
{
    Rational q{};
    std::cout << q;
}