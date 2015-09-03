#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    ifstream theinputfile;
    int tala,maxtala = 0,mintala = 0,fjolditolur = 0;
    string thefilename;

    cout << "Please write the name of the file: ";
    cin >> thefilename;

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
