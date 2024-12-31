#include "../linkedlist.hpp"
#include <iostream>

int main(){
    LinkedList ll;

    ll.push_back(3);
    ll.push_back(5);
    ll[1] = 4;
    ll.push_front(100);
    ll.push_back(50);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(29);

    std::cout << "size: " << ll.size() << " find first: " << ll.find_first(3) << std::endl;
    std::cout << "count: " << ll.count(3) << " Sum: " << ll.sum() << std::endl;

    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << std::endl;
    }

    ll.insert_at(4, 1000);
    std::cout << "size after insert at: " << ll.size() << std::endl;

    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << std::endl;
    }

    std::cout << "Find all: " << std::endl;
    LinkedList find_all_indexes = ll.find_all(3);

    for(int i = 0; i < find_all_indexes.size(); i++){
        std::cout << find_all_indexes[i] << std::endl;
    }


    ll.pop_back();
    std::cout << "size after pop_back: " << ll.size() << std::endl;
    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << std::endl;
    }

    ll.pop_front();
    std::cout << "size after pop_front: " << ll.size() << std::endl;
    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << std::endl;
    }

    ll.remove_first(4);
    std::cout << "size after remove_first: " << ll.size() << std::endl;
    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << std::endl;
    }

    ll.remove_at(2);
    std::cout << "size after remove_at: " << ll.size() << std::endl;
    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << std::endl;
    }

    ll.clear();
    std::cout << "size after clear: " << ll.size() << std::endl;

    for(int i = 0; i < ll.size(); i++){
        std::cout << find_all_indexes[i] << std::endl;
    }

}
