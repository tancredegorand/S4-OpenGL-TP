#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  

#include <random> 
#include "glm/fwd.hpp"
#include <glm/glm.hpp>



// ----- Base -----
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



// ----- other -----
template<typename T>
T displayVec(std::vector<T> vec){
     for (T num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;  
}



// ----- functions -----


template<typename T>
T uniforme(const std::vector<T>& vector) {
    if (vector.empty()) {
        throw std::invalid_argument("uniforme(vector) : Empty vector");
    }
    return vector[alea(0, vector.size())];
    
}

//--

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


//--

float exponentielle(float lambda)
{
  return (-1 / lambda) * std::log(random1());
}


//--

float gamma(float x){
    return factoriel(x-1);
}

float loi_beta(float alpha, float beta){
    const float random = random1();
    const float numerateur = std::pow(random, alpha - 1) * std::pow(1 - random, beta - 1);
    const float denominateur = (gamma(alpha) * gamma(beta)) / gamma(alpha + beta);
    return (numerateur / denominateur);
}

//--

double loi_normale(float esperance, float ecart_type)
{
    double x = sqrt(-2 * log(random1())) * cos(2 * M_PI * random1());
    double res = esperance + ecart_type * x;
    return res;
}

//--

bool bernoulli(double p){
    if(random1()<p){
        return true;
    } else {
    return false;
    }
}



    
// ---- MARKOV -----

//state 0 = eau sombre 
//state 1 = eau claire
//state 2 = eau avec pollution

glm::mat3 matriceTransition{
    {3/7, 3/7, 1/7},
    {3/10, 4/10, 2/10},
    {1/5, 1/5, 3/5}

};



void markov_setp2(int& current_state, glm::vec3 m)
{
    float a = random1();
    if (a < m[0])
    {
        current_state = 0;
    }
    else if (a < m[0] + m[1])
    {
        current_state = 1;
    }
    else if (a < m[0] + m[1] + m[2])
    {
        current_state = 2;
    }
    else
    {
        current_state = 3;
    }
}





void markov_setp1(int current_state)
{
    switch (current_state)
    {
    case 0:
        markov_setp2(current_state, matriceTransition[0]);
        break;
    case 1:
        markov_setp2(current_state, matriceTransition[1]);
        break;
    case 2:
        markov_setp2(current_state, matriceTransition[2]);
        break;
    }
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


//______

    // --- Permutation --- 
    // std::vector<int> original = {0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // displayVec(original);

    // for(unsigned int i = 0; i<100; i++){
    //     displayVec(permutation(original)); 
    // }



    // --- Exponentielle --- 
    //continue (in out)
    // float lambda = 1.0f; //modifier la courbe exp
    // int nb_try = 100; 
    // float esperance = 0.; 

    // for(unsigned int i = 0; i<nb_try; i++){
    //     float res = exponentielle(lambda);
    //     std::cout << res << std::endl; 
    //     esperance+= res; 
    // }
    // esperance/=nb_try; 
    // std::cout << "Esperance : " << esperance << std::endl;

    
    // -- Bêta --
    //continue in, alpha beta continue, continue out
    // float alpha = 5.f; 
    // float beta = 1.f; 
    // float esperance = 0.; 
    // int nb_try = 100;

    // for(unsigned int i = 0; i< nb_try; i++){
    //     float res =  loi_beta(alpha, beta); 
    //     std::cout << res << std::endl;
    //     esperance+= res;
    // }

    // esperance/=nb_try; 
    // std::cout << "Esperance : " << esperance << std::endl;

    // // -- Loi normal - méthode box-Muller --
    // centrée ->(en 0), réduite->(hauteur de la cloche)
    // continue in out
    // float esperance  = 3;
    // float ecart_type = 2;
    // int nb_try = 100;
    // for(unsigned int i = 0; i< nb_try; i++){
    //     std::cout << loi_normale(esperance, ecart_type) << std::endl;
    // }


    // --Bernoulli--
    //continue in -> bool out
    // int nb_try = 100;
    // double p = 0.8f;        //(win)
    //  for(unsigned int i = 0; i< nb_try; i++){
    //     std::cout << bernoulli(p) << std::endl;
    // }







    return 0;
}





