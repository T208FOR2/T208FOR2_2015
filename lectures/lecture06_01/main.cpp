#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    ifstream theinputfile;
    int tala, maxtala = 0, mintala = 0, fjolditolur = 0;
    string thefilename;
    bool firstnumber = true;

    cout << "Please write the name of the file: ";
//    cin >> thefilename;

//    theinputfile.open(thefilename.c_str());
    theinputfile.open("randomtolur.txt");

    if (theinputfile.fail()) {
        cout << "Can't open the file!" << endl;
        exit(1);
    }

    while (theinputfile >> tala) {
        fjolditolur++;

        if (maxtala < tala || firstnumber) {
            maxtala = tala;
        }
        if (mintala > tala || firstnumber) {
            mintala = tala;
        }
        firstnumber = false;
    }

    cout << "The largest number is " << maxtala << endl;
    cout << "The smallest number is " << mintala << endl;
    cout << "The file contains " << fjolditolur << " numbers." << endl;
    theinputfile.close();
    return 0;
}
