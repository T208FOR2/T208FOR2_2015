#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    string str;
    ifstream infile;
    infile.open("test.txt");
    if (infile.fail()) {
        cout << "Failure!" << endl;
        exit(1);
    }

    while (infile >> str) {
        cout << "\"" << str << "\"" << endl;
    }

    infile.close();
    return 0;
}
