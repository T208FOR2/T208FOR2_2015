#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    string str;
    char c;
    ifstream infile;
    infile.open("test.txt");
    if (infile.fail()) {
        cout << "Failure!" << endl;
        exit(1);
    }

    while ( !infile.eof() ) {
        c = infile.get();
        cout << ">" << c << "<" << endl;
//        cout << "\"" << c << "\"" << endl;
    }

//    while (infile >> str) {
//        cout << "\"" << str << "\"" << endl;
//    }

    infile.close();
    return 0;
}
