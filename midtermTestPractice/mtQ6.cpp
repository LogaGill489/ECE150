#include <iostream>
int main();
int main() {
    for (int i=3; i <= 13; i++) { //Equation One
        int o{0};
        for (int j = 0; j <= i; j++) {
            o += j*(j+1)*(j+2);
        }
        std::cout << "Eq1: When n = " << i << ", output = " << o << std::endl;
    }

    for (int i = 3; i <= 13; i++) { //Equation Two
        double o = 0.25*i*(i+1)*(i+2)*(i+3);
        std::cout << "Eq2: When n = " << i << ", output = " << o << std::endl;
    }
}