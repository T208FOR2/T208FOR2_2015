#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string THEFILENAME = "twitterfeed.txt";

int main()
{
    ofstream tmpfile;
    tmpfile.open(THEFILENAME.c_str());

    if (tmpfile.fail()) {
        cout << "WTF???" << endl;
    }
    tmpfile << "Hi!" << endl;

    tmpfile.close();
    return 0;
}
