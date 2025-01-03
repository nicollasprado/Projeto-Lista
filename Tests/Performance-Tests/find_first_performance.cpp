#include "../../Project/arraylist.hpp"
#include "../../Project/linkedlist.hpp"
#include <iostream>
#include <chrono>
#include <fstream>

int main(){
    ArrayList al;
    LinkedList ll;

    std::fstream file_input("Test-Values/values.txt");
    std::string line;

    while(std::getline(file_input, line) && line != "-1"){
        int val = std::stoi(line);
        al.push_back(val);
        ll.push_back(val);
        line = "";
    }

    int find_val = 99999; // last element in values.txt

    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al.find_first(find_val);
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll.find_first(find_val);
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    std::cout << "Quantidade de números na lista: " << 100000 << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds" << std::endl;

    return 0;
}
