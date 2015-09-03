#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int NR = 23;

bool somefunction(int tala) {
    return (tala % 2 == 0);
}

int main()
{
    if ( somefunction(17) ) {
        cout << "17 is even";
    }
    else {
        cout << "17 is odd";
    }
    ifstream theinputfile;
    int tala,i;

    theinputfile.open("xrandomtolur.txt");  // Mac
//    theinputfile.open("c:\\Users\\eyjo\\Desktop\\randomtolur.txt"); // Windows
    if (theinputfile.fail()) {
        cout << "Can't open the file!" << endl;
        exit(1);
    }

    for (i = 0; i < NR; i++) {
        theinputfile >> tala;
    }

    cout << "The " << i << "th number is: " << tala << endl;

    theinputfile.close();
    return 0;
}
