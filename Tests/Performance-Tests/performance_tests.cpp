#include "../../Project/arraylist.hpp"
#include "../../Project/linkedlist.hpp"
#include <iostream>
#include <chrono>
#include <fstream>



void remove_first_performance(unsigned int list_size, ArrayList* al, LinkedList* ll){
    int remove_val = list_size / 2;

    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al->remove_first(remove_val);
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll->remove_first(remove_val);
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    al->insert_at(remove_val, remove_val);
    ll->insert_at(remove_val, remove_val);

    std::cout << "\nTeste de Performance da função remove_first: " << std::endl;
    std::cout << "Quantidade de números na lista: " << list_size << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds \n" << std::endl;
}

void remove_at_performance(unsigned int list_size, ArrayList* al, LinkedList* ll){
    int index = list_size / 2;

    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al->remove_at(index);
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll->remove_at(index);
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    al->insert_at(index, index);
    ll->insert_at(index, index);

    std::cout << "\nTeste de Performance da função remove_at: " << std::endl;
    std::cout << "Quantidade de números na lista: " << 100000 << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds \n" << std::endl;
}

void pop_front_performance(unsigned int list_size, ArrayList* al, LinkedList* ll){
    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al->pop_front();
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll->pop_front();
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    al->push_front(0);
    ll->push_front(0);

    std::cout << "\nTeste de Performance da função pop_front: " << std::endl;
    std::cout << "Quantidade de números na lista: " << list_size << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds \n" << std::endl;
}

void find_first_performance(unsigned int list_size, ArrayList* al, LinkedList* ll){
    int find_val = list_size / 2;

    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al->find_first(find_val);
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll->find_first(find_val);
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    std::cout << "\nTeste de Performance da função find_first: " << std::endl;
    std::cout << "Quantidade de números na lista: " << list_size << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds \n" << std::endl;
}

void find_all_performance(unsigned int list_size, ArrayList* al, LinkedList* ll){
    int find_val = list_size / 2;

    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al->find_all(find_val);
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll->find_all(find_val);
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    std::cout << "\nTeste de Performance da função find_all: " << std::endl;
    std::cout << "Quantidade de números na lista: " << list_size << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds \n" << std::endl;
}

void insert_at_performance(unsigned int list_size, ArrayList* al, LinkedList* ll){
    int index = list_size / 2;

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll->insert_at(index, 1);
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al->insert_at(index, 1);
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    ll->remove_at(index);
    al->remove_at(index);

    std::cout << "\nTeste de Performance da função insert_at: " << std::endl;
    std::cout << "Quantidade de números na lista: " << list_size << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds \n" << std::endl;
}

void count_performance(unsigned int list_size, ArrayList* al, LinkedList* ll){
    int count_val = list_size - 1;

    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al->count(count_val);
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll->count(count_val);
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    std::cout << "\nTeste de Performance da função count: " << std::endl;
    std::cout << "Quantidade de números na lista: " << list_size << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds \n" << std::endl;


}

void get_at_performance(unsigned int list_size, ArrayList* al, LinkedList* ll){
    int get_val = list_size / 2;

    auto start_arraylist = std::chrono::high_resolution_clock::now();
    al->get_at(get_val);
    auto end_arraylist = std::chrono::high_resolution_clock::now();
    auto duration_arraylist = std::chrono::duration_cast<std::chrono::microseconds>(end_arraylist - start_arraylist);

    auto start_linkedlist = std::chrono::high_resolution_clock::now();
    ll->get_at(get_val);
    auto end_linkedlist = std::chrono::high_resolution_clock::now();
    auto duration_linkedlist = std::chrono::duration_cast<std::chrono::microseconds>(end_linkedlist - start_linkedlist);

    std::cout << "\nTeste de Performance da função get_at: " << std::endl;
    std::cout << "Quantidade de números na lista: " << list_size << std::endl;
    std::cout << "Tempo de processamento ArrayList: " << duration_arraylist.count() << " microseconds" << std::endl;
    std::cout << "Tempo de processamento LinkedList: " << duration_linkedlist.count() << " microseconds \n" << std::endl;
}



int choose_option(int chosen_test, unsigned int list_size, ArrayList* al, LinkedList* ll){
    int chosen = 21;

    if(chosen_test == -1){
        std::cout << "\nEscolha qual função você quer testar: \n"
        << "[0] - get_at \n"
        << "[1] - count \n"
        << "[2] - insert_at \n"
        << "[3] - find_all \n"
        << "[4] - find_first \n"
        << "[5] - pop_front \n"
        << "[6] - remove_at \n"
        << "[7] - remove_first \n"
        << "[8] - test all \n"
        << "[9] - trocar quantidade da entrada \n"
        << "[20] - exit program"
        << std::endl;

        std::cin >> chosen;
    }else{
        chosen = chosen_test;
    }

    switch (chosen) {
        case 0:
            get_at_performance(list_size, al, ll);
            break;
        case 1:
            count_performance(list_size, al, ll);
            break;
        case 2:
            insert_at_performance(list_size, al, ll);
            break;
        case 3:
            find_all_performance(list_size, al, ll);
            break;
        case 4:
            find_first_performance(list_size, al, ll);
            break;
        case 5:
            pop_front_performance(list_size, al, ll);
            break;
        case 6:
            remove_at_performance(list_size, al, ll);
            break;
        case 7:
            remove_first_performance(list_size, al, ll);
            break;
    }

    return chosen;
}

bool continue_program(){
    std::cout << "Deseja realizar outro teste? \n"
              << "[0] - Não \n" << "[1] - Sim" << std::endl;
    bool continue_p = false;
    int input;
    std::cin >> input;
    if(input == 1){
        continue_p = true;
    }

    return continue_p;
}

void fill_lists(unsigned int quantity, ArrayList* al, LinkedList* ll){
    std::fstream file_input("Test-Values/values.txt");
    std::string line;

    for(unsigned int i = 0; i < quantity; i++){
        std::getline(file_input, line);
        int val = std::stoi(line);
        al->push_back(val);
        ll->push_back(val);
        line = "";
    }
}


void test_all(unsigned int list_size, ArrayList* al, LinkedList* ll){
    for(int i = 0; i <= 7; i++){
        choose_option(i, list_size, al, ll);
    }
}


unsigned int choose_input_size(){
    unsigned int quantity_test_list = 0;
    std::cout << "Digite a quantidade de valores da lista, max: 100000 e min: 1000: " << std::endl;

    while(quantity_test_list < 1000 || quantity_test_list > 100000){
        std::cin >> quantity_test_list;

        if(quantity_test_list < 1000){
            std::cout << "\nO valor mínimo do tamanho da lista é 1000 \n"
                      << "Digite um novo valor, max: 100000 e min: 1000:"<< std::endl;
        }else if(quantity_test_list > 100000){
            std::cout << "\nO valor máximo do tamanho da lista é 100000 \n"
                      << "Digite um novo valor, max: 100000 e min: 1000:"<< std::endl;
        }
    }
    return quantity_test_list;
}

int main(){
    ArrayList al;
    LinkedList ll;

    unsigned int list_size = choose_input_size();
    fill_lists(list_size, &al, &ll);

    while(true){
        int chosen_opt = choose_option(-1, list_size, &al, &ll);
        if(chosen_opt == 20){
            break;
        }else if(chosen_opt == 9){
            list_size = choose_input_size();
            fill_lists(list_size, &al, &ll);
            continue;
        }else if(chosen_opt == 8){
            test_all(list_size, &al, &ll);
        }

        if(!continue_program()){
            break;
        }
    }

    return 0;
}
