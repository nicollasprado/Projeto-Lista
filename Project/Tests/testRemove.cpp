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

    list.remove_first(2);
    std::cout << "remove first size: " << list.size() << std::endl << std::endl;

    for(int j = 0; j < list.size(); j++){
        std::cout << list[j] << std::endl;
    }

    list.pop_front();
    std::cout << "pop front size: " << list.size() << std::endl << std::endl;

    for(int j = 0; j < list.size(); j++){
        std::cout << list[j] << std::endl;
    }

    list.pop_back();
    std::cout << "pop back size: " << list.size() << std::endl << std::endl;

    for(int j = 0; j < list.size(); j++){
        std::cout << list[j] << std::endl;
    }

    list.push_back(404);
    std::cout << "push back post pop back size: " << list.size() << std::endl << std::endl;

    for(int j = 0; j < list.size(); j++){
        std::cout << list[j] << std::endl;
    }

    list.remove_at(1);
    std::cout << "remove at size: " << list.size() << std::endl << std::endl;

    for(int j = 0; j < list.size(); j++){
        std::cout << list[j] << std::endl;
    }
}
