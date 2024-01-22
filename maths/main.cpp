// C++ program to demonstrate
// the use of rand()
#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;

int main() {
  // This program will create some sequence of
  // random numbers on every program run
  srand(time(NULL));
  for (int i = 0; i < 5; i++)
    cout << rand() % 6 + 1 << " ";

  return 0;
}