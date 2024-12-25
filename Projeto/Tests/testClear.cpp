#include "../arraylist.hpp"
#include <iostream>

int main() {
    ArrayList list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);


    std::cout << "starter size: " << list.size() << std::endl;
    for(int i = 0; i < list.size(); i++){
        std::cout << list[i] << std::endl;
    }

    list.clear();
    std::cout << "final size: " << list.size() << std::endl << std::endl;

    for(int j = 0; j < list.size(); j++){
        std::cout << list[j] << std::endl;
    }
}
