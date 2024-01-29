// C++ program to demonstrate
// the use of rand()
#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;

// void alea(){
//     srand(time (NULL));
//     for (unsigned int i = 0; i < 50; i++){
//         cout << rand() % 2 << " "; 
//     }

// }


int alea(){
    srand(time (NULL));
    int res = rand() % 2;
    cout << res << " "; 
    return res;
}

int main() {
    alea(); 

    return 0;
}