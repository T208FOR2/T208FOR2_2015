#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string THEFILENAME = "twitterfeed.txt";

void openinputfile(ifstream& inputfile, string thefilename);

int main()
{
    string currentline;
    ifstream inputfile;
    openinputfile(inputfile, THEFILENAME);

    while (!inputfile.eof()) {
        getline(inputfile, currentline);
        cout << currentline << endl;
    }


    inputfile.close();

    return 0;
}

void openinputfile(ifstream& inputfile, string thefilename) {
    inputfile.open(thefilename.c_str());

    if (inputfile.fail()) {
        cout << "Can't open " << thefilename << endl;
        exit(1);
    }
}

