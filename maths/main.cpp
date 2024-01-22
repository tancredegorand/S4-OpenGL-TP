// C++ program to demonstrate
// the use of rand()
#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;

void randBinaire(){
    srand(time (NULL));
    for (unsigned int i = 0; i < 50; i++){
        cout << rand() % 2 << " "; 
    }

}

int main() {
//   // This program will create some sequence of
//   // random numbers on every program run
//   srand(time(NULL));
//   for (int i = 0; i < 5; i++)
//     cout << rand() % 6 + 1 << " ";

    randBinaire(); 

    return 0;
}