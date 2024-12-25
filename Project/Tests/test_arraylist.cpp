#include "../arraylist.hpp"
#include <iostream>

int main() {
    ArrayList list;

    list.push_back(3);
    list.push_back(10);
    list.push_front(1);
    list.push_back(999);
    list.push_front(200);
    list.insert_at(2, 277);
    list.push_back(4300);
    list.push_back(8190);
    list.push_back(840);
    list.push_back(999);
    list.push_back(999);

    ArrayList foundElements = list.find_all(999);

    for(int i = 0; i < list.size(); i++){
        std::cout << list[i] << std::endl;
    }

    double percent = list.percent_occupied();

    std::cout << "back: " << list.back() << " front: " << list.front() << std::endl;
    std::cout << "size: " << list.size() << " capacity: " << list.capacity() << std::endl;
    std::cout << "percent: " << percent << std::endl;
    std::cout << "count: " << list.count(999) << "\n" << "FindAll:" << std::endl;

    for(int j = 0; j < foundElements.size(); j++){
        std::cout << "index encontrado: " << foundElements[j] << std::endl;
    }



}
