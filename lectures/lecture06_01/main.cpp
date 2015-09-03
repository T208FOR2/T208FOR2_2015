#include <iostream>
#include <fstream>

using namespace std;

const int NR = 23;

int main()
{
    ifstream theinputfile;
    int tala,i;

    theinputfile.open("xrandomtolur.txt");  // Mac
//    theinputfile.open("c:\\Users\\eyjo\\Desktop\\randomtolur.txt"); // Windows

    for (i = 0; i < NR; i++) {
        theinputfile >> tala;
    }

    cout << "The " << i << "th number is: " << tala << endl;

    theinputfile.close();
    return 0;
}
