#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void openfile(ifstream& infile, string thefilename);

int main()
{
    string str;
    char c;
    ifstream infile;

    // Method 1
    openfile(infile, "test.txt");
    while ( !infile.eof() ) {
        c = infile.get();
        cout << "\"" << c << "\"" << endl;
    }
    infile.close();

    // Method 2
    openfile(infile, "test.txt");
    while (infile >> str) {
        cout << "\"" << str << "\"" << endl;
    }
    infile.close();

    return 0;
}

void openfile(ifstream& infile, string thefilename) {
    infile.open(thefilename);
    if (infile.fail()) {
        cout << "Failure!" << endl;
        exit(1);
    }
}
