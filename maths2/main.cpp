#include <iostream>
#include <random>

// Fonction générant un nombre selon une distribution de Cauchy
double cauchy(double control) {
    // Générateur de nombres aléatoires
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    // Distribution de Cauchy
    std::cauchy_distribution<double> distribution(0, control);
    
    // Génération d'un nombre aléatoire
    return distribution(gen);
}

int main() {
    // Paramètre de contrôle de la courbe
    double control = 1.0;

    // Boucle pour générer 100 nombres aléatoires selon la distribution de Cauchy
    for (int i = 0; i < 100; ++i) {
        // Génération d'un nombre aléatoire selon la distribution de Cauchy avec le paramètre de contrôle
        double random_number = cauchy(control);

        // Affichage du nombre aléatoire généré
        std::cout << random_number << std::endl;
    }

    return 0;
}
