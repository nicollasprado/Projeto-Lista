#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

#include <stdexcept>

class LinkedList {
    private:
        struct int_node{
            int value;
            struct int_node* next, * prev;
        };

        int_node* head, * tail;
        unsigned int size_;

        int_node* get_index_addr(unsigned int index){
            int_node* value_addr;
            // check if index is closer to the start or the end
            unsigned int half_size = ((size_ - 1) / 2);
            if(index <= half_size){
                int_node* iter = head;
                // loop to get the value address
                for(unsigned int i = 0; i < size_; i++){
                    if(i == index){
                        value_addr = iter;
                        break;
                    }

                    iter = iter->next;
                }
            }else{
                int_node* iter = tail;
                // loop to get the value address
                for(unsigned int i = (size_ - 1); i > 0; i--){
                    if(i == index){
                        value_addr = iter;
                        break;
                    }

                    iter = iter->prev;
                }
            }

            return value_addr;
        }

    public:
        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->size_ = 0;
        }

        ~LinkedList() {
            for(unsigned int i = 0; i < size_; i++){
                if(i == (size_ - 1)){
                    delete tail;
                    head = nullptr;
                    tail = nullptr;
                    size_ = 0;
                }else{
                    tail = tail->prev;
                    delete tail->next;
                }
            }
        }



        // Get operations


        int size(){
            return size_;
        }

        int front(){
            return head->value;
        }

        int back() {
            return tail->value;
        }


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
                for(int i = 0; i < index; i++){
                    iter = iter->next;
                }

                return iter->value;
            }
        }

        int find_first(int value){
            int found = -1;

            int_node* iter = head;
            for(unsigned int i = 0; i < size_; i++){
                if(iter->value == value){
                    found = i;
                    break;
                }

                iter = iter->next;
            }

            return found;
        }

        LinkedList find_all(int value){
            LinkedList found_index_list;

            if(this->size_ == 1){
                if(head->value == value){
                    found_index_list.push_back(0);
                }
            }else{
                unsigned int qt_iterations = (this->size_) / 2;

                if(this->size_ % 2 != 0){
                    qt_iterations++;
                }

                int_node* start = this->head;
                int_node* end = this->tail;
                for(unsigned int i = 0; i < qt_iterations; i++){
                    if(end->value == value){
                        unsigned int val_index = (this->size_) - i;
                        found_index_list.push_back(val_index);
                    }

                    if(start == end){
                        continue;
                    }

                    if(start->value == value){
                        found_index_list.push_back(i);
                    }

                    start = start->next;
                    end = end->prev;
                }
            }

            return found_index_list;
        }

        int count(int value){
            int val_count = 0;

            if(size_ == 1){
                if(head->value == value){
                    val_count++;
                }
            }else{
                unsigned int qt_iterations = size_ / 2;
                if(size_ % 2 != 0){
                    qt_iterations++;
                }

                int_node* start = head;
                int_node* end = tail;
                for(unsigned int i = 0; i < qt_iterations; i++){
                    if(end->value == value){
                        val_count++;
                    }

                    if(start == end){
                        break;
                    }

                    if(start->value == value){
                        val_count++;
                    }

                    start = start->next;
                    end = end->prev;
                }
            }

            return val_count;
        }

        int sum(){
            int total_sum = 0;

            int_node* iter = head;
            for(unsigned int i = 0; i < size_; i++){
                total_sum += iter->value;
                iter = iter->next;
            }

            return total_sum;
        }

        int get_at(unsigned int index){
            if(size_ <= 0){
                throw std::invalid_argument("Invalid index " + std::to_string(index) + " -- List is empty.");
            }else if(index >= size_){
                throw std::out_of_range("Invalid index" + std::to_string(index) + " -- Index out of range.");
            }else{
                int_node* iter = head;
                for(unsigned int i = 0; i < index; i++){
                    iter = iter->next;
                }

                return iter->value;
            }
        }



        // Push operations



        void push_back(int value){
            if(size_ == 0){
                // creation of the new node
                int_node* new_val = new int_node;
                new_val->value = value;
                new_val->next = nullptr;
                new_val->prev = nullptr;

                // updating the linked list
                head = new_val;
                tail = new_val;
            }else{
                int_node* new_val = new int_node;
                new_val->value = value;
                new_val->next = nullptr;
                new_val->prev = tail;

                // change the tail node next to the new value
                tail->next = new_val;

                // updates tail pointer to new node
                tail = new_val;
            }

            size_++;
        }

        void push_front(int value){
            if(size_ == 0){
                int_node* new_val = new int_node;
                new_val->value = value;
                new_val->next = nullptr;
                new_val->prev = nullptr;

                head = new_val;
                tail = new_val;
            }else{
                int_node* new_val = new int_node;
                new_val->value = value;
                new_val->next = head;
                new_val->prev = nullptr;

                head->prev = new_val;

                head = new_val;
            }

            size_++;
        }

        void insert_at(unsigned int index, int value){
            if(index >= size_ || index < 0){
                std::string error_msg =
                    "Error trying to insert " + std::to_string(value)
                    + " at index " + std::to_string(index)
                    + " -- Index out of range";
                throw std::out_of_range(error_msg);
            }else{
                int_node* index_addr = get_index_addr(index);

                // creation of the new node
                int_node* new_node = new int_node();
                new_node->value = value;

                // linking the new node to the linked list
                new_node->prev = index_addr->prev;
                new_node->next = index_addr;

                int_node* before_index = index_addr->prev;
                before_index->next = new_node;
                index_addr->prev = new_node;

                size_++;
            }
        }




        // Remove operations


        void clear(){
            for(unsigned int i = 0; i < size_; i++){
                if(i == (size_ - 1)){
                    delete tail;
                    head = nullptr;
                    tail = nullptr;
                    size_ = 0;
                }else{
                    tail = tail->prev;
                    delete tail->next;
                }
            }
        }

        bool pop_back(){
            bool deleted = false;

            if(size_ == 0){
                throw std::runtime_error("Error trying to pop_back -- The list is empty");
            }else if(size_ == 1){
                delete tail;
                tail = nullptr;
                head = nullptr;
                size_--;

                deleted = true;
            }else{
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
                size_--;

                deleted = true;
            }

            return deleted;
        }

        bool pop_front(){
            bool deleted = false;

            if(size_ == 0){
                throw std::runtime_error("Error trying to pop_front -- The list is empty");
            }else if(size_ == 1){
                delete head;
                tail = nullptr;
                head = nullptr;
                size_--;

                deleted = true;
            }else{
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
                size_--;

                deleted = true;
            }

            return deleted;
        }

        bool remove_first(int value){
            bool removed = false;
            int value_index = find_first(value);

            if(value_index == 0){
                removed = pop_front();
            }else if(value_index == (int) (size_ - 1)){
                removed = pop_back();
            }else{
                int_node* value_addr = get_index_addr(value_index);

                // actually remove the value

                int_node* before_value = value_addr->prev;
                int_node* after_value = value_addr->next;

                // changes the pointers before and after value address. So, the value address is not anymore linked to the linked list
                before_value->next = after_value;
                after_value->prev = before_value;

                delete value_addr;

                removed = true;
            }

            if(removed){
                size_--;
            }

            return removed;
        }


        bool remove_at(unsigned int index){
            bool removed = false;

            if(index == 0){
                removed = pop_front();
            }else if(index == (size_ - 1)){
                removed = pop_back();
            }else{
                int_node* index_addr = get_index_addr(index);

                // actually remove the index value

                int_node* before_index = index_addr->prev;
                int_node* after_index = index_addr->next;

                // unlink the index address from linked list
                before_index->next = after_index;
                after_index->prev = before_index;
                delete index_addr;

                removed = true;
            }

            if(removed){
                size_--;
            }

            return removed;
        }
};





#endif
