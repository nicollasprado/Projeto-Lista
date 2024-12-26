#include "../linkedlist.hpp"
#include <iostream>

int main(){
    LinkedList ll;

    ll.push_back(3);
    ll[0] = 4;

    std::cout << ll[0] << std::endl;
}
