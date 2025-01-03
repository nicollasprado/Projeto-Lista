#include "../Project/linkedlist.hpp"
#include <iostream>
#include <string>


bool test_pushback(int* error_buffer){
    bool passed = false;

    LinkedList al;

    for(int i = 0; i <= 100; i++){
        al.push_back(i);
    }

    if(al[-1] == 100){
        passed = true;
    }else{
        error_buffer[0] = 100;
        error_buffer[1] = al[-1];
    }

    return passed;
}

bool test_pushfront(int* error_buffer){
    bool passed = false;

    LinkedList al;

    for(int i = 0; i <= 100; i++){
        al.push_front(i);
    }

    if(al[0] == 100){
        passed = true;
    }else{
        error_buffer[0] = 100;
        error_buffer[1] = al[0];
    }

    return passed;
}

bool test_insertat(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 100; i++){
        al.push_back(i);
    }

    al.insert_at(49, 999);

    bool passed = false;
    if(al[49] == 999){
        passed = true;
    }else{
        error_buffer[0] = 999;
        error_buffer[1] = al[49];
    }

    return passed;
}

bool test_size(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 100; i++){
        al.push_back(i);
    }

    bool passed = false;
    if(al.size() == 100){
        passed = true;
    }else{
        error_buffer[0] = 100;
        error_buffer[1] = al.size();
    }

    return passed;
}

bool test_back(int* error_buffer){
    LinkedList al;

    for(int i = 0; i <= 100; i++){
        al.push_back(i);
    }

    bool passed = false;
    if(al.back() == 100){
        passed = true;
    }else{
        error_buffer[0] = 100;
        error_buffer[1] = al.back();
    }

    return passed;
}

bool test_front(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 100; i++){
        al.push_back(i);
    }

    bool passed = false;
    if(al.front() == 0){
        passed = true;
    }else{
        error_buffer[0] = 0;
        error_buffer[1] = al.front();
    }

    return passed;
}

bool test_find_first(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 100; i++){
        al.push_back(i);
    }

    bool passed = false;
    if(al.find_first(59) == 59){
        passed = true;
    }else{
        error_buffer[0] = 59;
        error_buffer[1] = al.find_first(59);
    }

    return passed;
}

bool test_find_all(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 50; i++){
        al.push_back(i);
        al.push_front(i);
    }

    LinkedList found = al.find_all(49);

    bool passed = false;
    if((found[0] == 0 && found[1] == 100) || (found[0] == 100 && found[1] == 0)){
        passed = true;
    }else{
        error_buffer[0] = 0;
        error_buffer[1] = found[0];
        error_buffer[2] = 49;
        error_buffer[3] = found[1];
    }

    return passed;
}

bool test_count(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 50; i++){
        al.push_back(i);
        al.push_back(i);
        al.push_back(i);
    }

    bool passed = false;
    if(al.count(25) == 3){
        passed = true;
    }else{
        error_buffer[0] = 3;
        error_buffer[1] = al.count(25);
    }

    return passed;
}

bool test_sum(int* error_buffer){
    LinkedList al;

    int sum = 0;
    for(int i = 0; i < 50; i++){
        al.push_back(i);
        sum += i;
    }

    bool passed = false;
    if(al.sum() == sum){
        passed = true;
    }else{
        error_buffer[0] = sum;
        error_buffer[1] = al.sum();
    }

    return passed;
}

bool test_clear(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 100; i++){
        al.push_back(i);
    }
    al.clear();

    bool passed = false;
    if(al.size() == 0){
        passed = true;
    }else{
        error_buffer[0] = 0;
        error_buffer[1] = al.size();
    }

    return passed;
}

bool test_popback(int* error_buffer){
    LinkedList al;

    for(int i = 0; i <= 100; i++){
        al.push_back(i);
    }
    al.pop_back();

    bool passed = false;
    if(al[-1] == 99){
        passed = true;
    }else{
        error_buffer[0] = 99;
        error_buffer[1] = al[-1];
    }

    return passed;
}

bool test_popfront(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 100; i++){
        al.push_back(i);
    }
    al.pop_front();

    bool passed = false;
    if(al[0] == 1){
        passed = true;
    }else{
        error_buffer[0] = 1;
        error_buffer[1] = al[0];
    }

    return passed;
}

bool test_remove_first(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 100; i++){
        al.push_back(i);
    }
    al.remove_first(25);

    bool passed = false;
    if(al[25] != 25){
        passed = true;
    }else{
        error_buffer[0] = 26;
        error_buffer[1] = al[25];
    }

    return passed;
}

