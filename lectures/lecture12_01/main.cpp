#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string THEFILENAME = "twitterfeed.txt";

int main()
{
    string currentline;
    ifstream inputfile;
    inputfile.open(THEFILENAME.c_str());

    if (inputfile.fail()) {
        cout << "Can't open " << THEFILENAME << endl;
        exit(1);
    }

    while (!inputfile.eof()) {
        getline(inputfile, currentline);
        cout << currentline << endl;
    }


    inputfile.close();

    return 0;
}
