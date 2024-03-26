#include <cmath>
#include <cstddef>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

float random_float(int n) {
  srand(time(NULL));
  float sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += (rand() % 2) / pow(2, i);
  }
  return sum;
}

double rand01() {
    thread_local std::default_random_engine gen{std::random_device{}()};
    thread_local auto distrib = std::uniform_real_distribution<double>{0.0, 1.0};

    return distrib(gen);
}

float my_rand01()
{
  float randomNumber = (float)rand() / (float)RAND_MAX;
  return randomNumber;
}

float loi_exp(float lambda)
{
  return (-1 / lambda) * std::log(my_rand01());
}

int main()
{
  float moyenne = 0;
  float moyenne_carre = 0;
  float tmp = 0;
  const int nb_essais = 1000;
  std::vector<float> results;
  srand(static_cast<unsigned int>(time(NULL))); // Initialize random seed
  for(size_t i = 0 ; i < nb_essais ; i++)
  {
    tmp = loi_exp(10.f);
    results.push_back(tmp);
    moyenne += tmp;
    moyenne_carre += tmp * tmp;
    std::cout << tmp << "\n";
  }
  moyenne /= nb_essais;
  moyenne_carre /= nb_essais;

  float variance = 0;
  for(auto e : results)
  {
    variance += (e - moyenne) * (e - moyenne);
  }
  variance /= nb_essais;
  std:: cout << "Esperance : " << moyenne << "\n";
  std:: cout << "Variance : " << variance << "\n";
}