bool test_removeat(int* error_buffer){
    LinkedList al;

    for(int i = 0; i < 100; i++){
        al.push_back(i);
    }
    al.remove_at(25);

    bool passed = false;
    if(al[25] != 25){
        passed = true;
    }else{
        error_buffer[0] = 26;
        error_buffer[1] = al[25];
    }

    return passed;
}



bool continue_program(){
    std::cout << "Deseja realizar outro teste? \n"
        << "[0] - Não \n" << "[1] - Sim"
        << std::endl;

    int continue_p = 0;
    std::cin >> continue_p;
    if(continue_p == 1){
        return true;
    }

    return false;
}

std::string error_process(int* error_buffer){
    std::string error_msg;

    if(error_buffer[2] != 0){
        error_msg =
        "expected value: " + std::to_string(error_buffer[0])
        + ", returned value: " + std::to_string(error_buffer[1])
        + "\nexpected value: " + std::to_string(error_buffer[2])
        + ", returned value: " + std::to_string(error_buffer[3]);
    }else{
        error_msg =
        "expected value: " + std::to_string(error_buffer[0])
        + ", returned value: " + std::to_string(error_buffer[1]);
    }

    error_buffer[0] = 0;
    error_buffer[1] = 0;
    error_buffer[2] = 0;
    error_buffer[3] = 0;
    return error_msg;
}

int choose_option(int* error_buffer, int chosen_test){
    int chosen = 21;

    if(chosen_test == -1){
        std::cout << "\nEscolha qual função você quer testar: \n"
        << "[0] - push_back \n"
        << "[1] - push_front \n"
        << "[2] - insert_at \n"
        << "[3] - size \n"
        << "[4] - back \n"
        << "[5] - front \n"
        << "[6] - find_first \n"
        << "[7] - find_all \n"
        << "[8] - count \n"
        << "[9] - sum \n"
        << "[10] - clear \n"
        << "[11] - pop_back \n"
        << "[12] - pop_front \n"
        << "[13] - remove_first \n"
        << "[14] - remove_at \n"
        << "[15] - test all \n"
        << "[20] - exit program"
        << std::endl;

        std::cin >> chosen;
    }else{
        chosen = chosen_test;
    }

    switch(chosen){
        case 0:
            if(test_pushback(error_buffer)){
                std::cout << "\npush_back test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\npush_back test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 1:
            if(test_pushfront(error_buffer)){
                std::cout << "\npush_front test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\npush_front test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 2:
            if(test_insertat(error_buffer)){
                std::cout << "\ninsert_at test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\ninsert_at test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 3:
            if(test_size(error_buffer)){
                std::cout << "\nsize test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nsize test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 4:
            if(test_back(error_buffer)){
                std::cout << "\nback test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nback test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 5:
            if(test_front(error_buffer)){
                std::cout << "\nfront test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nfront test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 6:
            if(test_find_first(error_buffer)){
                std::cout << "\nfind_first test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nfind_first test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 7:
            if(test_find_all(error_buffer)){
                std::cout << "\nfind_all test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nfind_all test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 8:
            if(test_count(error_buffer)){
                std::cout << "\ncount test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\ncount test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 9:
            if(test_sum(error_buffer)){
                std::cout << "\nsum test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nsum test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 10:
            if(test_clear(error_buffer)){
                std::cout << "\nclear test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nclear test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 11:
            if(test_popback(error_buffer)){
                std::cout << "\npop_back test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\npop_back test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 12:
            if(test_popfront(error_buffer)){
                std::cout << "\npop_front test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\npop_front test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 13:
            if(test_remove_first(error_buffer)){
                std::cout << "\nremove_first test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nremove_first test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
        case 14:
            if(test_removeat(error_buffer)){
                std::cout << "\nremove_at test OK! \n" << std::endl;
            }else{
                std::string error_msg = error_process(error_buffer);
                std::cout << "\nremove_at test failed...\n" << error_msg << "\n" << std::endl;
            }
            break;
    }

    return chosen;
}


void test_all(int* error_buffer){
    for(int i = 0; i <= 14; i++){
        choose_option(error_buffer, i);
    }
}



int main(){
    // armazena o resultado esperado na posição 0 e o resultado do teste na posição 1
    int error_buffer[4] = {0,0,0,0};

    while(true){
        int chosen_opt = choose_option(error_buffer, -1);

        if(chosen_opt == 15){
            test_all(error_buffer);
        }else if(chosen_opt < 0 || chosen_opt > 20){
            continue;
        }

        if(!continue_program()){
            break;
        }
    }

    return 0;
}
