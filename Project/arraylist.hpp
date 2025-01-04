#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

#include <stdexcept> // needed to throw exceptions
#include <string>

class ArrayList {
    private:
        int* data; // initial size = 8
        unsigned int size_, capacity_;

        void increase_capacity(){
            capacity_ = capacity_ * 2;
            int* new_mem_loc = new int[capacity_]; // creation of a new memory location with the double of old capacity

            // Loop to add the values of data in the new mem location
            for(unsigned int i = 0; i < size_; i++){
                new_mem_loc[i] = data[i];
            }

            // Change of the pointer data to new mem location and flush the old memory
            int* old_data = data;
            data = new_mem_loc;
            delete [] old_data;
        }

        void check_capacity(){
            if(size_ == capacity_){
                increase_capacity();
            }
        }

    public:
        // constructor
        ArrayList() {
            this->size_ = 0;
            this->capacity_ = 8;
            this->data = new int[capacity_];
        }

        // destructor
        ~ArrayList() {
            delete [] data;
        }



        // Get operations


        unsigned int size() {
            return size_;
        }

        unsigned int capacity(){
            return capacity_;
        }

        int& operator[](int index){
            if(index > (int) (size_ - 1)){
                throw std::out_of_range("Index out of range");
            }else{
                // if index below 0, we iterate backwards
                if(index < 0){
                    index = size_ + index;
                }
                // Checks if the backwards iterations is valid
                // example: if size is 5 and the given index is -1 will return the value in data[4]
                // example 2: if size is 3 and given index is -4 the result will be -1 which is invalid
                if(index < 0){
                    throw std::out_of_range("Index out of range");
                }

                return data[index];
            }
        }

        double percent_occupied(){
            return (static_cast<double>(size_) / static_cast<double>(capacity_));
        }

        int back(){
            if(size_ == 0){
                throw std::out_of_range("The list is empty");
            }else if(size_ == 1){
                return data[0];
            }else{
                return data[size_ - 1];
            }
        }

        int front(){
            if(size_ == 0){
                throw std::out_of_range("The list is empty");
            }else{
                return data[0];
            }
        }

        int find_first(int value){
            int result = -1;
            for(unsigned int i = 0; i < size_; i++){
                if(data[i] == value){
                    result = i;
                    break;
                }
            }

            return result;
        }

        ArrayList find_all(int value){
            ArrayList found_elements;

            if(size_ == 1){
                if(*data == 1){
                    found_elements.push_back(*data);
                }
            }else{
                int* back = data + size_ - 1;
                int* start = data;

                unsigned int qt_iterations = size_ / 2;
                // If the size is odd we add 1 iteration that is the center value
                if(size_ % 2 != 0){
                    qt_iterations++;
                }

                // iterates from end to middle and from start to middle
                for(unsigned int i = 0; i < qt_iterations; i++){
                    if(*back == value){
                        unsigned int val_index = size_ - i;
                        found_elements.push_back(val_index);
                    }

                    if(start == back){
                        break;
                    }

                    if(*start == value){
                        found_elements.push_back(i);
                    }

                    back--;
                    start++;
                }
            }

            return found_elements;
        }

        int count(int value){
            int result = 0;

            if(size_ == 1){
                if(*data == value){
                    result++;
                }
            }else{
                int* back = data + size_ - 1;
                int* start = data;

                // Qt iterations is the distance of both pointers to the center of the list
                unsigned int qt_iterations = size_ / 2;
                // If the size is odd we add 1 iteration that is the center value
                if(size_ % 2 != 0){
                    qt_iterations++;
                }

                // iterates from end to middle and from start to middle
                for(unsigned int i = 0; i < qt_iterations; i++){
                    if(*back == value){
                        result++;
                    }

                    if(start == back){
                        break;
                    }

                    if(*start == value){
                        result++;
                        break;
                    }

                    back--;
                    start++;
                }
            }

            return result;
        }

        int sum(){
            int result = data[0];

            for(unsigned int i = 1; i < size_; i++){
                result += data[i];
            }

            return result;
        }

        int get_at(unsigned int index){
            return data[index];
        }



