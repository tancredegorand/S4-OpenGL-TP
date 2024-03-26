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


int randomBinary(){
    return alea(0, 2); 
}

float random1(){
    return alea(0.f, 1.f);
}

float factoriel(float x){
    float res = 1.; 
     for (unsigned int i = 1; i <= x; ++i) {
        res *= i;
    }
    return res;
}



//autre
template<typename T>
T displayVec(std::vector<T> vec){
     for (T num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;  
}



//functions


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
        int index = uniforme(remain);
        result[i] = vector[index]; 
        
        auto it = std::find(remain.begin(), remain.end(), index);
        if (it != remain.end()) {
            remain.erase(it);
        }
        
    }
    return result;
}




float exponentielle(float lambda)
{
  return (-1 / lambda) * std::log(random1());
}





float gamma(float x){
    return factoriel(x-1);
}

float loi_beta(float alpha, float beta){
    const float random = random1(); 
    const float numerateur = pow(random, alpha-1)*pow(1-random, beta-1);
    const float denominateur = (gamma(alpha)+gamma(beta))/gamma(alpha+beta); 
    return numerateur/denominateur;
}














int main(){

    // --- Random ---
    // for(unsigned int i = 0; i<100; i++){
    //    std::cout << random1() <<  " - " << randomBinary() << std::endl;
    // }

    // --- Factoriel ---
    // for(unsigned int i = 0; i<100; i++){
    //    std::cout << factoriel(5) << std::endl; 
    // }

    // --- Uniforme --- 
    // std::vector<int> original = {0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    // for(unsigned int i = 0; i<10; i++){
    //    std::cout << uniforme(original) << std::endl;
    // }



    // --- Permutation --- 
    // std::vector<int> original = {0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // displayVec(original);

    // for(unsigned int i = 0; i<100; i++){
    //     displayVec(permutation(original)); 
    // }



    // --- Exponentielle --- 
    // float labda = 10.0f; //modifier la courbe exp
    // int nb_try = 100; 
    // float esperance = 0.; 

    // for(unsigned int i = 0; i<nb_try; i++){
    //     float res = exponentielle(labda);
    //     std::cout << res << std::endl; 
    //     esperance+= res; 
    // }
    // esperance/=nb_try; 
    // std::cout << "Esperance : " << esperance << std::endl;

    
    // -- Bêta --
    float alpha = 1.f; 
    float beta = 2.f; 

    for(unsigned int i = 0; i<100; i++){
        std::cout << loi_beta(alpha, beta) << std::endl;

    }




    return 0;
}







