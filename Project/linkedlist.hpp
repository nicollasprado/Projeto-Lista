#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

#include <stdexcept>
#include <string>


class LinkedList {
    private:
        struct int_node{
            int value;
            struct int_node* next, * prev;
        };

        int_node* head, * tail;
        unsigned int size_;

    public:
        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->size_ = 0;
        }

        ~LinkedList() {
        }



        // Get operations


        int& operator[](int index){
            if(index > (int) (size_ - 1)){
                throw std::out_of_range("Index out of range");
            }else{
                if(index < 0){
                    index = size_ + index;
                    // second check
                    if(index < 0){
                        throw std::out_of_range("Index out of range");
                    }
                }

                int_node* iter = head;
                for(int i = 0; i <= index; i++){
                    iter = iter->next;
                }

                return iter->value;
            }
        }



        // Push operations



        void push_back(int value){
            if(size_ == 0){
                // creation of the new node
                int_node new_val;
                new_val.value = value;
                new_val.next = nullptr;
                new_val.prev = nullptr;

                // updating the linked list
                head = &new_val;
                tail = &new_val;

                size_++;
            }else{
                int_node new_val;
                new_val.value = value;
                new_val.next = nullptr;

                // change the tail node next to the new value
                tail->next = &new_val;

                // updates tail pointer to new node
                tail = &new_val;

                size_++;
            }
        }
};





#endif
