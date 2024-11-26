#include <iostream>

/*
- go through slides 1 & 2 for motivation
*/

class Node {
    public:
        Node(double new_val_, Node *p_new_next_pointer_);
        ~Node();
    private:
        double value_;
        Node *p_next_pointer_;
};
Node::Node (double new_val_, Node *p_new_next_pointer_) {
    value_ = new_val_;
    p_next_pointer_ = p_new_next_pointer_;
}

int main() {
    
}