#include <iostream>
/*
*** Dynamically Allocated Memory ***

*/

class E{
    public:
        E (int n);
        ~E();

        int retrieve();
    private:
        int heldVal{0};
};

E::E(int n) {
    heldVal = n;
}
int E::retrieve() {
    std::cout << heldVal << std::endl;
    return heldVal;
}

E::~E() {
    std::cout << "Deallocating: " << heldVal << std::endl;
}

int main() {
    E a{488};
    a.retrieve();

    E *p_array[5]{};

    for (int k{0}; k < 5; k++) {
        p_array[k] = new E{k + 1};
        p_array[k]->retrieve();
        delete p_array[k];
        p_array[k] = nullptr;
    }
}