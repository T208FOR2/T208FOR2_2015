#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream theinputfile;
    int tala;

    theinputfile.open("randomtolur.txt");

    theinputfile >> tala;

    cout << "The first number is: " << tala << endl;

    theinputfile.close();
    return 0;
}