        // Push operations


        void push_back(int value){
            check_capacity();

            data[size_] = value;
            size_++;
        }

        void push_front(int value){
            check_capacity();

            size_++;

            // Iterates the list backwards to move content to their index+1
            for(unsigned int i = size_; i > 0; i--){
                data[i] = data[i - 1];
            }

            data[0] = value;
        }

        void insert_at(unsigned int index, int value){
            check_capacity();

            // no needs to check if index < 0 because index is a unsigned int
            if(index > size_){
                std::string error_msg =
                     "Error trying to insert " + std::to_string(value)
                     + " at index" + std::to_string(index)
                     + " -- Index out of range";
                throw std::out_of_range(error_msg);
            }else if(index == 0){
                push_front(value);
            }else if(index == size_){
                push_back(value);
            }else{
                size_++;

                // Interates the list backwards moving the content to index+1 and end at the insert index
                for(unsigned int i = size_; i > index; i--){
                    data[i] = data[i - 1];
                }

                data[index] = value;
            }
        }



        // Remove operations



        void clear(){
            capacity_ = 8;
            size_ = 0;

            int* old_data = data;

            int* new_mem_loc = new int[capacity_];
            data = new_mem_loc;

            delete [] old_data;
        }

        bool pop_back(){
            bool removed = false;

            if(size_ == 0){
                throw std::runtime_error("Error trying to pop_back -- List is empty");
            }else{
                removed = true;
                size_--;
            }

            return removed;
        }

        bool pop_front(){
            bool removed = false;

            if(size_ == 0){
                throw std::runtime_error("Error trying to pop_back -- List is empty");
            }else{
                for(unsigned int i = 0; i < (size_ - 1); i++){
                    data[i] = data[i + 1];
                }

                size_--;
                removed = true;
            }

            return removed;
        }

        bool remove_first(int value){
            int value_index = find_first(value);
            bool removed = false;
            if(value_index == -1){
                std::string error_msg =
                    "Error trying to remove the first occurence of " + std::to_string(value)
                    + " -- Value is not in the list";
                throw std::invalid_argument(error_msg);
            }else{
                for(unsigned int i = value_index; i < (size_ - 1); i++){
                    data[i] = data[i + 1];
                }

                size_--;
                return true;
            }

            return removed;
        }

        bool remove_quantity(int value, unsigned int quantity){
            bool removed = false;
            if(quantity != 0){
                ArrayList found_indexes = find_all(value);

                if(quantity > found_indexes.size()){
                    std::string error_msg =
                        "Error trying to remove specific quantity of " + std::to_string(value)
                        + " -- Quantity " + std::to_string(quantity)
                        + " is higher than value quantity";
                    throw std::invalid_argument(error_msg);
                }

                if(found_indexes.size() == 0){
                    std::string error_msg =
                        "Error trying to remove specific quantity of " + std::to_string(value)
                        + " -- Value is not in the list";
                    throw std::invalid_argument(error_msg);
                }else{
                    // loop through each removal
                    for(unsigned int i = 0; i < quantity; i++){
                        // actually remove the value
                        for(unsigned int j = found_indexes[i]; j < (size_ - 1); j++){
                            data[j] = data[j + 1];
                        }
                        size_--;
                    }
                    removed = true;
                }
            }

            return removed;
        }

        bool remove_at(unsigned int index){
            bool removed = false;

            if(index > size_){
                std::string error_msg =
                    "Error trying to remove_at " + std::to_string(index)
                    + " -- Index out of range";
                throw std::invalid_argument(error_msg);
            }else if(size_ == 0){
                std::string error_msg =
                    "Error trying to remove_at " + std::to_string(index)
                    + " -- List is empty";
                throw std::out_of_range(error_msg);
            }else if(index == 0){
                removed = pop_front();
            }else if(index == (size_ - 1)){
                removed = pop_back();
            }else{
                for(unsigned int i = index; i < (size_ - 1); i++){
                    data[i] = data[i + 1];
                }
                removed = true;
                size_--;
            }

            return removed;
        }
};


#endif
