#include <iostream>
#include <fstream>

using namespace std;

const int NR = 23;

int main()
{
    ifstream theinputfile;
    int tala,i;

    theinputfile.open("randomtolur.txt");

    for (i = 0; i < NR; i++) {
        theinputfile >> tala;
    }

    cout << "The " << i << "th number is: " << tala << endl;

    theinputfile.close();
    return 0;
}
