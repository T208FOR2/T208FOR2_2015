#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// initialize the random seed generator
void randomize(int seed);

// return an integer random number in the range 0,1,...,n-1
int randomtala(int n);

// return a random double number between 0 and 1.
double uniform_random();

int main()
{
    randomize(1443);

    cout << endl;
    for (int i = 0; i < 20; i++) {
        cout << randomtala(6) << " ";
    }
    cout << endl << endl;

    return 0;
}

void randomize(int seed)
{
    if (seed < 0)
    {
        srand(static_cast<unsigned int>(time(NULL)));
    }
    else
    {
        srand(static_cast<unsigned int>(seed));
    }
}

int randomtala(int n)
{
    return rand() % n;
}

double uniform_random()
{
    return static_cast<double>(rand()) / RAND_MAX;
}


