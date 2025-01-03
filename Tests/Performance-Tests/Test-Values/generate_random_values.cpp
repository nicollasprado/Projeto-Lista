#include <fstream>

int main(){
    std::fstream file("values.txt");

    for(int i=0; i < 100000; i++){
        file << i << "\n";
    }
}
