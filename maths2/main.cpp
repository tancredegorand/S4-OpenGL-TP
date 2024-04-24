// #include <cmath>
// #include <iostream>
// #include <random>

// static auto& generator() {
//     thread_local std::default_random_engine gen{std::random_device{}()};
//     return gen;
// }

// float alea(float min, float max) {
//     if (min > max)
//         throw std::invalid_argument{"min must be smaller than max"};

//     auto distribution = std::uniform_real_distribution<float>{min, max};
//     return distribution(generator());
// }

// float random01() {
//     return alea(0.f, 1.f);
// }

// //--

// float factoriel(float x){
//     float res = 1.; 
//      for (unsigned int i = 1; i <= x; ++i) {
//         res *= i;
//     }
//     return res;
// }


// // float gamma(float x){
// //     return factoriel(x-1);
// // }


// float loi_beta(float alpha, float beta) {
//     float x;
//     do {
//         const float random = random01();
//         x = random * (alpha + beta);
//     } while (x == 0 || x == alpha + beta); // Éviter les divisions par zéro

//     const float numerateur = std::pow(random01(), alpha - 1) * std::pow(1 - random01(), beta - 1);
//     const float denominateur = std::tgamma(alpha) * std::tgamma(beta) / std::tgamma(alpha + beta);
//     return numerateur / denominateur;
// }

// //--

// int main() {
//     const int nb_echantillons = 100;
//     const float alpha = 2.0;
//     const float beta = 5.0;

//     std::cout << "Génération de " << nb_echantillons << " échantillons de la loi beta avec alpha = " << alpha << " et beta = " << beta << std::endl;
//     std::cout << "-------------------------------------------------------" << std::endl;

//     for (int i = 0; i < nb_echantillons; ++i) {
//         float echantillon = loi_beta(alpha, beta); 
//         std::cout << echantillon << std::endl;
//     }

//     return 0;
// }



#include <cmath>
#include <iostream>
#include <random>

float random01() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dis(0.0f, 1.0f);
    return dis(gen);
}
//l'algo de Jonk
float loi_beta(float alpha, float beta) {
    float x, y;
    do {
        float u = random01();
        float v = random01();

        x = std::pow(u, 1.0f / alpha);
        y = std::pow(v, 1.0f / beta);
    } while (x + y > 1.0f); 

    float result = (2.0f * x / (x + y)) - 1.0f;
    return result;
}

int main() {
    const int nb_echantillons = 100;
    const float alpha = 0.5;
    const float beta = 0.5;

    std::cout << "Génération de " << nb_echantillons << " échantillons de la loi beta avec alpha = " << alpha << " et beta = " << beta << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    std::vector<float> echantillons;
    for (int i = 0; i < nb_echantillons; ++i) {
        float echantillon = loi_beta(alpha, beta);
        echantillons.push_back(echantillon);
    }

    // Afficher les échantillons générés
    for (int i = 0; i < nb_echantillons; ++i) {
        std::cout << echantillons[i] << std::endl;
    }

    return 0;
}
