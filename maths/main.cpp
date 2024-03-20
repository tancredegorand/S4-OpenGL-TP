
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  

#include <random> 



//base
static auto& generator()
{
    thread_local std::default_random_engine gen{std::random_device{}()};
    return gen;
}
float alea(float min, float max)
{
    if (min > max)
        throw std::invalid_argument{"min must be smaller than max"};

    auto distribution = std::uniform_real_distribution<float>{min, max};
    return distribution(generator());
}

//autres
template<typename T>
T displayVec(std::vector<T> vec){
     for (T num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;  
}





//functions

int randomBinary(){
    return alea(1, 3); 
}

// template<typename T>
// T uniforme(T min, T max) {
//     return alea(min, max);
// }

template<typename T>
T uniforme(const std::vector<T>& vector) {
    if (vector.empty()) {
        throw std::invalid_argument("uniforme(vector) : Empty vector");
    }

    return vector[alea(0, vector.size())];
    
}


template<typename T>
std::vector<T> permutation(std::vector<T> vector) {
    if (vector.empty()) {
        throw std::invalid_argument("permutation(vector) : Empty vector");
    }
    const int size = vector.size();
    std::vector<T> result(size);
    std::vector<int> remain(size);

    for (unsigned int i = 0; i < size; i++) {
        remain[i] = i;  
    }

    for (unsigned int i = 0; i < size; i++) {
        unsigned int index = uniforme(remain);
        result[i] = vector[index]; 
        
        auto it = std::find(remain.begin(), remain.end(), index);
        if (it != remain.end()) {
            remain.erase(it);
        }
        
    }

    return result;

}


int main(){
    std::vector<int> original = {0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
    displayVec(original);

    for(unsigned int i = 0; i<100; i++){
        std::vector<int> permuted = permutation(original); 
        displayVec(permuted); 
    }



    return 0;
}





